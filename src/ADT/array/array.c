/* File: array.c */

/*  NIM                 : 18221067
    Nama                : Fawwaz Abrial Saffa
    Tanggal             : 25 September 2022
    Topik praktikum     : Prapraktikum #04 - Array dan ADT List
    Deskripsi           : Realisasi dari array.h
*/

#include "array.h"
#include <stdio.h>

/* Indeks yang digunakan [IdxMin..IdxMax] */
/* Jika T adalah TabInt, cara deklarasi dan akses: */
/* Deklarasi : T : TabInt */
/* Maka cara akses:
 * T.Neff untuk mengetahui banyaknya elemen
 * T.TI untuk mengakses seluruh nilai elemen tabel
 * T.TI[i] untuk mengakses elemen ke-i */
/* Definisi :
 * Tabel kosong: T.Neff = 0
 * Definisi elemen pertama : T.TI[i] dengan i=1
 * Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.Neff */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmpty (TabWord *T) {
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */

    // KAMUS LOKAL

    // ALGORITMA
    T->Neff = 0;
}


/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabWord T) {
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */

    // KAMUS LOKAL

    // ALGORITMA
    return (T.Neff);
}

/* *** Daya tampung container *** */
int MaxNbEl (TabWord T) {
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */

    // KAMUS LOKAL

    // ALGORITMA
    return (IdxMax - IdxMin + 1);
}
/* *** Selektor INDEKS *** */
IdxTypeArray GetFirstIdx (TabWord T) {
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */

    // KAMUS LOKAL

    // ALGORITMA
    return (IdxMin);
}

IdxTypeArray GetLastIdx (TabWord T) {
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */

    // KAMUS LOKAL

    // ALGORITMA
    return (NbElmt(T));
}

/* *** Menghasilkan sebuah elemen *** */
ElTypeArray GetElmt (TabWord T, IdxTypeArray i) {
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */

    // KAMUS LOKAL

    // ALGORITMA
    return (T.TI[i]);
}

int GetElmtIdx (TabWord T, Word elmt) {
    /* Prekondisi: bebas
       Mengirimkan indeks elemen tabel pertama yang berisi sama dengan elmt.
       Mengirimkan IdxUndef (-999) jika tidak ditemukan (hilang coy) */
    for (int i=1;i<=T.Neff;i++) {
        if (isKataEqual(T.TI[i],elmt)) {return i;}
    }
    return IdxUndef;
}

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetTab (TabWord Tin, TabWord *Tout) {
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Assignment THsl -> Tin */

    // KAMUS LOKAL
    IdxTypeArray i;

    // ALGORITMA
    MakeEmpty(Tout);
    (*Tout).Neff = NbElmt(Tin);
    for (i = GetFirstIdx(Tin); i <= GetLastIdx(Tin); i++) {
        (*Tout).TI[i] = GetElmt(Tin, i);
    }
    
}

void SetEl (TabWord *T, IdxTypeArray i, ElTypeArray v) {
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */

    // KAMUS LOKAL

    // ALGORITMA
    (*T).TI[i] = v;
    // (*T).TI[i] = v;
    if (i > GetLastIdx(*T)) (*T).Neff++;
}

void SetNeff (TabWord *T, IdxTypeArray N) {
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */

    // KAMUS LOKAL

    // ALGORITMA
    (*T).Neff = N;
}


/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabWord T, IdxTypeArray i) {
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/

    // KAMUS LOKAL

    // ALGORITMA
    return (i >= GetFirstIdx(T) && i <= MaxNbEl(T));
}

boolean IsIdxEff (TabWord T, IdxTypeArray i) {
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

    // KAMUS LOKAL

    // ALGORITMA
    return (i >= GetFirstIdx(T) && i <= GetLastIdx(T));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabWord T) {
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */

    // KAMUS LOKAL

    // ALGORITMA
    return (NbElmt(T) == 0);
}

/* *** Test tabel penuh *** */
boolean IsFull (TabWord T) {
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

    // KAMUS LOKAL

    // ALGORITMA
    return (NbElmt(T) == IdxMax);
}


/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void DisplayArray (TabWord T) {
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/* Jika isi tabel ["HALO", "SAYA", "GAME"] maka akan diprint
1. HALO
2. SAYA
3. GAME
*/
/* Jika T kosong : Hanya menulis "Tabel kosong" */

    // KAMUS LOKAL
    IdxTypeArray i;

    // ALGORITMA
    if (IsEmpty(T)) printf("Tabel kosong\n");
    else {
        for (i=IdxMin; i<=GetLastIdx(T); i++) {
            printf("%d. ", i);
            displayWord(GetElmt(T, i), true);
        }
    }
}

void InsertLast (TabWord *T, ElTypeArray X) {
/* Memasukkan elemen ke akhir array */
/* I.S. T terdefinisi */
/* F.S. Apabila tidak penuh, T bertambah satu elemen di akhir */
    // KAMUS LOKAL
    int idxLast;

    // ALGORITMA
    if (IsEmpty(*T)) {
        T->TI[IdxMin] = X;
    } else {
        idxLast = GetLastIdx(*T);
        T->TI[idxLast + 1] = X;
        T->Neff++;
    }
}

void DeleteAt (TabWord *T, int id) {
/* Menghapus elemen pada Array yang menempati indeks id
   I.S. : T terdefinisi, tidak kosong
   F.S. : Elemen ke-id di array dihapuskan */
    // KAMUS LOKAL

    // ALGORITMA
    for (int i=id;i<T->Neff;i++) {
        T->TI[i] = T->TI[i+1];
    }
    T->Neff--;
}
