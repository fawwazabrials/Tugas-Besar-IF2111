/* File : stack.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef stackt_H
#define stackt_H

#include "boolean.h"
#include "mesinkata.h"

#define MaxElStackHanoi 100
/* Nil adalah stack dengan elemen kosong . */

typedef int infotype;
typedef int addressStackHanoi;   /* indeks tabel */

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct { 
  infotype T[MaxElStackHanoi]; /* tabel penyimpan elemen */
  addressStackHanoi TOP;  /* alamat TOP: indeks puncak */
} Stack;
/* Definisi stack S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai Stack T[0]..T[MaxElStackHanoi-1] */
/* Jika S adalah Stack maka akses elemen : */
   /* S.T[(S.TOP)] untuk mengakses elemen TOP */
   /* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).TOP /*indeks puncak*/
#define InfoTop(S) (S).T[(S).TOP] /*nilai puncak*/

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyS(Stack *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxElStackHanoi */
/* jadi indeksnya antara 0.. MaxElStackHanoi */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyS(Stack S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */

boolean IsFullS(Stack S);

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushS(Stack * S, infotype X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void PopS(Stack * S, infotype* X);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

int getTop(Stack S) ;

boolean isStackEqual(Stack a, Stack b);

#endif
