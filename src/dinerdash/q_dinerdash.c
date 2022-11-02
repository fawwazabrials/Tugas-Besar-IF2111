#include "q_dinerdash.h"
#include <stdio.h>

/* ********* AKSES (Selektor) ********* */
/* Jika q adalah Queue, maka akses elemen : */
#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define     HEAD(q) (q).buffer[(q).idxHead]
#define     TAIL(q) (q).buffer[(q).idxTail]

/* *** Kreator *** */
void CreateQueue(Queue *q) {
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

/* ********* Prototype ********* */
boolean isEmpty(Queue q) {
/* Mengirim true jika q kosong: lihat definisi di atas */
    return (IDX_HEAD(q) == IDX_UNDEF && IDX_TAIL(q) == IDX_UNDEF);
}
boolean isFull(Queue q) {
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/
    return (length(q) == CAPACITY);
}

int length(Queue q) {
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
    if (isEmpty(q)) {
        return 0;
    } else {
        return IDX_TAIL(q) - IDX_HEAD(q) + 1;
    }
}
/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, ElType val) {
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */
    if (isEmpty(*q)) {
        (*q).idxHead = 0;
        (*q).idxTail = 0;
    } else {
        (*q).idxTail = (*q).idxTail + 1;
    }
    (*q).buffer[(*q).idxTail].makanan = val.makanan;
    (*q).buffer[(*q).idxTail].durasi = val.durasi;
    (*q).buffer[(*q).idxTail].ketahanan = val.ketahanan;
    (*q).buffer[(*q).idxTail].harga = val.harga;
}

void dequeue(Queue *q, ElType *val) {
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
void displayQueueFood(Queue q) {
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
    printf("Daftar Pesanan\n");
    printf("Makanan\t| Durasi memasak\t| Ketahanan\t| Harga\n");
    printf("--------------------------------------------------------\n");
    if (isEmpty(q)) {
        printf("\t| \t\t\t| \t\t| \n");
    } else {
        for (int i = IDX_HEAD(q); i <= IDX_TAIL(q); i++) {
            printf("%s\t| %d\t\t\t| %d\t\t| %d \n", q.buffer[i].makanan, q.buffer[i].durasi, q.buffer[i].ketahanan, q.buffer[i].harga);
        }
    } 
    printf("\n");
}

void displayQueueCooked(Queue q) {
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
    printf("Daftar Makanan yang sedang dimasak\n");
    printf("Makanan\t| Sisa durasi memasak\n");
    printf("-----------------------------\n");
    if (isEmpty(q)) {
        printf(" \t| \n");
    } else {
        for (int i = IDX_HEAD(q); i <= IDX_TAIL(q); i++) {
            if (q.buffer[i].durasi > 0) {
                printf("%s\t| %d\n", q.buffer[i].makanan, q.buffer[i].durasi);
            }
        }
    }
    printf("\n");
}

void displayQueueRTS(Queue q) {
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
    printf("Daftar Makanan yang dapat disajikan\n");
    printf("Makanan | Sisa ketahanan memasak\n");
    printf("---------------------------------\n");
    if (isEmpty(q)) {
        printf(" \t| \n");
    } else {
        for (int i = IDX_HEAD(q); i <= IDX_TAIL(q); i++) {
            if (q.buffer[i].durasi == 0) {
                if (q.buffer[i].ketahanan >= 0) {
                    printf("%s\t| %d\n", q.buffer[i].makanan, q.buffer[i].ketahanan);
                }
            }
        }
    }
    printf("\n");
}