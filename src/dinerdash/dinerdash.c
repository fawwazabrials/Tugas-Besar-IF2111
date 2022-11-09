#include <stdio.h>
#include "dinerdash.h"
#include "q_dinerdash.h"
#include "q_dinerdash.c"                // Jangan lupa delete kalo udah selese
#include "../functions.c"               // Jangan lupa ganti jadi .h
#include "../ADT/mesinkarakter.h"
#include "../ADT/mesinkarakter.c"       // Jangan lupa delete kalo udah selese
#include "../ADT/mesinkata.h"
#include "../ADT/mesinkata.c"           // Jangan lupa delete kalo udah selese

/*
    TO DO :
    * buat skema valid untuk cooking and serve (co: kalo mau COOK M1, M1 harus ada di daftar Pesanan)
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
            if (q->buffer[i].durasi == 0) {
                printf("Berhasil memasak %s\n", q->buffer[i].makanan);
            }
        } else {
            if (q->buffer[i].ketahanan > -1) {
                q->buffer[i].ketahanan--;
            }
        }
        i++;
    }
}

void cooking(Queue QF, Queue *QC, char* commandID) {
    /* Memasak makanan yang ada di Queue Pesanan */
    /* I.S. Queue Food dan Cooked terdefinisi */
    /* F.S. Food dengan commandID akan ter-enqueue ke Cooked */
    int i = IDX_HEAD(QF);
    while (i < IDX_TAIL(QF)) {
        if (sameString(QF.buffer[i].makanan, commandID)) {
            enqueue(QC, QF.buffer[i]);
        }
        i++;
    }
}

void serving(Queue *QS, Queue *QF, char* commandID, int *saldo) {
    /* Menyajikan makanan */
    /* I.S. Queue ReadyToServe terdefinisi */
    /* F.S. Food di ReadyToServe ter-dequeue */
    Food val;
    if (sameString((*QS).buffer[IDX_HEAD(*QS)].makanan, commandID)) {
        if ((*QS).buffer[IDX_HEAD(*QS)].durasi == 0) {
            dequeue(QS, &val);
            printf("Berhasil menyajikan makanan %s\n", val.makanan);
            *saldo = *saldo + val.harga;

            // Search and Delete from Food (Treating it like a normal array)
            int i = IDX_HEAD(*QF);
            while (i <= IDX_TAIL(*QF)) {
                if (sameString((*QF).buffer[i].makanan, commandID)) {
                    ForceDeleteAt(QF, i);
                }
                i++;
            }
        } else {
            printf("%s belum selesai dimasak\n", commandID);
        }
    } else {
        printf("%s belum bisa disajikan karena %s belum selesai\n", commandID, HEAD(*QS));
    }
}

void checkBasi(Queue *QC) {
    /* Mengecek apakah ada makanan yang sudah basi */
    /* I.S. Queue Cooked terdefinisi */
    /* F.S. Apabila ada makanan yang sudah basi, maka akan di-dequeue */
    int i = IDX_HEAD(*QC);
    if (! isEmpty(*QC)) {
        while (i <= IDX_TAIL(*QC)) {
            if ((*QC).buffer[i].ketahanan == -1) {
                dequeue(QC, &(*QC).buffer[i]);
                printf("Makanan %s sudah basi.\n", (*QC).buffer[i].makanan);
            }
            i++;
        }
    }

}

void moveToServe(Queue *QC, Queue *QS) {
    /* Memindahkan makanan yang sudah dimasak ke Queue ReadyToServe */
    /* I.S. Queue Cooked dan ReadyToServe terdefinisi */
    /* F.S. Apabila ada makanan yang sudah selesai dimasak, maka akan di-enqueue ke ReadyToServe */
    int i = IDX_HEAD(*QC);
    if (! isEmpty(*QC)) {
        while (i <= IDX_TAIL(*QC)) {
            Food val;
            if ((*QC).buffer[i].durasi == 0) {
                val = (*QC).buffer[i];
                enqueue(QS, val);
                // dequeue(QC, &val);
                ForceDeleteAt(QC, i);
            }
            i++;
        }
    }
}

boolean IsIn(Queue q, char* X) {
/* Mengirimkan true apabila ada elemen X pada queue ber-ElType makanan. */
    int i = IDX_HEAD(q);
    boolean found = false;
    while (i <= IDX_TAIL(q) && ! found) {
        if (sameString(X, q.buffer[i].makanan)) {
            found = true;
        }
        i++;
    }
    return found;
}

void dinerdash() {
    /* DEKLARASI VARIABEL DAN ADT */
    int saldo = 0;
    int countServe = 0;
    char* inputCommand = (char*) malloc(100 * sizeof(char));
    char* commandInput = (char*) malloc(100 * sizeof(char));
    char* commandIDInput = (char*) malloc(100 * sizeof(char));
    char* command = (char*) malloc(100 * sizeof(char));
    char* commandID = (char*) malloc(100 * sizeof(char));
    Queue food;
    Queue cook;
    Queue serve;
    int round = 0;
    ListID listID = ID();
    Word inputWord;
    Word placeholder1;
    int placeholder2;
    boolean available;

    /* INISIALISASI ADT */
    CreateQueue(&food);
    CreateQueue(&cook);
    CreateQueue(&serve);

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
    displayQueueCooked(cook);
    displayQueueRTS(serve);

    /* Masukkin command dengan Mesin Kata */
    /* Contoh: COOK M1 */
    printf("MASUKKAN COMMAND (COOK/SERVE/SKIP): \n");
    scan("%s", &inputWord, &placeholder1, &placeholder2);
    inputCommand = WordToString(inputWord);
    separateSpace(inputCommand, command, commandID);

    /* VALIDASI INPUT COMMAND */
    while (! sameString(command, "COOK") && ! sameString(command, "SERVE") && ! sameString(command, "SKIP")) {
        printf("Command tidak valid.\n");
        printf("MASUKKAN COMMAND (COOK/SERVE/SKIP): \n");
        scan("%s", &inputWord, &placeholder1, &placeholder2);
        inputCommand = WordToString(inputWord);
        separateSpace(inputCommand, command, commandID);
    }

    /* GAME LOOP */
    while (length(food) <= 7 && countServe <= 15) {
        available = IsIn(food, commandID);
        /* Permainan selesai apabila antrian melebihi 7 pelanggan atau
        jumlah pelanggan yang sudah dilayani mencapai 15 pelanggan. */

        if (available) {
            /* MENAMBAHKAN PESANAN SECARA OTOMATIS */
            jumlahPesanan++;
            Food new = newOrder(food, jumlahPesanan-1);
            enqueue(&food, new);

            /* PENGURANGAN DURASI MEMASAK DAN KETAHANAN MAKANAN */
            if (! isEmpty(cook)) {
                autoSubstract(&cook);
            }
            if ( ! isEmpty(serve)) {
                autoSubstract(&serve);
            }

            /* MEMINDAHKAN MAKANAN DARI COOK KE SERVE APABILA DURASI = 0 */
            moveToServe(&cook, &serve);

            /* MENGHILANGKAN MAKANAN YANG BASI */
            checkBasi(&serve);

            /* PENYOCOKAN DENGAN COMMAND */
            if (sameString(command, "COOK")) {
                cooking(food, &cook, commandID);
            } else if (sameString(command, "SERVE")) {
                serving(&serve, &food, commandID, &saldo);
                countServe++;
            } else if (sameString(command, "SKIP")) {
                printf("ROUND KE-%d DI SKIP.\n", round);
            }

        }

        printf("\n======================== ROUND %d ========================\n\n", round);

        /* Display Queue */
        printf("SALDO: %d\n\n", saldo);
        displayQueueFood(food);
        displayQueueCooked(cook);
        displayQueueRTS(serve);

        /* GAME OVER */
        if (length(food) > 7) {
            printf("Game Over! Antrian pelanggan sudah melebihi 7 orang.\n");
            printf("Saldo akhir Anda adalah %d.\n", saldo);
            break;
        } else if (countServe >= 15) {
            printf("Game Over! Jumlah pelanggan yang sudah dilayani sudah mencapai 15 orang.\n");
            printf("Saldo akhir Anda adalah %d.\n", saldo);
            break;
        }

        /* Input Command */
        printf("MASUKKAN COMMAND (COOK/SERVE/SKIP): \n");
        scan("%s", &inputWord, &placeholder1, &placeholder2);
        inputCommand = WordToString(inputWord);
        separateSpace(inputCommand, command, commandID);

        /* VALIDASI INPUT COMMAND */
        while (! sameString(command, "COOK") && ! sameString(command, "SERVE") && ! sameString(command, "SKIP")) {
            printf("Command tidak valid.\n");
            printf("MASUKKAN COMMAND (COOK/SERVE/SKIP): \n");
            scan("%s", &inputWord, &placeholder1, &placeholder2);
            inputCommand = WordToString(inputWord);
            separateSpace(inputCommand, command, commandID);
        }

        /* PENAMBAHAN BABAK */
        round++;
    }

}

int main() {
    dinerdash();
    return 0;
}