#include "q_dinerdash.h"
#include <stdio.h>

/* ********* AKSES (Selektor) ********* */
/* Jika q adalah Queue_DD, maka akses elemen : */
#define IDX_HEAD_DD(q) (q).idxHeadQDD
#define IDX_TAIL_DD(q) (q).idxTailQDD
#define     HEAD_DD(q) (q).buffer[(q).idxHeadQDD]
#define     TAIL_DD(q) (q).buffer[(q).idxTailQDD]

/* *** Kreator *** */
void CreateQueueDD(Queue_DD *q) {
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
    IDX_HEAD_DD(*q) = IDX_UNDEF;
    IDX_TAIL_DD(*q) = IDX_UNDEF;
}

/* ********* Prototype ********* */
boolean isEmptyDD(Queue_DD q) {
/* Mengirim true jika q kosong: lihat definisi di atas */
    return (IDX_HEAD_DD(q) == IDX_UNDEF && IDX_TAIL_DD(q) == IDX_UNDEF);
}
boolean isFullDD(Queue_DD q) {
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL_DD akan selalu di belakang IDX_HEAD_DD dalam buffer melingkar*/
    return (lengthDD(q) == CAPACITY);
}

int lengthDD(Queue_DD q) {
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
    if (isEmptyDD(q)) {
        return 0;
    } else {
        return IDX_TAIL_DD(q) - IDX_HEAD_DD(q) + 1;
    }
}

/* *** Primitif Add/Delete *** */
void enqueueDD(Queue_DD *q, ElTypeQDD val) {
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL_DD yang baru, IDX_TAIL_DD "mundur" dalam buffer melingkar. */
    if (isEmptyDD(*q)) {
        (*q).idxHeadQDD = 0;
        (*q).idxTailQDD = 0;
    } else {
        (*q).idxTailQDD = (*q).idxTailQDD + 1;
    }
    (*q).buffer[(*q).idxTailQDD].makanan = val.makanan;
    (*q).buffer[(*q).idxTailQDD].durasi = val.durasi;
    (*q).buffer[(*q).idxTailQDD].ketahanan = val.ketahanan;
    (*q).buffer[(*q).idxTailQDD].harga = val.harga;
}

void dequeueDD(Queue_DD *q, ElTypeQDD *val) {
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD_DD pd I.S., IDX_HEAD_DD "mundur";
        q mungkin kosong */
    *val = HEAD_DD(*q);
    if (IDX_HEAD_DD(*q) == IDX_TAIL_DD(*q)) {
        IDX_HEAD_DD(*q) = IDX_UNDEF;
        IDX_TAIL_DD(*q) = IDX_UNDEF;
    } else {
        IDX_HEAD_DD(*q)++;
    }
}

void ForceDeleteAt(Queue_DD *q, int i) {
/* Menghapus elemen array secara paksa (bukan dequeueDD) */
/* I.S. Queue_DD  terdefinisi dan tidak kosong */
/* F.S. Elemen Queue_DD ke-i terhapus */
    Food val;
    if (i == IDX_HEAD_DD(*q)) {
        dequeueDD(q, &val);
    } else {
        int j = IDX_TAIL_DD(*q);
        val = q->buffer[i];
        while (i <= j) {
            q->buffer[i] = q->buffer[i+1];
            i++;
        }
        IDX_TAIL_DD(*q)--;
        if (IDX_TAIL_DD(*q) < 0) {
            IDX_TAIL_DD(*q) == CAPACITY-1;
        }
    }
}

/* *** Display Queue_DD *** */
void displayQueueFood(Queue_DD q) {
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
    printf("Daftar Pesanan\t\t\t  Banyaknya pesanan: %d\n", lengthDD(q));
    printf("Makanan\t| Durasi memasak\t| Ketahanan\t| Harga\n");
    printf("--------------------------------------------------------\n");
    if (isEmptyDD(q)) {
        printf("\t| \t\t\t| \t\t| \n");
    } else {
        for (int i = IDX_HEAD_DD(q); i <= IDX_TAIL_DD(q); i++) {
            printf("%s\t| %d\t\t\t| %d\t\t| %d \n", q.buffer[i].makanan, q.buffer[i].durasi, q.buffer[i].ketahanan, q.buffer[i].harga);
        }
    } 
    printf("\n");
}

void displayQueueCooked(Queue_DD q) {
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
    printf("Daftar Makanan yang sedang dimasak\n");
    printf("Makanan\t| Sisa durasi memasak\n");
    printf("-----------------------------\n");
    if (isEmptyDD(q)) {
        printf(" \t| \n");
    } else {
        for (int i = IDX_HEAD_DD(q); i <= IDX_TAIL_DD(q); i++) {
            printf("%s\t| %d\n", q.buffer[i].makanan, q.buffer[i].durasi);
        }
    }
    printf("\n");
}

void displayQueueRTS(Queue_DD q) {
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
    printf("Daftar Makanan yang dapat disajikan\n");
    printf("Makanan | Sisa ketahanan memasak\n");
    printf("---------------------------------\n");
    if (isEmptyDD(q)) {
        printf(" \t| \n");
    } else {
        for (int i = IDX_HEAD_DD(q); i <= IDX_TAIL_DD(q); i++) {
            printf("%s\t| %d\n", q.buffer[i].makanan, q.buffer[i].ketahanan);
        }
    }
    printf("\n");
}