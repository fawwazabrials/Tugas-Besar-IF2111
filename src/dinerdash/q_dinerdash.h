/* File : q_dinerdash.h */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi statik */

#ifndef Q_DINERDASH_H
#define Q_DINERDASH_H

#include "boolean.h"

#define IDX_UNDEF -1
#define CAPACITY 20

/* Definisi elemen dan address */
typedef struct {
    char* makanan;
    int durasi;
    int ketahanan;
    int harga;
} Food;

typedef Food ElType;

typedef struct {
	ElType buffer[CAPACITY]; 
	int idxHead;
	int idxTail;
} Queue;

/* ********* AKSES (Selektor) ********* */
/* Jika q adalah Queue, maka akses elemen : */
#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define     HEAD(q) (q).buffer[(q).idxHead]
#define     TAIL(q) (q).buffer[(q).idxTail]

/* *** Kreator *** */
void CreateQueue(Queue *q);
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean isEmpty(Queue q);
/* Mengirim true jika q kosong: lihat definisi di atas */
boolean isFull(Queue q);
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/

int length(Queue q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, ElType val);
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

void dequeue(Queue *q, ElType *val);
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */

void ForceDeleteAt(Queue *q, int i);
/* Menghapus elemen array secara paksa (bukan dequeue) */
/* I.S. Queue  terdefinisi dan tidak kosong */
/* F.S. Elemen Queue ke-i terhapus */

/* *** Display Queue *** */
void displayQueueFood(Queue q);
/* Proses : Menuliskan isi Queue dengan traversal */
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

void displayQueueRTS(Queue q);
/* Proses : Menuliskan isi Queue dengan traversal */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong dan memiliki 1 elemen */
/*
Makanan | Sisa ketahanan makanan
---------------------------------
M2      | 4
*/
/* Jika Queue kosong : akan dicetak */
/*
Makanan | Sisa ketahanan makanan
---------------------------------
*/

void displayQueueCooked(Queue q);
/* Proses : Menuliskan isi Queue dengan traversal */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada dua makanan yang sedang dimasak */
/*
Makanan | Sisa durasi memasak
-----------------------------
M0      | 1
M1      | 3

*/
/* Jika Queue kosong */
/*
Makanan | Sisa durasi memasak
-----------------------------
*/

#endif