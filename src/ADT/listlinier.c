/* File : listlinier.c */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* infotype adalah integer */

#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

// typedef int infotype;
// typedef struct tElmtlist *address;
// typedef struct tElmtlist { 
// 	infotype info;
// 	address next;
// } ElmtList;
// typedef struct {
// 	address First;
// } List;

// /* Definisi list : */
// /* List kosong : First(L) = Nil */
// /* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
// /* Elemen terakhir list : jika addressnya Last, maka Next(Last)=Nil */
// #define Info(P) (P)->info
// #define Next(P) (P)->next
// #define First(L) ((L).First)

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L) {
/* Mengirim true jika list kosong */
    return (First(L) == Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L) {
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
    First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X) {
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
    address P = (address) malloc (sizeof(ElmtList));
    if (P != Nil) {
        Info(P) = X;
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
address Search (List L, infotype X){
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
    address P = First(L);
    boolean found = false;
    while (P!= Nil && ! found) {
        if (Info(P) == X) {
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

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
    address P = Alokasi(X);
    InsertFirst(L, P);
}

void InsVLast (List *L, infotype X){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    address P = Alokasi(X);
    InsertLast(L, P);
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X){
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
    address P;
    DelFirst(L, &P);
    *X = Info(P);
    Dealokasi(&P);
}

void DelVLast (List *L, infotype *X){
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
    address P;
    DelLast(L, &P);
    *X = Info(P);
    Dealokasi(&P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P){
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
    Next(P) = First(*L);
    First(*L) = P;
}

void InsertAfter (List *L, address P, address Prec){
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLast (List *L, address P){ 
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
    if (IsEmpty(*L)) {
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
void DelFirst (List *L, address *P){ 
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
    *P = First(*L);
    if (Next(*P) == Nil) {
        CreateEmpty(L);
    } else {
        First(*L) = Next(*P);
    }

}

void DelP (List *L, infotype X){ 
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
    address P = Search(*L, X);
    if (P != Nil) {
        address Prec = First(*L);       // Prec = Loc di ppt
        if (Prec == P) {
            DelFirst(L, &P);
        } else {
            while (Next(Prec) != P) {
                Prec = Next(Prec);
            }
            DelAfter(L, &P, Prec);
        }
    }

    Dealokasi(&P);
}

void DelLast (List *L, address *P){ 
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
    if (Next(*P) == Nil) {
        *P = First(*L);
        CreateEmpty(L);
    } else {
        address Prec = First(*L);
        while (Next(Next(Prec)) != Nil) {
            Prec = Next(Prec);
        }
        DelAfter(L, P, Prec);
    }
}

void DelAfter (List *L, address *Pdel, address Prec) { 
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
void PrintInfo (List L){ 
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    printf("[");
    if (! IsEmpty(L)) {
        address P = First(L);
        printf("%d", Info(P));
        P = Next(P);
        while (P != Nil) {
            printf(",%d", Info(P));
            P = Next(P);
        }
    }
    printf("]");

}

int NbElmt (List L){ 
/* Mengirimkan banyaknya elemen list{ } mengirimkan 0 jika list kosong */
    int ctr = 0;
    address P = First(L);
    if (! IsEmpty(L)) {
        while (P != Nil) {
            ctr++;
            P = Next(P);
        }
    }
    return ctr;

}

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L){ 
/* Mengirimkan nilai info(P) yang maksimum */
    address P = First(L);
    int maximum = Info(P);
    while (P != Nil) {
        if (Info(P) > maximum) {
            maximum = Info(P);
        }
        P = Next(P);
    }
    return maximum;
}

address AdrMax (List L){ 
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
    address P = First(L);
    while (P != Nil) {
        if (Info(P) == Max(L)) {
            return P;
        } else {
            P = Next(P);
        }
    }
    return Nil;
}

infotype Min (List L){ 
/* Mengirimkan nilai info(P) yang minimum */
    address P = First(L);
    int minimum = Info(P);
    while (P != Nil) {
        if (Info(P) < minimum) {
            minimum = Info(P);
        }
        P = Next(P);
    }
    return minimum;
}

address AdrMin (List L){ 
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
    address P = First(L);
    while (P != Nil) {
        if (Info(P) == Min(L)) {
            return P;
        } else {
            P = Next(P);
        }
    }
    return Nil;
}

float Average (List L){ 
/* Mengirimkan nilai rata-rata info(P) */
    float sum = 0;
    address P = First(L);
    while (P != Nil) {
        sum = sum + Info(P);
        P = Next(P);
    }
    return sum / (float) NbElmt(L);

}

/****************** PROSES TERHADAP LIST ******************/

void InversList (List *L){ 
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
    address Prev = Nil;
    address Current = First(*L);
    address After = First(*L);
    while (Current != Nil) {
        After = Next(Current);
        Next(Current) = Prev;
        Prev = Current;
        Current = After;
    }
    First(*L) = Prev;
}


void Konkat1 (List *L1, List *L2, List *L3){ 
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
    CreateEmpty(L3);
    if (! IsEmpty(*L1)) {
        address P = First(*L1);
        First(*L3) = P;
        while (Next(P) != Nil) {
            P = Next(P);
        }
        Next(P) = First(*L2);
    } else {
        First(*L3) = First(*L2);
    }
    CreateEmpty(L1);
    CreateEmpty(L2);
}