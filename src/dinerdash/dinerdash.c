#include <stdio.h>
#include "dinerdash.h"
#include "q_dinerdash.h"
#include "q_dinerdash.c"

ListID ID() {
    ListID listID;
    listID.buffer[0].ID = "M0";
    listID.buffer[1].ID = "M1";
    listID.buffer[2].ID = "M2";
    listID.buffer[3].ID = "M3";
    listID.buffer[4].ID = "M4";
    listID.buffer[5].ID = "M5";
    listID.buffer[6].ID = "M6";
    listID.buffer[7].ID = "M7";
    listID.buffer[8].ID = "M8";
    listID.buffer[9].ID = "M9";
    listID.buffer[10].ID = "M10";
    listID.buffer[11].ID = "M11";
    listID.buffer[12].ID = "M12";
    listID.buffer[13].ID = "M13";
    listID.buffer[14].ID = "M14";
    return listID;
}

Food newFood(Queue q, int jumlahPesanan) {
    /* Membuat Food baru untuk pesanan dengan increment */
    Food new;
    ListID listID = ID();
    int len = length(q);
    
    new.makanan = listID.buffer[len].ID;
    new.durasi = 1 + len; // harusnya random
    new.ketahanan = 1 + len; //harusnya random
    new.harga = 10000 + len * 10000; //harusnya random
    
    jumlahPesanan++;
    return new;
}

Food getFoodDetails(Queue q, char* commandID) {
/* Asumsi: Selalu ada commandID yang dicari */
    Food food;
    int i = IDX_HEAD(q);
    while (i <= IDX_TAIL(q)) {
        if (q.buffer[i].makanan == commandID) {
            food = q.buffer[i];
        }
        i++;
    }
    return food;
}

void DeleteOrder(Queue *q, char* commandID) {
    /* Menghapus makanan dari pesanan yang sudah dipindahkan ke cooked */
    int i = IDX_HEAD(*q);
    while (i <= IDX_TAIL(*q)) {
        if (q->buffer[i].makanan == commandID) {
            q->buffer[i] = q->buffer[i+1];
        }
        i++;
    }
}

void DeleteCooked(Queue *q, char* commandID) {
    /* Menghapus makanan dari cooked yang sudah dipindahkan ke ReadyToServe */
    int i = IDX_HEAD(*q);
    while (i <= IDX_TAIL(*q)) {
        if (q->buffer[i].makanan == commandID) {
            q->buffer[i] = q->buffer[i+1];
        }
        i++;
    }
}

void DeleteReadyToServe(Queue *q, char* commandID) {
    /* Menghapus makanan dari ReadyToServe yang sudah di-Serve */
    int i = IDX_HEAD(*q);
    while (i <= IDX_TAIL(*q)) {
        if (q->buffer[i].makanan == commandID) {
            q->buffer[i] = q->buffer[i+1];
        }
        i++;
    }
}

void substractDuration(Queue *q) {
    /* Mengurangi durasi memasak makanan Cooked */
    int i = IDX_HEAD(*q);
    while (i <= IDX_TAIL(*q)) {
        if (q->buffer[i].durasi > 0) {
            q->buffer[i].durasi--;
        }
        i++;
    }
}

void substractKetahanan(Queue *q) {
    /* Mengurangi ketahanan makanan dari ReadyToServe */
    int i = IDX_HEAD(*q);
    while (i <= IDX_TAIL(*q)) {
        q->buffer[i].ketahanan--;
        i++;
    }
}

Food copyFood(Food food1) {
    Food food2;
    food2.makanan = food1.makanan;
    food2.durasi = food1.durasi;
    food2.ketahanan = food1.ketahanan;
    food2.harga = food1.harga;
    return food2;
}

void FromQCookToQRTS(Queue *QC, Queue *QR) {
    /* Memindahkan makanan dari QueueCooked ke QueueRTS apabila durasi memasak sudah 0*/
    Food fromCooked;
    Food toRTS;
    int i = IDX_HEAD(*QC);
    while (i <= IDX_TAIL(*QC)) {
        if (QC->buffer[i].durasi == 0) {
            toRTS = copyFood(QC->buffer[i]);
            enqueue(QR, toRTS);
            DeleteCooked(QC, QC->buffer[i].makanan);
        }
        i++;
    }
}

void dinerdash() {
    /* DEKLARASI VARIABEL DAN ADT */
    int saldo = 0;
    int rounds = 0;
    int countServe = 0;
    char* command;
    char* commandID;
    Queue food;
    Queue cooked;
    Queue rts;

    /* INISIALISASI ADT */
    CreateQueue(&food);
    CreateQueue(&cooked);
    CreateQueue(&rts);

    /* INISIALISASI ADT Food */
    /* Menyiapkan 3 pesanan dari 3 pelanggan */
    int jumlahPesanan = 3;
    for (int i = 0; i < jumlahPesanan; i++) {
        Food new = newFood(food, jumlahPesanan);
        enqueue(&food, new);
    }

    /* WELCOME SCREEN */
    printf("======================================================\n");
    printf(" _____  _                   _____            _        \n");  
    printf("|  __ \\(_)                 |  __ \\          | |       \n");
    printf("| |  | |_ _ __   ___ _ __  | |  | | __ _ ___| |__     \n");        
    printf("| |  | | | '_ \\ / _ \\ '__| | |  | |/ _` / __| '_ \\    \n");
    printf("| |__| | | | | |  __/ |    | |__| | (_| \\__ \\ | | |   \n");
    printf("|_____/|_|_| |_|\\___|_|    |_____/ \\__,_|___/_| |_|   \n\n\n");                                     
    printf("Selamat Datang di Diner Dash!\n\n");
    
    /* Display Queue */
    printf("SALDO: %d\n\n", saldo);
    printf("Daftar Pesanan\n");
    displayQueueFood(food);
    printf("\n");
    printf("Daftar Makanan yang sedang dimasak\n");
    displayQueueCooked(cooked);
    printf("\n");
    printf("Daftar Makanan yang dapat disajikan\n");
    displayQueueRTS(rts);
    printf("\n");

    printf("MASUKKAN COMMAND: \n");
    // Masukkin command dengan Mesin Kata
    // Contoh: COOK M1

    /* TESTING COMMAND */
    command = "COOK";
    commandID = "M0";

    while (! isFull(food) && countServe < 15) {
        /* Permainan selesai apabila antrian melebihi 7 pelanggan atau
        jumlah pelanggan yang sudah dilayani mencapai 15 pelanggan. */

        /* INCREMENT JUMLAH PESANAN */
        jumlahPesanan++;
        Food new = newFood(food, jumlahPesanan);
        enqueue(&food, new);

        Food currentFood = getFoodDetails(food, commandID);
        Food currentCooked = copyFood(currentFood);

        if (command == "COOK") {
            if (! isEmpty(cooked)) {
                substractDuration(&cooked);
            }
            enqueue(&cooked, currentCooked);
            FromQCookToQRTS(&cooked, &rts);
            
            
        } else if (command == "SERVE") {
            printf("Serve");
        }

        countServe++;

        /* Display Queue */
        printf("SALDO: %d\n\n", saldo);
        printf("Daftar Pesanan\n");
        displayQueueFood(food);
        printf("\n");
        printf("Daftar Makanan yang sedang dimasak\n");
        displayQueueCooked(cooked);
        printf("\n");
        printf("Daftar Makanan yang dapat disajikan\n");
        displayQueueRTS(rts);
        printf("\n");
    }
}

int main() {
    dinerdash();
    return 0;
}