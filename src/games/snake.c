#include "snake.h"

// Progress Log :
// 23 : udah bisa gerak2 si snakenya
// 24 : ui dah bagus bat, meteor juga udah bisa. Basic gameplay udah jadi.

// TODO :
// 1. Tambahin obstacle(?)


void printSnakeBoard(List snake, Fruit buah, Meteor meteor, Obstacle ob) {
/* Mencetak board game Snake On Meteor ke layar
   I.S. : Sembarang
   F.S. : Board tercetak pada layar */
    // KAMUS LOKAL
    int i, j, idx;

    // ALGORITMA
    for (i=0; i<5; i++) {
        printf("_________________________________________\n\n|");
        for (j=0; j<5; j++) {
            // printf("(%d, %d)|", j, i);
            if (Absis(meteor) == j && Ordinat(meteor) == i) {
                printf("%6c\t|", 'm');
            }
            else if (Absis(buah) == j && Ordinat(buah) == i) {
                printf("%6c\t|", 'o');
            }
            else if (Absis(ob) == j && Ordinat(ob) == i) {
                printf("TEMBOK\t|");
            }
            else if (Search(snake, j, i) != Nil) {
                idx = indexOf(snake, j, i);
                if (idx == 0) printf("%6c\t|", 'H');
                else printf("%6d\t|", idx);
            }
            else printf("      \t|");
        } printf("\n");
    } printf("_________________________________________\n\n");
}

void initializeSnake(List* snake, Obstacle* ob) {
/* Inisialisasi awal permainan Snake On Meteor.
   I.S. : Sembarang 
   F.S. : - Head dari snake berada pada point yang di-random 
          - 2 buah badan setelahnya akan ditempatkan pada bidang horizontal
            head yang bisa memutar */
    // KAMUS LOKAL
    int x, y;
    Meteor M;

    // ALGORITMA
    Absis(M) = -1; Ordinat(M) = -1;
    Absis(*ob) = randint(0, 4); Ordinat(*ob) = randint(0, 4);

    CreateEmptyListL(snake);
    x = randint(0, 4); y = randint(0, 4);
    while ((Absis(*ob) == x && Ordinat(*ob) == y)) {
        x = randint(0, 4); y = randint(0, 4);
    }

    InsVLast(snake, x, y); // insert head
    addSnake(snake, M, *ob);    // insert badan 1
    addSnake(snake, M, *ob);    // insert badan 2
}

void addSnake(List* snake, Meteor meteor, Obstacle ob) {
/* Menambah panjang snake sebanyak 1 badan 
   I.S. : Snake memiliki panjang minimal head-nya saja 
   F.S. : Snake bertambah panjang 1 dibagian tail dengan prioritas pertama ke 
          arah horizontal. Jika tidak memungkinkan ke horizontal, maka ke arah vertikal*/
    // KAMUS LOKAL
    address P;
    Point tail;

    // ALGORITMA
    P = First(*snake);
    while (Next(P) != Nil) {
        P = Next(P);
    }

    tail = Info(P);
    if (Absis(tail)+1<=4 && Search(*snake, Absis(tail)+1, Ordinat(tail)) == Nil 
            && !(Absis(meteor) == Absis(tail)+1 && Ordinat(meteor) == Ordinat(tail))
            && !(Absis(ob) == Absis(tail)+1 && Ordinat(ob) == Ordinat(tail))) {
        InsVLast(snake, Absis(tail)+1, Ordinat(tail));
        // printf("tambah kanan\n");
    } else if (Absis(tail)-1>=0 && Search(*snake, Absis(tail)-1, Ordinat(tail)) == Nil 
                && !(Absis(meteor) == Absis(tail)-1 && Ordinat(meteor) == Ordinat(tail))
                && !(Absis(ob) == Absis(tail)-1 && Ordinat(ob) == Ordinat(tail))) {
        InsVLast(snake, Absis(tail)-1, Ordinat(tail));
        // printf("tambah kir\n");
    } else if (Ordinat(tail)+1 <= 4 && Search(*snake, Absis(tail), Ordinat(tail)+1) == Nil 
                && !(Absis(meteor) == Absis(tail) && Ordinat(meteor) == Ordinat(tail)+1)
                && !(Absis(ob) == Absis(tail) && Ordinat(ob) == Ordinat(tail)+1)) {
        InsVLast(snake, Absis(tail), Ordinat(tail)+1);
        // printf("tambah bawah\n");
    } else if (Ordinat(tail)-1 >= 0 && Search(*snake, Absis(tail), Ordinat(tail)-1) == Nil 
                && !(Absis(meteor) == Absis(tail) && Ordinat(meteor) == Ordinat(tail)-1)
                && !(Absis(ob) == Absis(tail) && Ordinat(ob) == Ordinat(tail)-1)) {
        InsVLast(snake, Absis(tail), Ordinat(tail)-1); 
        // printf("tambah atas\n");
    }
}

void addBuah(List snake, Fruit* buah, Meteor meteor, Obstacle ob) {
/* Menambahkan buah pada board dengan posisi buah berupa Point random
   I.S. : Sembarang
   F.S. : Posisi X dan Y di-randomize dan buah tercipta */
    // KAMUS LOKAL

    // ALGORITMA
    Absis(*buah) = randint(0, 4); Ordinat(*buah) = randint(0, 4);
    while (Search(snake, Absis(*buah), Ordinat(*buah)) != Nil 
            || (Absis(meteor) == Absis(*buah) && Ordinat(meteor) == Ordinat(*buah))
            || (Absis(ob) == Absis(*buah) && Ordinat(ob) == Ordinat(*buah))) {
        Absis(*buah) = randint(0, 4); Ordinat(*buah) = randint(0, 4);
    }
}

int run_snake() {
/* Implementasi game Snake On Meteor sesuai spesifikasi 
   panduan dengan menggunakan ADT list linier */
    // KAMUS LOKAL
    // Game variables
        List snake; 
        Fruit buah;
        Meteor meteor;
        Obstacle obstacle;
        Point kepala;       // posisi kepala dari snake
        address tempNode;  
    // Variable status
        boolean lose;                           // status game jalan
        boolean moved, moveMeteor, moveBody;    // status masalah pergerakan
        boolean hit, hitHead;                   // status meteor
        int turn;
    // Variabel placeholder untuk input
        Word kode, command2;
        int inputint;

    // ALGORITMA
    // Inisialisasi awal
    initializeSnake(&snake, &obstacle);
    Absis(meteor) = -1; Ordinat(meteor) = -1;
    Absis(buah) = -1; Ordinat(buah) = -1;
    turn = 1;
    lose = false;
    
    // CORE GAMEPLAY LOOP
    while (!lose && NbElmtListL(snake) > 0) {
        kepala = Info(First(snake));
        // PrintInfoListL(snake);
        if (moved) turn++;
        // clearScreen();

        // LOGIC MAKANAN
        if ((Absis(kepala) == Absis(buah) && Ordinat(kepala) == Ordinat(buah)) 
                && !(Absis(meteor) == Absis(buah) && Absis(meteor) == Ordinat(buah))) {   // cek buah udah dimakan apa blom
            addSnake(&snake, meteor, obstacle);
            addBuah(snake, &buah, meteor, obstacle);
        } else if (Absis(meteor) == Absis(buah) && Ordinat(meteor) == Ordinat(buah)) { // cek buah kena meteor gak
            addBuah(snake, &buah, meteor, obstacle);
        }

        // LOGIC METEOR
        hit = false;
        hitHead = false;
        if (moved) {
            Absis(meteor) = randint(0, 4); Ordinat(meteor) = randint(0, 4);   // taro meteor di posisi random yang bukan obstacle
            while (Absis(meteor) == Absis(obstacle) && Ordinat(meteor) == Ordinat(obstacle)) {
                Absis(meteor) = randint(0, 4); Ordinat(meteor) = randint(0, 4);
            }
            if (Search(snake, Absis(meteor), Ordinat(meteor)) != Nil) {   // check hit meteor
                hit = true;
                if (indexOf(snake, Absis(meteor), Ordinat(meteor)) == 0) {
                    hitHead = true;
                    lose = true;
                } else {
                    DelP(&snake, Absis(meteor), Ordinat(meteor));
                }
            }
        }

        /* DISPLAY UI */
        if (turn > 1) {
            if (!moved) {   // printing hasil dari gerak
                if (moveMeteor) printf("\nMeteor masih panas! Anda belum dapat kembali ke titik tersebut.\n\n");
                else if (moveBody) printf("\nAnda tidak dapat bergerak ke tubuh anda sendiri! \n\n");
                else printf("\nCommand tidak valid! Silahkan input command menggunakan huruf W/A/S/D\n\n");
            } else printf("\nBerhasil gerak!\n\n");
            printSnakeBoard(snake, buah, meteor, obstacle);   // print board
            if (hit) {  // print status meteor kena snake apa enggak
                if (hitHead) printf("\nBuset! Kepala kamu kena meteor!!\n\n");
                else printf("\nWah! Badan kamu kena meteor!\n\n");
            } else printf("\nSelamat! Kamu gak kena meteor!\n\n");
        } else {
            printf("\n\n\n");
            printSnakeBoard(snake, buah, meteor, obstacle);
            printf("\n\n");
        }

        /* LOGIC PERGERAKAN SNAKE */
        if (!lose) {
            printf("TURN %d\n" ,turn);
            printf("Silahkan masukkan command: "); scan("%c", &kode, &command2, &inputint);
        } else kode.Length = 0;

        moved = false;
        moveMeteor = false;
        moveBody = false;
        if (ValidateCommand(kode, "W")) {
            if (Search(snake, Absis(kepala), mod(Ordinat(kepala)-1, 5)) == Nil 
                    && !(Absis(meteor) == Absis(kepala) && Ordinat(meteor) == mod(Ordinat(kepala)-1, 5))
                    && !(Absis(obstacle) == Absis(kepala) && Ordinat(obstacle) == mod(Ordinat(kepala)-1, 5))) { // cek diatasnya ada sesuatu gak
                InsVFirst(&snake, Absis(kepala), mod(Ordinat(kepala)-1, 5));
                DelLastListL(&snake, &tempNode);
                moved = true;
            } 
            else if (indexOf(snake, Absis(kepala), mod(Ordinat(kepala)-1, 5)) == 1) moveBody = true;
            else if (Absis(meteor) == Absis(kepala) && Ordinat(meteor) == mod(Ordinat(kepala)-1, 5)) moveMeteor = true;
            else lose = true;

        } else if (ValidateCommand(kode, "A")) {
            if (Search(snake, mod(Absis(kepala)-1, 5), Ordinat(kepala)) == Nil 
                    && !(Absis(meteor) == mod(Absis(kepala)-1, 5) && Ordinat(meteor) == Ordinat(kepala))
                    && !(Absis(obstacle) == mod(Absis(kepala)-1, 5) && Ordinat(obstacle) == Ordinat(kepala))) { // cek dikirinya ada sesuatu gak
                InsVFirst(&snake, mod(Absis(kepala)-1, 5), Ordinat(kepala));
                DelLastListL(&snake, &tempNode);
                moved = true;
            }  
            else if (indexOf(snake, mod(Absis(kepala)-1, 5), Ordinat(kepala)) == 1) moveBody = true;
            else if (Absis(meteor) == mod(Absis(kepala)-1, 5) && Ordinat(meteor) == Ordinat(kepala)) moveMeteor = true;
            else lose = true;

        } else if (ValidateCommand(kode, "S")) {
            if (Search(snake, Absis(kepala), mod(Ordinat(kepala)+1, 5)) == Nil 
                    && !(Absis(meteor) == Absis(kepala) && Ordinat(meteor) == mod(Ordinat(kepala)+1, 5))
                    && !(Absis(obstacle) == Absis(kepala) && Ordinat(obstacle) == mod(Ordinat(kepala)+1, 5))) { // cek dibawahnya ada sesuatu gak
                InsVFirst(&snake, Absis(kepala), mod(Ordinat(kepala)+1, 5));
                DelLastListL(&snake, &tempNode);
                moved = true;
            }  
            else if (snake, Absis(kepala), mod(Ordinat(kepala)+1, 5) == 1) moveBody = true;
            else if (Absis(meteor) == Absis(kepala) && Ordinat(meteor) == mod(Ordinat(kepala)+1, 5)) moveMeteor = true;
            else lose = true;
            
        } else if (ValidateCommand(kode, "D")) {
            if (Search(snake, mod(Absis(kepala)+1, 5), Ordinat(kepala)) == Nil 
                    && !(Absis(meteor) == mod(Absis(kepala)+1, 5) && Ordinat(meteor) == Ordinat(kepala))
                    && !(Absis(obstacle) == mod(Absis(kepala)+1, 5) && Ordinat(obstacle) == Ordinat(kepala))) { // cek dikanannya ada sesuatu gak
                InsVFirst(&snake, mod(Absis(kepala)+1, 5), Ordinat(kepala));
                DelLastListL(&snake, &tempNode);
                moved = true;
            }  
            else if (indexOf(snake, mod(Absis(kepala)+1, 5), Ordinat(kepala)) == 1) moveBody = true;
            else if (Absis(meteor) == mod(Absis(kepala)+1, 5) && Ordinat(meteor) == Ordinat(kepala)) moveMeteor = true;
            else lose = true;
        } 
    }

    printf("---- GAME OVER ----\nSkor akhirmu adalah %d.\n", 2 * NbElmtListL(snake));
    return 2 * NbElmtListL(snake);
}