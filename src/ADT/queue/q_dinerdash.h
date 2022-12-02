/* File : q_dinerdash.h */
/* Definisi ADT Queue_DD dengan representasi array secara eksplisit dan alokasi statik */

#ifndef Q_DINERDASH_H
#define Q_DINERDASH_H

#include "boolean/boolean.h"

#define IDX_UNDEF -1
#define CAPACITY_QUEUE_DD 20

/* Definisi elemen dan address */
typedef struct {
    char* makanan;
    int durasi;
    int ketahanan;
    int harga;
} Food;

typedef Food ElTypeQDD;

typedef struct {
	ElTypeQDD buffer[CAPACITY_QUEUE_DD]; 
	int idxHeadQDD;
	int idxTailQDD;
} Queue_DD;

/* ********* AKSES (Selektor) ********* */
/* Jika q adalah Queue_DD, maka akses elemen : */
#define IDX_HEAD_DD(q) (q).idxHeadQDD
#define IDX_TAIL_DD(q) (q).idxTailQDD
#define     HEAD_DD(q) (q).buffer[(q).idxHeadQDD]
#define     TAIL_DD(q) (q).buffer[(q).idxTailQDD]

/* *** Kreator *** */
void CreateQueueDD(Queue_DD *q);
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean isEmptyDD(Queue_DD q);
/* Mengirim true jika q kosong: lihat definisi di atas */
boolean isFullDD(Queue_DD q);
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL_DD akan selalu di belakang IDX_HEAD_DD dalam buffer melingkar*/

int lengthDD(Queue_DD q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueueDD(Queue_DD *q, ElTypeQDD val);
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL_DD yang baru, IDX_TAIL_DD "mundur" dalam buffer melingkar. */

void dequeueDD(Queue_DD *q, ElTypeQDD *val);
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD_DD pd I.S., IDX_HEAD_DD "mundur";
        q mungkin kosong */

void ForceDeleteAt(Queue_DD *q, int i);
/* Menghapus elemen array secara paksa (bukan dequeueDD) */
/* I.S. Queue_DD terdefinisi dan tidak kosong */
/* F.S. Elemen Queue_DD ke-i terhapus */

/* *** Display Queue_DD *** */
void displayQueueFood(Queue_DD q);
/* Proses : Menuliskan isi Queue_DD dengan traversal */
/* I.S. q boleh kosong */
/* F.S. Jika q kosong akan dicetak: */
/*
Makanan | Durasi memasak | Ketahanan | Harga      
---------------------------------------------     
        |                |           | 
*/
/* Contoh : jika ada tiga elemen Food akan dicetak: */
/*
Makanan | Durasi memasak | Ketahanan | Harga      
---------------------------------------------  
M0      | 2              | 3         | 15000
M1      | 3              | 1         | 15000
M2      | 1              | 4         | 15000

*/

void displayQueueRTS(Queue_DD q);
/* Proses : Menuliskan isi Queue_DD dengan traversal */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong dan memiliki 1 elemen */
/*
Makanan | Sisa ketahanan makanan
---------------------------------
M2      | 4
*/
/* Jika Queue_DD kosong : akan dicetak */
/*
Makanan | Sisa ketahanan makanan
---------------------------------
*/

void displayQueueCooked(Queue_DD q);
/* Proses : Menuliskan isi Queue_DD dengan traversal */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada dua makanan yang sedang dimasak */
/*
Makanan | Sisa durasi memasak
-----------------------------
M0      | 1
M1      | 3

*/
/* Jika Queue_DD kosong */
/*
Makanan | Sisa durasi memasak
-----------------------------
*/

#endif