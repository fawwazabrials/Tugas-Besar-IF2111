#include <stdio.h>
#include "cooked.h"

/* *** Kreator *** */
void CreateQueueCooked(QueueCooked *q) {
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

/* ********* Prototype ********* */
boolean isEmptyCooked(QueueCooked q) {
/* Mengirim true jika q kosong: lihat definisi di atas */
    return (IDX_HEAD(q) == IDX_UNDEF && IDX_TAIL(q) == IDX_UNDEF);
}
boolean isFullCooked(QueueCooked q) {
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/
    return (IDX_HEAD(q) == 0 && IDX_TAIL(q) == CAPACITY_COOKED-1);
}

int length(QueueCooked q) {
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
    if (isEmptyCooked(q)) {
        return 0;
    } else {
        return (IDX_TAIL(q) - IDX_HEAD(q)) + 1;;
    }
}

/* *** Primitif Add/Delete *** */
void enqueueCooked(QueueCooked *q, Cooked val) {
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */
    if (isEmptyCooked(*q)) {
        (*q).idxHead = 0;
        (*q).idxTail = 0;
    } else { // *q is not empty
        if (IDX_TAIL(*q) == CAPACITY_COOKED - 1) { // elemen mentok kanan, geser dulu
            for (int i=(*q).idxHead = 0; i <= (*q).idxTail; i++) {
                (*q).buffer[i-(*q).idxHead] = (*q).buffer[i];
            }
            (*q).idxTail -= (*q).idxHead;
            (*q).idxHead = 0;
        }
        (*q).idxTail = (*q).idxTail + 1;
    }
    (*q).buffer[(*q).idxTail] = val;
}

void dequeueCooked(QueueCooked *q, Cooked *val) {
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */
    *val = HEAD(*q);
    if (IDX_HEAD(*q) == IDX_TAIL(*q)) {
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    } else {
        IDX_HEAD(*q)++;
    }
}

/* *** Display Queue *** */
void displayQueueCooked(QueueCooked q) {
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
        |
*/
    printf("Makanan | Sisa durasi memasak\n");
    printf("-----------------------------\n");
    if (isEmptyCooked(q)) {
        printf("        |   \n");
    } else {
        for (int i = IDX_HEAD(q); i <= IDX_TAIL(q); i++) {
            printf("%s      | %d               \n", q.buffer[i].makanan, q.buffer[i].durasi);
        }
    }
    printf("\n");
}