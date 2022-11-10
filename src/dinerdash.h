#include "functions.h"
#include "ADT/boolean.h"
#include "ADT/q_dinerdash.h"
#include "ADT/mesinkarakter.h"
#include "ADT/mesinkata.h"

typedef struct {
    char* ID;
} IDMakanan;

typedef struct {
    IDMakanan buffer[15];
} ListID;

ListID ID();
    /* Membuat list berisi ID makanan */

Food newOrder(Queue_DD q, int angka);
    /* Membuat Food baru untuk pesanan dengan increment */

void autoSubstract(Queue_DD *q);
    /* Mengurangi durasi memasak makanan atau durasi ketahanan makanan */
    /* I.S. Queue_DD dengan ElTypeQDD = Food terdefinisi */
    /* F.S. Apabila durasi makanan lebih dari 0, maka akan durasi makanan berkurang 1 */
    /*      Apabila durasi makanan sama dengan 0, maka durasi ketahanan berkurang 1 sampai
            ketahanan makanan menjadi 0 */

void cooking(Queue_DD QF, Queue_DD *QC, char* commandID);
    /* Memasak makanan yang ada di Queue_DD Pesanan */
    /* I.S. Queue_DD Food dan Cooked terdefinisi */
    /* F.S. Food dengan commandID akan ter-enqueueDD ke Cooked */

void serving(Queue_DD *QR, Queue_DD *QF, char* commandID, int *saldo);
    /* Menyajikan makanan */
    /* I.S. Queue_DD ReadyToServe terdefinisi */
    /* F.S. Food di ReadyToServe ter-dequeue */

void checkBasi(Queue_DD *QC);
    /* Mengecek apakah ada makanan yang sudah basi */
    /* I.S. Queue_DD Cooked terdefinisi */
    /* F.S. Apabila ada makanan yang sudah basi, maka akan di-dequeue */

void moveToServe(Queue_DD *QC, Queue_DD *QS);
    /* Memindahkan makanan yang sudah dimasak ke Queue_DD ReadyToServe */
    /* I.S. Queue_DD Cooked dan ReadyToServe terdefinisi */
    /* F.S. Apabila ada makanan yang sudah selesai dimasak, maka akan di-enqueueDD ke ReadyToServe */

boolean IsIn(Queue_DD q, char* X);
/* Mengirimkan true apabila ada elemen X pada queue ber-ElTypeQDD makanan. */

void dinerdash();
/* Game Diner Dash */