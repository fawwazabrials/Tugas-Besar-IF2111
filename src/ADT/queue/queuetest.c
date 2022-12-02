#include "../../src/ADT/queue.h"
#include "../../src/ADT/q_dinerdash.h"
#include "../../src/ADT/mesinkarakter.h"
#include "../../src/ADT/mesinkata.h"

int main() {
    printf("====================== DRIVER QUEUE ======================\n");

    Queue Q;
    CreateQueue(&Q);

    if (isEmpty(Q)) {
        printf("Queue kosong\n");
    }

    printf("Testing proses enqueue. Silakan tulis beberapa kata.\n");
    STARTWORD();
    while (!EndWord) {
        enqueue(&Q, currentWord);
        ADVWORD();
    }

    if (! isEmpty(Q)) {
        printf("Queue tidak kosong\n\n");
    }

    printf("Isi queue sekarang adalah \n");
    DisplayQueue(Q);
    printf("Panjang queue sekarang adalah %d\n", length(Q));
    
    printf("\nTesting prosedur dequeue\n");
    Word deq;
    dequeue(&Q, &deq);

    printf("\nKata yang di-dequeue adalah ");
    displayWord(deq, true);
    printf("\n");

    DisplayQueue(Q);

    printf("\n================= DRIVER QUEUE DINER DASH =================\n");

    Food food1, food2, food3;

    food1.makanan = "M0";
    food1.durasi = 1;
    food1.ketahanan = 1;
    food1.harga = 10000;

    food2.makanan = "M1";
    food2.durasi = 2;
    food2.ketahanan = 2;
    food2.harga = 2000;

    food3.makanan = "M2";
    food3.durasi = 3;
    food3.ketahanan = 3;
    food3.harga = 3000;

    Queue_DD QFood;
    CreateQueueDD(&QFood);

    if (isEmptyDD(QFood)) {
        printf("Queue QFood kosong\n");
    }
    printf("Testing proses enqueue. Memasukkan beberapa makanan.\n");
    enqueueDD(&QFood, food1);
    enqueueDD(&QFood, food2);
    enqueueDD(&QFood, food3);

    printf("Menampilkan isi Queue Food dengan view displayQueueFood\n");
    displayQueueFood(QFood);
    printf("Menampilkan Queue Food dengan view displayQueueCook\n");
    displayQueueCooked(QFood);
    printf("Menampilkan Queue Food dengan view displayQueueRTS\n");
    displayQueueRTS(QFood);

    Food delfood;
    dequeueDD(&QFood, &delfood);

    printf("Isi Queue Food sekarang adalah \n");
    displayQueueFood(QFood);

    return 0;

}