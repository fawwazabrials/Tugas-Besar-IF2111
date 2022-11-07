#include "boolean.h"
#include "q_dinerdash.h"

typedef struct {
    char* ID;
} IDMakanan;

typedef struct {
    IDMakanan buffer[15];
} ListID;

void autoSubstract(Queue *q);
    /* Mengurangi durasi memasak makanan atau durasi ketahanan makanan */
    /* I.S. Queue dengan ElType = Food terdefinisi */
    /* F.S. Apabila durasi makanan lebih dari 0, maka akan durasi makanan berkurang 1 */
    /*      Apabila durasi makanan sama dengan 0, maka durasi ketahanan berkurang 1 sampai
            ketahanan makanan menjadi 0 */

void cooking(Queue QF, Queue *QC, char* commandID);
    /* Memasak makanan yang ada di Queue Pesanan */
    /* I.S. Queue Food dan Cooked terdefinisi */
    /* F.S. Food dengan commandID akan ter-enqueue ke Cooked */

void serving(Queue *QR, Queue *QF, char* commandID, int *saldo);
    /* Menyajikan makanan */
    /* I.S. Queue ReadyToServe terdefinisi */
    /* F.S. Food di ReadyToServe ter-dequeue */

void checkBasi(Queue *QC);
    /* Mengecek apakah ada makanan yang sudah basi */
    /* I.S. Queue Cooked terdefinisi */
    /* F.S. Apabila ada makanan yang sudah basi, maka akan di-dequeue */

void dinerdash();
/* Game Diner Dash */