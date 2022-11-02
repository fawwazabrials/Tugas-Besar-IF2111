#include "q_dinerdash.c"
#include <stdio.h>

int main () {
    Queue foodies;
    printf("Membuat foodies...\n");
    CreateQueue(&foodies);
    if (isEmpty(foodies)) {
        printf("Pembuatan foodies berhasil\n");
    } else {
        printf("Pembuatan foodies tidak berhasil\n");
    }
    printf("Isi foodies saat ini adalah: \n");
    displayQueueFood(foodies);

    Queue cooked;
    printf("Membuat cooked...\n");
    CreateQueue(&cooked);
    if (isEmpty(cooked)) {
        printf("Pembuatan cooked berhasil\n");
    } else {
        printf("Pembuatan cooked tidak berhasil\n");
    }
    printf("Isi cooked saat ini adalah: \n");
    displayQueueCooked(cooked);

    Queue rts;
    printf("Membuat rts...\n");
    CreateQueue(&rts);
    if (isEmpty(rts)) {
        printf("Pembuatan rts berhasil\n");
    } else {
        printf("Pembuatan rts tidak berhasil\n");
    }
    printf("Isi rts saat ini adalah: \n");
    displayQueueRTS(rts);

    Food food1;
    food1.makanan = "M0";
    food1.durasi = 3;
    food1.ketahanan = 5;
    food1.harga = 15000;

    printf("Mengantrikan food1 \n");
    enqueue(&foodies, food1);

    printf("Jumlah foodies sekarang adalah: %d\n", length(foodies));
    printf("Isi foodies saat ini adalah: \n");
    displayQueueFood(foodies);

    Food food2;
    food2.makanan = "M1";
    food2.durasi = 5;
    food2.ketahanan = 2;
    food2.harga = 30000;

    printf("Mengantrikan food2 \n");
    enqueue(&foodies, food2);
    printf("Makanan food2: %s\n", foodies.buffer[1].makanan);
    printf("Indeks tail setelah dienqueue food ke-2 %d\n", IDX_TAIL(foodies));
    printf("Jumlah foodies sekarang adalah: %d\n", length(foodies));
    printf("Isi foodies saat ini adalah: \n");
    displayQueueFood(foodies);

    Food foodval;
    dequeue(&foodies, &foodval);
    printf("Makanan yang diambil adalah: %s\n", foodval.makanan);
    printf("Jumlah foodies sekarang adalah: %d\n", length(foodies));
    printf("Isi foodies saat ini adalah: \n");
    displayQueueFood(foodies);

    printf("Mengantrikan makanan yang baru diqueue ke cooked\n");
    enqueue(&cooked, foodval);
    printf("Isi cooked saat ini adalah: \n");
    displayQueueCooked(cooked);

    printf("Mengantrikan makanan yang baru diqueue ke rts\n");
    enqueue(&rts, foodval);
    printf("Isi rts saat ini adalah: \n");
    displayQueueRTS(rts);

    return 0;
}