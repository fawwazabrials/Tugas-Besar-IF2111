/* File : listlinier.c */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* infotype adalah integer */

#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsListLEmpty (List L) {
/* Mengirim true jika list kosong */
    return (First(L) == Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyListL (List *L) {
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
    First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X, infotype Y) {
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Absis(P) = X, Ordinat(P) = Y Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
    address P = (address) malloc (sizeof(ElmtList));
    if (P != Nil) {
        Absis(Info(P)) = X;
        Ordinat(Info(P)) = Y;
        Next(P) = Nil;
    }
    return P;
}

void Dealokasi (address *P) {
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
    free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X, infotype Y){
/* Mencari apakah ada elemen list dengan Absis(P) = X dan Ordinat(P) = Y */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
    address P = First(L);
    boolean found = false;
    while (P!= Nil && ! found) {
        if (Absis(Info(P)) == X && Ordinat(Info(P)) == Y) {
            found = true;
        } else {
            P = Next(P);
        }
    }
    if (found) {
        return P;
    } else {
        return Nil;
    }
    
}

int indexOf(List L, infotype X, infotype Y) {
/* Mencari indeks keberapa sebuah elemen dengan absis X dan ordinat Y pada list 
   Jika elemen tidak ada di dalam list, maka akan mengembalikan nilai -9999 */
    // KAMUS LOKAL
    address P;
    boolean found;
    int idx;

    // ALGORITMA
    P = First(L);
    idx = 0;
    found = false;
    while (P!= Nil && ! found) {
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
void InsVFirst (List *L, infotype X, infotype Y){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
    address P = Alokasi(X, Y);
    InsertFirst(L, P);
}

void InsVLast (List *L, infotype X, infotype Y){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    address P = Alokasi(X, Y);
    InsertLast(L, P);
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X, infotype *Y){
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
    address P;
    DelFirst(L, &P);
    *X = Absis(Info(P));
    *Y = Ordinat(Info(P));
    Dealokasi(&P);
}

void DelVLast (List *L, infotype *X, infotype *Y){
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
    address P;
    DelLast(L, &P);
    *X = Absis(Info(P));
    *Y = Ordinat(Info(P));
    Dealokasi(&P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstListL (List *L, address P){
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
    Next(P) = First(*L);
    First(*L) = P;
}

void InsertAfterListL (List *L, address P, address Prec){
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLastListL (List *L, address P){ 
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
    if (IsListLEmpty(*L)) {
        First(*L) = P;
        Next(P) = Nil;  // Penandaan Elemen Terakhir
    } else {
        address last = First(*L);
        while (Next(last) != Nil) {
            last = Next(last);
        }
        Next(last) = P;
        Next(P) = Nil;
    }
}


/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstListL (List *L, address *P){ 
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
    *P = First(*L);
    if (Next(*P) == Nil) {
        CreateEmptyListL(L);
    } else {
        First(*L) = Next(*P);
    }

}

void DelP (List *L, infotype X, infotype Y){ 
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
    address P = Search(*L, X, Y);
    if (P != Nil) {
        address Prec = First(*L);       // Prec = Loc di ppt
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

void DelLastListL (List *L, address *P){ 
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
    if (Next(*P) == Nil) {
        *P = First(*L);
        CreateEmptyListL(L);
    } else {
        address Prec = First(*L);
        while (Next(Next(Prec)) != Nil) {
            Prec = Next(Prec);
        }
        DelAfterListL(L, P, Prec);
    }
}

void DelAfterListL (List *L, address *Pdel, address Prec) { 
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
    *Pdel = Next(Prec);
    if (Pdel != Nil) {
        address P = Next(Prec);
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
        address P = First(L);
        do {
            printf("(%d,%d)", Absis(Info(P)), Ordinat(Info(P)));
            P = Next(P);
            if (P != Nil) {
                printf(",");
            }
        } while (P != Nil);
    }
}

int NbElmtListL (List L){ 
/* Mengirimkan banyaknya elemen list{ } mengirimkan 0 jika list kosong */
    int ctr = 0;
    address P = First(L);
    if (! IsListLEmpty(L)) {
        while (P != Nil) {
            ctr++;
            P = Next(P);
        }
    }
    return ctr;

}