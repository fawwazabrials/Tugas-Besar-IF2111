/* File : listlinier.c */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi addressLL dengan pointer */
/* infotypeLL adalah integer */

#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsListLEmpty (List L) {
/* Mengirim true jika list kosong */
    return (First(L) == NilLL);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyListL (List *L) {
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
    First(*L) = NilLL;
}

/****************** Manajemen Memori ******************/
addressLL Alokasi (infotypeLL X, infotypeLL Y) {
/* Mengirimkan addressLL hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressLL tidak NilLL, dan misalnya */
/* menghasilkan P, maka Absis(P) = X, Ordinat(P) = Y Next(P)=NilLL */
/* Jika alokasi gagal, mengirimkan NilLL */
    addressLL P = (addressLL) malloc (sizeof(ElmtList));
    if (P != NilLL) {
        Absis(Info(P)) = X;
        Ordinat(Info(P)) = Y;
        Next(P) = NilLL;
    }
    return P;
}

void Dealokasi (addressLL *P) {
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressLL P */
    free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressLL Search (List L, infotypeLL X, infotypeLL Y){
/* Mencari apakah ada elemen list dengan Absis(P) = X dan Ordinat(P) = Y */
/* Jika ada, mengirimkan addressLL elemen tersebut. */
/* Jika tidak ada, mengirimkan NilLL */
    addressLL P = First(L);
    boolean found = false;
    while (P!= NilLL && ! found) {
        if (Absis(Info(P)) == X && Ordinat(Info(P)) == Y) {
            found = true;
        } else {
            P = Next(P);
        }
    }
    if (found) {
        return P;
    } else {
        return NilLL;
    }
    
}

int indexOf(List L, infotypeLL X, infotypeLL Y) {
/* Mencari indeks keberapa sebuah elemen dengan absis X dan ordinat Y pada list 
   Jika elemen tidak ada di dalam list, maka akan mengembalikan nilai -9999 */
    // KAMUS LOKAL
    addressLL P;
    boolean found;
    int idx;

    // ALGORITMA
    P = First(L);
    idx = 0;
    found = false;
    while (P!= NilLL && ! found) {
        if (Absis(Info(P)) == X && Ordinat(Info(P)) == Y) {
            found = true;
        } else {
            P = Next(P); idx++;
        }
    }

    if (found) {
        return idx;
    } else {
        return -9999;
    }

}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotypeLL X, infotypeLL Y){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
    addressLL P = Alokasi(X, Y);
    InsertFirstListL(L, P);
}

void InsVLast (List *L, infotypeLL X, infotypeLL Y){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    addressLL P = Alokasi(X, Y);
    InsertLastListL(L, P);
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotypeLL *X, infotypeLL *Y){
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
    addressLL P;
    DelFirstListL(L, &P);
    *X = Absis(Info(P));
    *Y = Ordinat(Info(P));
    Dealokasi(&P);
}

void DelVLast (List *L, infotypeLL *X, infotypeLL *Y){
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
    addressLL P;
    DelLastListL(L, &P);
    *X = Absis(Info(P));
    *Y = Ordinat(Info(P));
    Dealokasi(&P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstListL (List *L, addressLL P){
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addressLL P sebagai elemen pertama */
    Next(P) = First(*L);
    First(*L) = P;
}

void InsertAfterListL (List *L, addressLL P, addressLL Prec){
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLastListL (List *L, addressLL P){ 
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
    if (IsListLEmpty(*L)) {
        First(*L) = P;
        Next(P) = NilLL;  // Penandaan Elemen Terakhir
    } else {
        addressLL last = First(*L);
        while (Next(last) != NilLL) {
            last = Next(last);
        }
        Next(last) = P;
        Next(P) = NilLL;
    }
}


/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstListL (List *L, addressLL *P){ 
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
    *P = First(*L);
    if (Next(*P) == NilLL) {
        CreateEmptyListL(L);
    } else {
        First(*L) = Next(*P);
    }

}

void DelP (List *L, infotypeLL X, infotypeLL Y){ 
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
    addressLL P = Search(*L, X, Y);
    if (P != NilLL) {
        addressLL Prec = First(*L);       // Prec = Loc di ppt
        if (Prec == P) {
            DelFirstListL(L, &P);
        } else {
            while (Next(Prec) != P) {
                Prec = Next(Prec);
            }
            DelAfterListL(L, &P, Prec);
        }
    }

    Dealokasi(&P);
}

void DelLastListL (List *L, addressLL *P){ 
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
    if (Next(First(*L)) == NilLL) {
        *P = First(*L);
        CreateEmptyListL(L);
    } else {
        addressLL Prec = First(*L);
        while (Next(Next(Prec)) != NilLL) {
            Prec = Next(Prec);
        }
        DelAfterListL(L, P, Prec);
    }
}

void DelAfterListL (List *L, addressLL *Pdel, addressLL Prec) { 
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
    *Pdel = Next(Prec);
    if (Pdel != NilLL) {
        addressLL P = Next(Prec);
        Next(Prec) = Next(P);
    }

}
/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfoListL (List L){ 
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    if (! IsListLEmpty(L)) {
        addressLL P = First(L);
        do {
            printf("(%d,%d)", Absis(Info(P)), Ordinat(Info(P)));
            P = Next(P);
            if (P != NilLL) {
                printf(",");
            }
        } while (P != NilLL);
    }
}

int NbElmtListL (List L){ 
/* Mengirimkan banyaknya elemen list{ } mengirimkan 0 jika list kosong */
    int ctr = 0;
    addressLL P = First(L);
    if (! IsListLEmpty(L)) {
        while (P != NilLL) {
            ctr++;
            P = Next(P);
        }
    }
    return ctr;

}