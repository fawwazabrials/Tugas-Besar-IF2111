/* File : StackHanoi.h */
/* deklarasi StackHanoi yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef STACK_HANOI_H
#define STACK_HANOI_H

#include "boolean.h"
#include "mesinkata.h"

#define MaxElStackHanoi 100
/* Nil adalah StackHanoi dengan elemen kosong . */

typedef int infotypeStackHanoi;
typedef int addressStackHanoi;   /* indeks tabel */

/* Contoh deklarasi variabel bertype StackHanoi dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct { 
  infotypeStackHanoi T[MaxElStackHanoi]; /* tabel penyimpan elemen */
  addressStackHanoi TOP;  /* alamat TOP: indeks puncak */
} StackHanoi;
/* Definisi StackHanoi S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai StackHanoi T[0]..T[MaxElStackHanoi-1] */
/* Jika S adalah StackHanoi maka akses elemen : */
   /* S.T[(S.TOP)] untuk mengakses elemen TOP */
   /* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).TOP /*indeks puncak*/
#define InfoTop(S) (S).T[(S).TOP] /*nilai puncak*/

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyS(StackHanoi *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah StackHanoi S yang kosong berkapasitas MaxElStackHanoi */
/* jadi indeksnya antara 0.. MaxElStackHanoi */
/* Ciri StackHanoi kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyS(StackHanoi S);
/* Mengirim true jika StackHanoi kosong: lihat definisi di atas */

boolean IsFullS(StackHanoi S);

/* ************ Menambahkan sebuah elemen ke StackHanoi ************ */
void PushS(StackHanoi * S, infotypeStackHanoi X);
/* Menambahkan X sebagai elemen StackHanoi S. */
/* I.S. S mungkin kosong, tabel penampung elemen StackHanoi TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen StackHanoi ************ */
void PopS(StackHanoi * S, infotypeStackHanoi* X);
/* Menghapus X dari StackHanoi S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

int getTop(StackHanoi S) ;

boolean isStackEqual(StackHanoi a, StackHanoi b);

#endif
