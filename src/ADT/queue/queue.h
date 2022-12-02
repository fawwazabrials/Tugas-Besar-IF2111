/* File : queue.h */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi statik */

#ifndef QUEUE_H
#define QUEUE_H

#include "../boolean/boolean.h"
#include "../mesinkata/mesinkata.h"
#include "../functions.h"

#define IDX_UNDEF -1
#define CAPACITY_QUEUE 100

/* Definisi elemen dan address */
typedef Word ElTypeQueue;
typedef struct {
	ElTypeQueue buffer[CAPACITY_QUEUE]; 
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

boolean isInQueue(Queue q, Word w);
// Mengirimkan apakah Word w terdapat di dalam queue

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, ElTypeQueue val);
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

void dequeue(Queue *q, ElTypeQueue *val);
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */

/* *** Display Queue *** */
void DisplayQueue(Queue q);
/* Proses : Menuliskan isi queue dengan traversal */
/* I.S. q Tboleh kosong */
/* F.S. Jika q tidak kosong : elemen queue ditulis berderet ke bawah */
/* Jika isi tabel ["HALO", "SAYA", "GAME"] maka akan diprint
1. HALO
2. SAYA
3. GAME
*/
/* Jika T kosong : Hanya menulis "Tabel kosong" */


#endif
