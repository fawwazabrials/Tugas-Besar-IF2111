#include "food.c"

int main () {
    QueueFood foodies;
    CreateQueueFood(&foodies);
    if (isEmptyFood(foodies)) {
        printf("Pembuatan foodies berhasil\n");
    } else {
        printf("Pembuatan foodies tidak berhasil\n");
    }
    printf("Isi foodies saat ini adalah: \n");
    displayQueueFood(foodies);

    Food food1;
    food1.makanan = "M0";
    food1.durasi = 3;
    food1.ketahanan = 5;
    food1.harga = 15000;

    enqueueFood(&foodies, food1);

    printf("Jumlah foodies sekarang adalah: %d\n", lengthFood(foodies));
    printf("Isi foodies saat ini adalah: \n");
    displayQueueFood(foodies);

    Food food2;
    food2.makanan = "M1";
    food2.durasi = 5;
    food2.ketahanan = 2;
    food2.harga = 30000;

    enqueueFood(&foodies, food2);
    printf("Makanan food2: %s\n", foodies.buffer[1].makanan);
    printf("Indeks tail setelah dienqueue food ke-2 %d\n", IDX_TAIL(foodies));
    printf("Jumlah foodies sekarang adalah: %d\n", lengthFood(foodies));
    printf("Isi foodies saat ini adalah: \n");
    displayQueueFood(foodies);

    Food foodval;
    dequeueFood(&foodies, &foodval);
    printf("Makanan yang diambil adalah: %s\n", foodval.makanan);
    printf("Jumlah foodies sekarang adalah: %d\n", lengthFood(foodies));
    printf("Isi foodies saat ini adalah: \n");
    displayQueueFood(foodies);

    return 0;
}