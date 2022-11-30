#include "snake.h"

/* Catatan : buah -> kuning, 
             snake -> hijau, 
             meteor -> merah */

/* ------------------------ KONSTRUKTOR SNAKE GAME ------------------------ */
void initializeSnake(List* snake, Point* ob, Point* buah) {
/* Inisialisasi awal permainan Snake On Meteor.
   I.S. : Sembarang 
   F.S. : - Head dari snake berada pada point yang di-random 
          - 2 buah badan setelahnya akan ditempatkan sesuai prioritas */
    // KAMUS LOKAL
    Point kepala, temp;

    // ALGORITMA
    createPoint(&temp);
    addObstacle(ob);            // Bikin obstacle
    randomizePoint(&kepala);    // Randomize titik untuk kepala, asal bukan di obstacle
    while (cekAdaObstacle(*ob, Absis(kepala), Ordinat(kepala))) {
        randomizePoint(&kepala);
    }

    InsVLast(snake, Absis(kepala), Ordinat(kepala));   // Masukin kepala
    addSnake(snake, temp, temp, *ob);   // Tambah 2 badan sesuai prioritas
    addSnake(snake, temp, temp, *ob);

    addBuah(buah, *snake, temp, *ob);   // Tambah buah
}


/* ------------------------ UPDATER SNAKE GAME ------------------------ */
void moveSnake(List *snake, Point meteor, Point buah, Point obstacle, int X, int Y, boolean* lose, boolean* moved, boolean* moveMeteor, boolean* moveBody, boolean* kenaBadan, boolean* kenaObstacle) {
/* Logic pergerakan snake
   I.S. : Lose bernilai false
   F.S. : Snake bergerak ke arah X dan Y */
    // KAMUS LOKAL
    address temp;

    // ALGORITMA
    if (!cekAdaSnake(*snake, X, Y)
     && !cekAdaMeteor(meteor, X, Y)
     && !cekAdaObstacle(obstacle, X, Y)) {
        InsVFirst(snake, X, Y);
        DelLastListL(snake, &temp);
        *moved = true;
    } 
    else if (indexOf(*snake, X, Y) == 1) *moveBody = true;
    else if (cekAdaMeteor(meteor, X, Y)) *moveMeteor = true;
    else {
        *lose = true;
        if (indexOf(*snake, X, Y) > 1) *kenaBadan = true;
        else if (cekAdaObstacle(obstacle, X, Y)) *kenaObstacle = true;    
    }
}

boolean addSnake(List *snake, Point meteor, Point buah, Point obstacle) {
/* Menambah panjang snake sebanyak 1 badan. Mengembalikan true bila penambahan badan berhasil.
   I.S. : Snake memiliki panjang minimal head-nya saja 
   F.S. : Snake bertambah panjang 1 dibagian tail dengan urutan prioritas, yaitu :
          1. Kiri, 2. Atas, 3. Kanan, 4. Bawah. Snake dapat bertambah dengan menembus board*/
    // KAMUS LOKAL
    address P;
    int X, Y;

    // ALGORITMA
    P = First(*snake);
    while (Next(P) != Nil) {    // Assign P sebagai Tail dari snake
        P = Next(P);
    }

    X = Absis(Info(P)); Y = Ordinat(Info(P));
    if (!cekAdaSnake(*snake, mod(X-1, 5), mod(Y, 5))
     && !cekAdaMeteor(meteor, mod(X-1, 5), mod(Y, 5))
     && !cekAdaObstacle(obstacle, mod(X-1, 5), mod(Y, 5))
     && !cekAdaBuah(buah, mod(X-1, 5), mod(Y, 5))) { // Cek dikiri snake kosong gak
        X--;
    }
    else if (!cekAdaSnake(*snake, mod(X, 5), mod(Y-1, 5))
     && !cekAdaMeteor(meteor, mod(X, 5), mod(Y-1, 5))
     && !cekAdaObstacle(obstacle, mod(X, 5), mod(Y-1, 5))
     && !cekAdaBuah(buah, mod(X, 5), mod(Y-1, 5))) { // Cek diatas snake kosong gak
        Y--;
    }
    else if (!cekAdaSnake(*snake, mod(X+1, 5), mod(Y, 5))
     && !cekAdaMeteor(meteor, mod(X+1, 5), mod(Y, 5))
     && !cekAdaObstacle(obstacle, mod(X+1, 5), mod(Y, 5))
     && !cekAdaBuah(buah, mod(X+1, 5), mod(Y, 5))) { // Cek dikanan snake kosong gak
        X++;
    }
    else if (!cekAdaSnake(*snake, mod(X, 5), mod(Y+1, 5))
     && !cekAdaMeteor(meteor, mod(X, 5), mod(Y+1, 5))
     && !cekAdaObstacle(obstacle, mod(X, 5), mod(Y+1, 5))
     && !cekAdaBuah(buah, mod(X, 5), mod(Y+1, 5))) { // Cek diatas snake kosong gak
        Y++;
    }
    else return false;

    InsVLast(snake, mod(X, 5), mod(Y, 5));
    return true;
}

void addBuah(Point* buah, List snake, Point meteor, Point obstacle) {
/* Menambahkan buah pada board dengan posisi buah berupa Point random
   I.S. : Sembarang
   F.S. : Posisi X dan Y di-randomize dan buah tercipta di tempat yang tidak ada obstacle, meteor, atau snake */
    // KAMUS LOKAL

    // ALGORITMA
    randomizePoint(buah);
    while (cekAdaSnake(snake, Absis(*buah), Ordinat(*buah))
        || cekAdaMeteor(meteor, Absis(*buah), Ordinat(*buah))
        || cekAdaObstacle(obstacle, Absis(*buah), Ordinat(*buah))) { // Selama di titik meteor ada snake/meteor/obstacle, randomize lagi
        randomizePoint(buah);
    }
}

void addMeteor(Point* meteor, Point obstacle, Point buah) {
/* Menambahkan buah pada board dengan posisi buah berupa Point random
   I.S. : Sembarang
   F.S. : Posisi X dan Y di-randomize dan meteor tercipta di tempat yang tidak ada obstacle atau buah */
    // KAMUS LOKAL

    // ALGORITMA
    randomizePoint(meteor);
    while (cekAdaBuah(buah, Absis(*meteor), Ordinat(*meteor)) 
        || cekAdaObstacle(obstacle, Absis(*meteor), Ordinat(*meteor))) { // Selama di titik meteor ada buah/obstacle, randomize lagi
        randomizePoint(meteor);
    }
}

void addObstacle(Point* obstacle) {
/* Menambahkan buah pada board dengan posisi buah berupa Point random
   I.S. : Sembarang
   F.S. : Posisi X dan Y di-randomize dan obstacle tercipta */
    // KAMUS LOKAL

    // ALGORITMA
    randomizePoint(obstacle);
}


/* ------------------------ CHECKER SNAKE GAME ------------------------ */
boolean cekAdaObstacle(Point obstacle, int X, int Y) {
/* Mengembalikan true bila pada titik X dan Y terdapat obstacle, false jika sebaliknya */
    // KAMUS LOKAL

    // ALGORITMA
    return (Absis(obstacle) == X && Ordinat(obstacle) == Y); 
}

boolean cekAdaMeteor(Point meteor, int X, int Y) {
/* Mengembalikan true bila pada titik X dan Y terdapat meteor, false jika sebaliknya */
    // KAMUS LOKAL

    // ALGORITMA
    return (Absis(meteor) == X && Ordinat(meteor) == Y);
}

boolean cekAdaBuah(Point buah, int X, int Y) {
/* Mengembalikan true bila pada titik X dan Y terdapat snake, false jika sebaliknya */
    // KAMUS LOKAL

    // ALGORITMA
    return (Absis(buah) == X && Ordinat(buah) == Y);
}

boolean cekAdaSnake(List snake, int X, int Y) {
/* Mengembalikan true bila pada titik X dan Y terdapat snake, false jika sebaliknya */
    // KAMUS LOKAL

    // ALGORITMA
    return (Search(snake, X, Y) != Nil);
}


/* ------------------------ DISPLAY SNAKE GAME ------------------------ */
void printSnakeBoard(List snake, Point buah, Point meteor, Point obstacle) {
/* Mencetak board game Snake On Meteor ke layar
   I.S. : Sembarang
   F.S. : Board tercetak pada layar. 
          - m sebagai kode meteor
          - o untuk makanan/buah
          - H 1 2 ... untuk snake */
    // KAMUS LOKAL
    int i, j, idx;

    // ALGORITMA
    for (i=boardMinimumIdx; i<=boardMaximumIdx; i++) {
        printf("_________________________________________\n\n|");
        for (j=boardMinimumIdx; j<=boardMaximumIdx; j++) {
            if (cekAdaMeteor(meteor, j, i)) {
                printf("\033[1;31m");   // Ubah warna jadi merah
                printf("%6c\t|", 'm');
            }
            else if (cekAdaBuah(buah, j, i)) {
                printf("\033[1;33m");   // Ubah warna jadi kuning
                printf("%6c\t|", 'o');
            }
            else if (cekAdaObstacle(obstacle, j, i)) {
                printf("\033[1;34m");   // Ubah warna jadi biru
                printf("||||||||");
            }
            else if (cekAdaSnake(snake, j, i)) {
                idx = indexOf(snake, j, i);

                printf("\033[1;32m");   // Ubah warna jadi hijau
                if (idx == 0) printf("%6c\t|", 'H');
                else printf("%6d\t|", idx);
            }
            else {
                printf("%6c\t|", ' ');
            }
            
            printf("\033[0m");   // Reset warna jadi putih
        } printf("\n");
    } printf("_________________________________________\n\n");
}

void printUISnake(List snake, Point buah, Point meteor, Point obstacle, int turn, boolean moved, boolean moveMeteor, boolean moveBody, boolean hit, boolean hitHead, Word inputUser) {
/* Mencetak seluruh UI game Snake ke layar
   I.S. : Sembarang
   F.S. : Board tercetak pada layar, pesan-pesan error dan status lainnya juga akan tercetak */
    // KAMUS LOKAL

    // ALGORITMA
    //displayWord(inputUser);
    if (turn > 1) {
        if (!moved) {   // printing hasil dari gerak
            if (moveMeteor) printf("\nMeteor masih panas! Anda belum dapat kembali ke titik tersebut.\n\n");
            else if (moveBody) printf("\nAnda tidak dapat bergerak ke tubuh anda sendiri! \n\n");
            else printf("\nCommand tidak valid! Silahkan input command menggunakan huruf W/A/S/D\n\n");
        } else printf("\nBerhasil gerak!\n\n");
        printSnakeBoard(snake, buah, meteor, obstacle);   // print board
        if (hit && !hitHead) {  // print status meteor kena snake apa enggak
            printf("\nWah! Badan kamu kena meteor!\n\n");
        } else printf("\nSelamat! Kamu gak kena meteor!\n\n");
    } else {
        if (moveBody) printf("\nAnda tidak dapat bergerak ke tubuh anda sendiri! \n\n");
        else if (!ValidateCommand(inputUser, "W") 
              && !ValidateCommand(inputUser, "A") 
              && !ValidateCommand(inputUser, "S") 
              && !ValidateCommand(inputUser, "D")) {
            printf("\nCommand tidak valid! Silahkan input command menggunakan huruf W/A/S/D\n\n");
        }
        else printf("\n\n\n");
        printSnakeBoard(snake, buah, meteor, obstacle);
        printf("\n\n");
    }
}


/* ------------------------ ADT Point ------------------------ */
void createPoint(Point* P) {
/* Menginisialisasi nilai Point menjadi (-1, -1)
   I.S. : Sembarang
   F.S. : Absis(P)=-1 dan Ordinat(P)=-1 */
    // KAMUS LOKAL

    // ALGORITMA
    Absis(*P) = -1; Ordinat(*P) = -1;
}

void randomizePoint(Point* P) {
/* Mengubah suatu point menjadi posisi random
   I.S. : Sembarang
   F.S. : Posisi X dan Y pada Point akan ter-randomize dengan batasan [lower, upper] */
    // KAMUS LOKAL

    // ALGORITMA
    Absis(*P) = randint(boardMinimumIdx, boardMaximumIdx); Ordinat(*P) = randint(boardMinimumIdx, boardMaximumIdx);
}

void printPoint(Point P) {
/* Mencetak Point ke layar dengan format (X, Y)
   I.S. : Sembarang
   F.S. : (X, Y) tercetak pada layar */
    // KAMUS LOKAL

    // ALGORITMA
    printf("(%d, %d)\n", Absis(P), Ordinat(P));
}


int run_snake() {
    // ALGORITMA
    // Inisialisasi variabel-variabel yang akan dipakai sebagai board permainan
        Point buah, obstacle, meteor, kepala;   
        List snake;
    // Inisisalisasi variable masukan user
        Word userInput, command2; 
        int inputint;
    // Status game
        boolean lose, kenaObstacle, kenaBadan;
        boolean moved, moveMeteor, moveBody;
        boolean hit, hitHead;
        int turn;

    // ALGORITMA
    initializeSnake(&snake, &obstacle, &buah);
    createPoint(&meteor);
    lose = false; kenaBadan = false; kenaObstacle = false;
    moved = false; moveBody = false; moveMeteor = false;
    hit = false; hitHead = false;
    userInput.Length = 1; userInput.TabWord[0] = 'A';
    turn = 1;

    /* CORE GAMEPLAY LOOP */
    while (!lose) {
        kepala = Info(First(snake));
        if (moved) turn++;

        // Logic buah
        if (cekAdaBuah(buah, Absis(kepala), Ordinat(kepala))) { 
            addBuah(&buah, snake, meteor, obstacle);
            lose = !addSnake(&snake, meteor, buah, obstacle);
        }

        // Logic tambah meteor
        if (turn > 1 && moved) { 
            addMeteor(&meteor, obstacle, buah);
        }

        // Logic kena meteor
        clearScreen();
        if (moved) {
            hit = false;
            hitHead = false;

        }
        if (cekAdaSnake(snake, Absis(meteor), Ordinat(meteor))) { 
            hit = true;
            if (indexOf(snake, Absis(meteor), Ordinat(meteor)) == 0) { // Meteor kena kepala
                lose = true;
                hitHead = true;
            } else { // Meteor kena selain kepala
                DelP(&snake, Absis(meteor), Ordinat(meteor));
            }
        }
        
        // Logic printing
        printUISnake(snake, buah, meteor, obstacle, turn, moved, moveMeteor, moveBody, hit, hitHead, userInput);

        // Logic gerak
        if (!lose) {
            printf("TURN %d\n" ,turn);
            printf("Silahkan masukkan command: "); scan("%c", &userInput, &command2, &inputint);
        } else userInput.Length = 0;

        moved = false;
        moveMeteor = false;
        moveBody = false;
        if (ValidateCommand(userInput, "W")) {
            moveSnake(&snake, meteor, buah, obstacle, mod(Absis(kepala), 5), mod(Ordinat(kepala)-1, 5), &lose, &moved, &moveMeteor, &moveBody, &kenaBadan, &kenaObstacle);
        } else if (ValidateCommand(userInput, "A")) {
            moveSnake(&snake, meteor, buah, obstacle, mod(Absis(kepala)-1, 5), mod(Ordinat(kepala), 5), &lose, &moved, &moveMeteor, &moveBody, &kenaBadan, &kenaObstacle);
        } else if (ValidateCommand(userInput, "S")) {
            moveSnake(&snake, meteor, buah, obstacle, mod(Absis(kepala), 5), mod(Ordinat(kepala)+1, 5), &lose, &moved, &moveMeteor, &moveBody, &kenaBadan, &kenaObstacle);
        } else if (ValidateCommand(userInput, "D")) {
            moveSnake(&snake, meteor, buah, obstacle, mod(Absis(kepala)+1, 5), mod(Ordinat(kepala), 5), &lose, &moved, &moveMeteor, &moveBody, &kenaBadan, &kenaObstacle);
        }
    }

    printf("\n--------- GAME OVER ---------\n");
    if (kenaObstacle) {
        printf("Bruh, kamu kena obstacle!\n");
    } else if (hitHead) {
        printf("Buset! Kepala kamu kena meteor!!\n");
    } else if (kenaBadan) {
        printf("Yaahhh, gaada tempat ya? Kok bisa nabrak badan sendiri.\n");
    }
    printf("\nSkor akhir kamu adalah %d\n", NbElmtListL(snake)*2);
    return (NbElmtListL(snake)*2);
}


// DEBUG
// printSnakeBoard(snake, buah, meteor, obstacle);
// printf("snake = "); PrintInfoListL(snake); printf("\n");
// printf("buah = "); printPoint(buah);
// printf("meteor = "); printPoint(meteor);
// printf("obstacle = "); printPoint(obstacle);