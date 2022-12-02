#include <stdio.h>
#include "dinerdash.h"

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

Food newOrder(Queue_DD q, int angka) {
    /* Membuat Food baru untuk pesanan dengan increment */
    Food new;
    ListID listID = ID();
    
    new.makanan = listID.buffer[angka].ID;
    new.durasi = randint(1, 5);
    new.ketahanan = randint(1, 5);
    new.harga = randint(1, 5) * 10000;
    
    return new;
}

void autoSubstract(Queue_DD *q) {
    /* Mengurangi durasi memasak makanan atau durasi ketahanan makanan */
    /* I.S. Queue_DD dengan ElTypeQDD = Food terdefinisi */
    /* F.S. Apabila durasi makanan lebih dari 0, maka akan durasi makanan berkurang 1 */
    /*      Apabila durasi makanan sama dengan 0, maka durasi ketahanan berkurang 1 sampai
            ketahanan makanan menjadi 0 */
    int i = IDX_HEAD_DD(*q);
    while (i <= IDX_TAIL_DD(*q)) {
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

void cooking(Queue_DD QF, Queue_DD *QC, char* commandID) {
    /* Memasak makanan yang ada di Queue_DD Pesanan */
    /* I.S. Queue_DD Food dan Cooked terdefinisi */
    /* F.S. Food dengan commandID akan ter-enqueueDD ke Cooked */
    int i = IDX_HEAD_DD(QF);
    while (i < IDX_TAIL_DD(QF)) {
        if (sameString(QF.buffer[i].makanan, commandID)) {
            enqueueDD(QC, QF.buffer[i]);
        }
        i++;
    }
}

void serving(Queue_DD *QS, Queue_DD *QF, char* commandID, int *saldo) {
    /* Menyajikan makanan */
    /* I.S. Queue_DD ReadyToServe terdefinisi */
    /* F.S. Food di ReadyToServe ter-dequeueDD */
    Food val;
    int idx;
    boolean found;
    if (sameString((*QF).buffer[IDX_HEAD_DD(*QF)].makanan, commandID)) {
        // Find the Food in Serving Queue
        idx = IDX_HEAD_DD(*QS);
        found = false;
        while (idx <= IDX_TAIL_DD(*QS) && ! found) {
            if (sameString((*QS).buffer[idx].makanan, commandID)) {
                found = true;
            }
            idx++;
        }
        if (QS->buffer[idx].durasi == 0) {
            ForceDeleteAt(QS, idx);
            // Dequeue from Food Queue
            dequeueDD(QF, &val);
            printf("Berhasil menyajikan makanan %s\n", val.makanan);
            *saldo = *saldo + val.harga;
        } else {
            printf("%s belum selesai dimasak\n", commandID);
        }
    } else {
        printf("%s belum bisa disajikan karena %s belum selesai\n", commandID, HEAD_DD(*QF).makanan);
    }

}

void checkBasi(Queue_DD *QC) {
    /* Mengecek apakah ada makanan yang sudah basi */
    /* I.S. Queue_DD Cooked terdefinisi */
    /* F.S. Apabila ada makanan yang sudah basi, maka akan di-dequeueDD */
    int i = IDX_HEAD_DD(*QC);
    if (! isEmptyDD(*QC)) {
        while (i <= IDX_TAIL_DD(*QC)) {
            if ((*QC).buffer[i].ketahanan == 0) {
                // dequeueDD(QC, &(*QC).buffer[i]);
                printf("Makanan %s sudah basi.\n", (*QC).buffer[i].makanan);
                ForceDeleteAt(QC, i);
            }
            i++;
        }
    }

}

void moveToServe(Queue_DD *QC, Queue_DD *QS) {
    /* Memindahkan makanan yang sudah dimasak ke Queue_DD ReadyToServe */
    /* I.S. Queue_DD Cooked dan ReadyToServe terdefinisi */
    /* F.S. Apabila ada makanan yang sudah selesai dimasak, maka akan di-enqueueDD ke ReadyToServe */
    int i = IDX_HEAD_DD(*QC);
    if (! isEmptyDD(*QC)) {
        while (i <= IDX_TAIL_DD(*QC)) {
            Food val;
            if ((*QC).buffer[i].durasi == 0) {
                val = (*QC).buffer[i];
                enqueueDD(QS, val);
                // dequeueDD(QC, &val);
                ForceDeleteAt(QC, i);
            }
            i++;
        }
    }
}

boolean IsIn(Queue_DD q, char* X) {
/* Mengirimkan true apabila ada elemen X pada queue ber-ElTypeQDD makanan. */
    int i = IDX_HEAD_DD(q);
    boolean found = false;
    while (i <= IDX_TAIL_DD(q) && ! found) {
        if (sameString(X, q.buffer[i].makanan)) {
            found = true;
        }
        i++;
    }
    return found;
}

int dinerdash() {
    /* DEKLARASI VARIABEL DAN ADT */
    int saldo = 0;
    int countServe = 0;
    char* inputCommand = (char*) malloc(100 * sizeof(char));
    char* commandInput = (char*) malloc(100 * sizeof(char));
    char* commandIDInput = (char*) malloc(100 * sizeof(char));
    char* command = (char*) malloc(100 * sizeof(char));
    char* commandID = (char*) malloc(100 * sizeof(char));
    Queue_DD food;
    Queue_DD cook;
    Queue_DD serve;
    int round = 0;
    ListID listID = ID();
    Word inputWord;
    Word placeholder1;
    int placeholder2;
    boolean available;

    /* INISIALISASI ADT */
    CreateQueueDD(&food);
    CreateQueueDD(&cook);
    CreateQueueDD(&serve);

    /* INISIALISASI Food */
    /* Menyiapkan 3 pesanan dari 3 pelanggan */
    int jumlahPesanan = 3;
    for (int i = 0; i < jumlahPesanan; i++) {
        Food new = newOrder(food, i);
        enqueueDD(&food, new);
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
    
    /* Display Queue_DD */
    printf("SALDO: %d\n\n", saldo);
    displayQueueFood(food);
    displayQueueCooked(cook);
    displayQueueRTS(serve);

    /* Masukkin command dengan Mesin Kata */
    /* Contoh: COOK M1 */
    printf("MASUKKAN COMMAND (COOK/SERVE/SKIP): \n");
    scan("%s", &inputWord, &placeholder1, &placeholder2);
    inputCommand = WordToString(inputWord);
    if (inputCommand[0] == 'S' && inputCommand[1] == 'K' && inputCommand[2] == 'I' && inputCommand[3] == 'P') {
        command[0] = 'S';
        command[1] = 'K';
        command[2] = 'I';
        command[3] = 'P';
        command[4] = '\0';
        printf("Anda memasukkan Skip.");
        available = true;
    } else {
        separateSpace(inputCommand, command, commandID);
    }

    /* VALIDASI INPUT COMMAND */
    while (! sameString(command, "COOK") && ! sameString(command, "SERVE") && ! sameString(command, "SKIP")) {
        printf("MASUKKAN COMMAND (COOK/SERVE/SKIP): \n");
        scan("%s", &inputWord, &placeholder1, &placeholder2);
        inputCommand = WordToString(inputWord);
        if (inputCommand[0] == 'S' && inputCommand[1] == 'K' && inputCommand[2] == 'I' && inputCommand[3] == 'P') {
            command[0] = 'S';
            command[1] = 'K';
            command[2] = 'I';
            command[3] = 'P';
            command[4] = '\0';
            printf("Anda memasukkan Skip.");
            available = true;
        } else {
            separateSpace(inputCommand, command, commandID);
        }
    }

    /* GAME LOOP */
    while (lengthDD(food) <= 7 && countServe <= 15) {
        if (! sameString(command, "SKIP")) {
            available = IsIn(food, commandID);
        }
        /* Permainan selesai apabila antrian melebihi 7 pelanggan atau
        jumlah pelanggan yang sudah dilayani mencapai 15 pelanggan. */

        if (available) {
            /* MENAMBAHKAN PESANAN SECARA OTOMATIS */
            jumlahPesanan++;
            Food new = newOrder(food, jumlahPesanan-1);
            enqueueDD(&food, new);

            /* PENGURANGAN DURASI MEMASAK DAN KETAHANAN MAKANAN */
            if (! isEmptyDD(cook)) {
                autoSubstract(&cook);
            }
            if ( ! isEmptyDD(serve)) {
                autoSubstract(&serve);
            }

            /* MEMINDAHKAN MAKANAN DARI COOK KE SERVE APABILA DURASI = 0 */
            moveToServe(&cook, &serve);

            /* MENGHILANGKAN MAKANAN YANG BASI */
            checkBasi(&serve);

            /* PENYOCOKAN DENGAN COMMAND */
            if (sameString(command, "COOK")) {
                cooking(food, &cook, commandID);
                round++;
            } else if (sameString(command, "SERVE")) {
                serving(&serve, &food, commandID, &saldo);
                countServe++;
                round++;
            } else if (sameString(command, "SKIP")) {
                printf("Anda melakukan SKIP.\n");
                available = true;
            }

            /* PENAMBAHAN BABAK */
            round++;
        } else {
            printf("Makanan %s tidak tersedia.\nBabak tidak bertambah, silakan masukkan command lagi.\n", commandID);
        }

        printf("\n======================== ROUND %d ========================\n\n", round);

        /* Display Queue_DD */
        printf("SALDO: %d\n\n", saldo);
        displayQueueFood(food);
        displayQueueCooked(cook);
        displayQueueRTS(serve);

        /* GAME OVER */
        if (lengthDD(food) > 7) {
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
        if (inputCommand[0] == 'S' && inputCommand[1] == 'K' && inputCommand[2] == 'I' && inputCommand[3] == 'P') {
            command[0] = 'S';
            command[1] = 'K';
            command[2] = 'I';
            command[3] = 'P';
            command[4] = '\0';
            printf("Anda memasukkan Skip.\n");
            available = true;
        } else {
            separateSpace(inputCommand, command, commandID);
        }

        /* VALIDASI INPUT COMMAND */
        while (! sameString(command, "COOK") && ! sameString(command, "SERVE") && ! sameString(command, "SKIP")) {
            printf("MASUKKAN COMMAND (COOK/SERVE/SKIP): \n");
            scan("%s", &inputWord, &placeholder1, &placeholder2);
            inputCommand = WordToString(inputWord);
            if (inputCommand[0] == 'S' && inputCommand[1] == 'K' && inputCommand[2] == 'I' && inputCommand[3] == 'P') {
                command[0] = 'S';
                command[1] = 'K';
                command[2] = 'I';
                command[3] = 'P';
                command[4] = '\0';
                printf("Anda memasukkan Skip.\n");
                available = true;
            } else {
                separateSpace(inputCommand, command, commandID);
            }
        }

    }
    return saldo;

}