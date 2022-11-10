#include "queue.h"

/* *** Kreator *** */
void CreateQueue(Queue *q) {
    // KAMUS LOKAL

    // AGLORITMA
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean isEmpty(Queue q) {
    // KAMUS LOKAL

    // AGLORITMA
    return ((IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF));
}
/* Mengirim true jika q kosong: lihat definisi di atas */
boolean isFull(Queue q) {
    // KAMUS LOKAL

    // AGLORITMA
    return (length(q) == CAPACITY_QUEUE);
}
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/

int length(Queue q) {
    // KAMUS LOKAL

    // AGLORITMA
    if (isEmpty(q)) return 0;
    else if(IDX_TAIL(q) >= IDX_HEAD(q)) return IDX_TAIL(q) - IDX_HEAD(q) +1;
    else return IDX_TAIL(q) + 1 + (CAPACITY_QUEUE - IDX_HEAD(q));
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

boolean isInQueue(Queue q, Word w) {
    boolean r = false;
    int i,j=IDX_HEAD(q);
    for (i=0;i<length(q);i++) {
        if (isKataEqual(q.buffer[j],w)) {r=true;}
        j = (j+1) % CAPACITY_QUEUE;
    }
    return r;
}

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, ElTypeQueue val) {
    // KAMUS LOKAL

    // AGLORITMA
    if (isEmpty(*q)) {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;  
    } else {
        IDX_TAIL(*q) = (IDX_TAIL(*q) + 1) % CAPACITY_QUEUE;
    }

    // copyWord(val, &TAIL(*q));
    TAIL(*q) = val;
}
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

void dequeue(Queue *q, ElTypeQueue *val) {
    // KAMUS LOKAL

    // AGLORITMA
    *val = HEAD(*q);

    if (length(*q) == 1) {
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;  
    } else {
        IDX_HEAD(*q) = (IDX_HEAD(*q) + 1) % CAPACITY_QUEUE;
    }
}
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */

/* *** Display Queue *** */
void DisplayQueue(Queue q) {
    // KAMUS LOKAL
    int i, val;

    // AGLORITMA

    for (i = 0; i<length(q); i++) {
        printf("%d. ", i+1);
        displayWord(q.buffer[i]);
    }
}
