#include <stdio.h>
#include "dinerdash.h"
#include "q_dinerdash.h"
#include "q_dinerdash.c"        // Jangan lupa delete kalo udah selese
#include "../functions.c"       // Jangan lupa ganti jadi .h

/*
    TO DO :
    * Mesin kata taek
*/

ListID ID() {
    /* Membuat list berisi ID makanan */
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

Food newOrder(Queue q, int angka) {
    /* Membuat Food baru untuk pesanan dengan increment */
    Food new;
    ListID listID = ID();
    
    new.makanan = listID.buffer[angka].ID;
    new.durasi = randint(1, 5);
    new.ketahanan = randint(1, 5);
    new.harga = randint(1, 5) * 10000;
    
    return new;
}

void autoSubstract(Queue *q) {
    /* Mengurangi durasi memasak makanan atau durasi ketahanan makanan */
    /* I.S. Queue dengan ElType = Food terdefinisi */
    /* F.S. Apabila durasi makanan lebih dari 0, maka akan durasi makanan berkurang 1 */
    /*      Apabila durasi makanan sama dengan 0, maka durasi ketahanan berkurang 1 sampai
            ketahanan makanan menjadi 0 */
    int i = IDX_HEAD(*q);
    while (i <= IDX_TAIL(*q)) {
        if (q->buffer[i].durasi > 0) {
            q->buffer[i].durasi--;
        } else {
            if (q->buffer[i].ketahanan > -1) {
                q->buffer[i].ketahanan--;
            }
        }
        i++;
    }
}

void cook(Queue QF, Queue *QC, char* commandID) {
    /* Memasak makanan yang ada di Queue Pesanan */
    /* I.S. Queue Food dan Cooked terdefinisi */
    /* F.S. Food dengan commandID akan ter-enqueue ke Cooked */
    int i = IDX_HEAD(QF);
    while (i < IDX_TAIL(QF)) {
        if (QF.buffer[i].makanan == commandID) {
            enqueue(QC, QF.buffer[i]);
            printf("Berhasil memasak %s\n", commandID);
        }
        i++;
    }
}

void serve(Queue *QR, char* commandID, int *saldo) {
    /* Menyajikan makanan */
    /* I.S. Queue ReadyToServe terdefinisi */
    /* F.S. Food di ReadyToServe ter-dequeue */
    Food val;
    if ((*QR).buffer[IDX_HEAD(*QR)].makanan == commandID) {
        if ((*QR).buffer[IDX_HEAD(*QR)].durasi == 0) {
            dequeue(QR, &val);
            printf("Berhasil menyajikan makanan %s\n", val.makanan);
            *saldo = *saldo + val.harga;
        } else {
            printf("%s belum selesai dimasak\n", commandID);
        }
    } else {
        printf("%s belum bisa disajikan karena %s belum selesai\n", commandID, HEAD(*QR));
    }
}

// void inputToCommand(char* input, char* command, char* commandID) {
//     /* Memisahkan input menjadi command dan commandID */
//     char COOK[4] = "COOK";
//     char SERVE[5] = "SERVE";
//     boolean isCook = true;
//     boolean isServe = true;
//     int i = 0;
//     if (input[i] == 'C') {
//         while (i < 4 && isCook) {
//             if (*(input + i) != COOK[i]) {
//                 isCook = false;
//             }
//             i++;
//         }
//         if (isCook) {
//             command = "COOK";
//             for (int i = 0; i < 3; i++) {
//                 *(commandID + i) = *(input + 5 + i);
//             }
//         }
//     } else if (input[i] == 'S') {
//         while (i < 5 && isServe) {
//             if (*(input + i) != SERVE[i]) {
//                 isServe = false;
//             }
//             i++;
//         }
//         if (isServe) {
//             command = "SERVE";
//             for (int i = 0; i < 3; i++) {
//                 *(commandID + i) = *(input + 6 + i);
//             }
//         }
//     }   
// }

void dinerdash() {
    /* DEKLARASI VARIABEL DAN ADT */
    int saldo = 0;
    int countServe = 0;
    char* command;
    char* commandID;
    char commandinput[10];
    Queue food;
    Queue cookserve;
    int round = 0;
    ListID listID = ID();

    /* INISIALISASI ADT */
    CreateQueue(&food);
    CreateQueue(&cookserve);

    /* INISIALISASI Food */
    /* Menyiapkan 3 pesanan dari 3 pelanggan */
    int jumlahPesanan = 3;
    for (int i = 0; i < jumlahPesanan; i++) {
        Food new = newOrder(food, i);
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
    displayQueueFood(food);
    displayQueueCooked(cookserve);
    displayQueueRTS(cookserve);

    /* Masukkin command dengan Mesin Kata */
    /* Contoh: COOK M1 */
    printf("MASUKKAN COMMAND: \n");
    // scanf("%[^\n]", commandinput);
    // inputToCommand(commandinput, command, commandID);

    /* TESTING COMMAND */
    command = "COOK";
    commandID = "M0";

    /* GAME LOOP */
    while (length(food) < 7 && countServe < 15) {
        /* Permainan selesai apabila antrian melebihi 7 pelanggan atau
        jumlah pelanggan yang sudah dilayani mencapai 15 pelanggan. */

        /* TESTING COMMAND */
        if (round % 2 == 0) {
            command = "COOK";
            commandID = listID.buffer[round].ID;
        } else {
            command = "SERVE";
            commandID = listID.buffer[round].ID;
        }
        printf("%s %s\n", command, commandID);

        /* MENAMBAHKAN PESANAN SECARA OTOMATIS */
        jumlahPesanan++;
        Food new = newOrder(food, jumlahPesanan-1);
        enqueue(&food, new);

        /* PENGURANGAN DURASI MEMASAK DAN KETAHANAN MAKANAN */
        if (! isEmpty(cookserve)) {
            autoSubstract(&cookserve);
        }

        if (command == "COOK") {
            cook(food, &cookserve, commandID);
        } else if (command == "SERVE") {
            serve(&cookserve, commandID, &saldo);
            countServe++;
        }

        printf("\n======================= ROUND %d =======================\n\n", round);

        /* Display Queue */
        printf("SALDO: %d\n\n", saldo);
        displayQueueFood(food);
        displayQueueCooked(cookserve);
        displayQueueRTS(cookserve);

        /* Input Command */
        printf("MASUKKAN COMMAND: \n");
        // scanf("%[^\n]", commandinput);
        // inputToCommand(commandinput, command, commandID);

        /* TESTING */
        round++;
    }

    /* GAME OVER */
    if (length(food) >= 7) {
        printf("Game Over! Antrian pelanggan sudah melebihi 7 orang.\n");
    } else if (countServe >= 15) {
        printf("Game Over! Jumlah pelanggan yang sudah dilayani sudah mencapai 15 orang.\n");
    }
}

int main() {
    dinerdash();
    return 0;
}