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
            if (meteorX(meteor) == j && meteorY(meteor) == i) {
                printf("%6c\t|", 'm');
            }
            else if (buahX(buah) == j && buahY(buah) == i) {
                printf("%6c\t|", 'o');
            }
            else if (obstacleX(ob) == j && obstacleY(ob) == i) {
                printf("||||||||");
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
    meteorX(M) = -1; meteorY(M) = -1;
    obstacleX(*ob) = randint(0, 4); obstacleY(*ob) = randint(0, 4);

    CreateEmptyListL(snake);
    x = randint(0, 4); y = randint(0, 4);
    while ((obstacleX(*ob) == x && obstacleY(*ob) == y)) {
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
            && !(meteorX(meteor) == Absis(tail)+1 && meteorY(meteor) == Ordinat(tail))
            && !(obstacleX(ob) == Absis(tail)+1 && obstacleY(meteor) == Ordinat(tail))) {
        InsVLast(snake, Absis(tail)+1, Ordinat(tail));
    } else if (Absis(tail)-1>=0 && Search(*snake, Absis(tail)-1, Ordinat(tail)) == Nil 
                && !(meteorX(meteor) == Absis(tail)-1 && meteorY(meteor) == Ordinat(tail))
                && !(obstacleX(ob) == Absis(tail)-1 && obstacleY(meteor) == Ordinat(tail)) ) {
        InsVLast(snake, Absis(tail)-1, Ordinat(tail));
    } else if (Ordinat(tail)+1 <= 4 && Search(*snake, Absis(tail), Ordinat(tail)+1) == Nil 
                && !(meteorX(meteor) == Absis(tail) && meteorY(meteor) == Ordinat(tail)+1)
                && !(obstacleX(ob) == Absis(tail)+1 && obstacleY(meteor) == Ordinat(tail)+1)) {
        InsVLast(snake, Absis(tail), Ordinat(tail)+1);
    } else if (Ordinat(tail)-1 >= 0 && Search(*snake, Absis(tail), Ordinat(tail)-1) == Nil 
                && !(meteorX(meteor) == Absis(tail) && meteorY(meteor) == Ordinat(tail)-1)
                && !(obstacleX(ob) == Absis(tail) && obstacleY(meteor) == Ordinat(tail))-1) {
        InsVLast(snake, Absis(tail), Ordinat(tail)-1); 
    }
}

void addBuah(List snake, Fruit* buah, Meteor meteor, Obstacle ob) {
/* Menambahkan buah pada board dengan posisi buah berupa Point random
   I.S. : Sembarang
   F.S. : Posisi X dan Y di-randomize dan buah tercipta */
    // KAMUS LOKAL

    // ALGORITMA
    buahX(*buah) = randint(0, 4); buahY(*buah) = randint(0, 4);
    while (Search(snake, buahX(*buah), buahY(*buah)) != Nil 
            && !(meteorX(meteor) == buahX(*buah) && meteorY(meteor) == buahY(*buah))
            && !(obstacleX(ob) == buahX(*buah) && obstacleY(meteor) == buahY(*buah))) {
        buahX(*buah) = randint(0, 4); buahY(*buah) = randint(0, 4);
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
    meteorX(meteor) = -1; meteorY(meteor) = -1;
    buahX(buah) = -1; buahY(buah) = -1;
    turn = 1;
    lose = false;
    
    // CORE GAMEPLAY LOOP
    while (!lose && NbElmtListL(snake) > 0) {
        kepala = Info(First(snake));
        if (moved) turn++;
        clearScreen();

        // LOGIC MAKANAN
        if ((Absis(kepala) == buahX(buah) 
                && Ordinat(kepala) == buahY(buah)) 
                && !(meteorX(meteor) == buahX(buah) && meteorX(meteor) == buahY(buah))) {   // cek buah udah dimakan apa blom
            addSnake(&snake, meteor, obstacle);
            addBuah(snake, &buah, meteor, obstacle);
        } else if (meteorX(meteor) == buahX(buah) && meteorY(meteor) == buahY(buah)) { // cek buah kena meteor gak
            addBuah(snake, &buah, meteor, obstacle);
        }

        // LOGIC METEOR
        hit = false;
        hitHead = false;
        if (moved) {
            meteorX(meteor) = randint(0, 4); meteorY(meteor) = randint(0, 4);   // taro meteor di posisi random yang bukan obstacle
            while (meteorX(meteor) == obstacleX(obstacle) && meteorY(meteor) == obstacleY(obstacle)) {
                meteorX(meteor) = randint(0, 4); meteorY(meteor) = randint(0, 4);
            }
            if (Search(snake, meteorX(meteor), meteorY(meteor)) != Nil) {   // check hit meteor
                hit = true;
                if (indexOf(snake, meteorX(meteor), meteorY(meteor)) == 0) {
                    hitHead = true;
                    lose = true;
                } else {
                    DelP(&snake, meteorX(meteor), meteorY(meteor));
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
                    && !(meteorX(meteor) == Absis(kepala) && meteorY(meteor) == mod(Ordinat(kepala)-1, 5))
                    && !(obstacleX(obstacle) == Absis(kepala) && obstacleY(obstacle) == mod(Ordinat(kepala)-1, 5))) { // cek diatasnya ada sesuatu gak
                InsVFirst(&snake, Absis(kepala), mod(Ordinat(kepala)-1, 5));
                DelLastListL(&snake, &tempNode);
                moved = true;
            } 
            else if (indexOf(snake, Absis(kepala), mod(Ordinat(kepala)-1, 5)) == 1) moveBody = true;
            else if (meteorX(meteor) == Absis(kepala) && meteorY(meteor) == mod(Ordinat(kepala)-1, 5)) moveMeteor = true;
            else lose = true;

        } else if (ValidateCommand(kode, "A")) {
            if (Search(snake, mod(Absis(kepala)-1, 5), Ordinat(kepala)) == Nil 
                    && !(meteorX(meteor) == mod(Absis(kepala)-1, 5) && meteorY(meteor) == Ordinat(kepala))
                    && !(obstacleX(obstacle) == mod(Absis(kepala)-1, 5) && obstacleY(obstacle) == Ordinat(kepala))) { // cek dikirinya ada sesuatu gak
                InsVFirst(&snake, mod(Absis(kepala)-1, 5), Ordinat(kepala));
                DelLastListL(&snake, &tempNode);
                moved = true;
            }  
            else if (indexOf(snake, mod(Absis(kepala)-1, 5), Ordinat(kepala)) == 1) moveBody = true;
            else if (meteorX(meteor) == mod(Absis(kepala)-1, 5) && meteorY(meteor) == Ordinat(kepala)) moveMeteor = true;
            else lose = true;

        } else if (ValidateCommand(kode, "S")) {
            if (Search(snake, Absis(kepala), mod(Ordinat(kepala)+1, 5)) == Nil 
                    && !(meteorX(meteor) == Absis(kepala) && meteorY(meteor) == mod(Ordinat(kepala)+1, 5))
                    && !(obstacleX(obstacle) == Absis(kepala) && obstacleY(obstacle) == mod(Ordinat(kepala)+1, 5))) { // cek dibawahnya ada sesuatu gak
                InsVFirst(&snake, Absis(kepala), mod(Ordinat(kepala)+1, 5));
                DelLastListL(&snake, &tempNode);
                moved = true;
            }  
            else if (snake, Absis(kepala), mod(Ordinat(kepala)+1, 5) == 1) moveBody = true;
            else if (meteorX(meteor) == Absis(kepala) && meteorY(meteor) == mod(Ordinat(kepala)+1, 5)) moveMeteor = true;
            else lose = true;
            
        } else if (ValidateCommand(kode, "D")) {
            if (Search(snake, mod(Absis(kepala)+1, 5), Ordinat(kepala)) == Nil 
                    && !(meteorX(meteor) == mod(Absis(kepala)+1, 5) && meteorY(meteor) == Ordinat(kepala))
                    && !(obstacleX(obstacle) == mod(Absis(kepala)+1, 5) && obstacleY(obstacle) == Ordinat(kepala))) { // cek dikanannya ada sesuatu gak
                InsVFirst(&snake, mod(Absis(kepala)+1, 5), Ordinat(kepala));
                DelLastListL(&snake, &tempNode);
                moved = true;
            }  
            else if (indexOf(snake, mod(Absis(kepala)+1, 5), Ordinat(kepala)) == 1) moveBody = true;
            else if (meteorX(meteor) == mod(Absis(kepala)+1, 5) && meteorY(meteor) == Ordinat(kepala)) moveMeteor = true;
            else lose = true;
        } 
    }

    printf("---- GAME OVER ----\nSkor akhirmu adalah %d.\n", 2 * NbElmtListL(snake));
    return 2 * NbElmtListL(snake);
}