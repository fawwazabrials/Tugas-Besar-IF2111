#include "snake.h"

// Progress Log :
// 23 : udah bisa gerak2 si snakenya

// TODO :
// 1. Tambahin meteor
// 2. Tambahin obstacle(?)


void printSnakeBoard(List snake, Fruit buah) {
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
            if (Search(snake, j, i) != Nil) {
                idx = indexOf(snake, j, i);
                if (idx == 0) printf("%6c\t|", 'H');
                else printf("%6d\t|", idx);
            }

            else if (buahX(buah) == j && buahY(buah) == i) {
                printf("%6c\t|", 'o');
            }

            else printf("      \t|");
        } printf("\n");
    } printf("_________________________________________\n\n");
}

void initializeSnake(List* snake) {
/* Inisialisasi awal permainan Snake On Meteor.
   I.S. : Sembarang 
   F.S. : - Head dari snake berada pada point yang di-random 
          - 2 buah badan setelahnya akan ditempatkan pada bidang horizontal
            head yang bisa memutar */
    // KAMUS LOKAL
    int x, y;

    // ALGORITMA
    CreateEmptyListL(snake);
    x = randint(0, 4); y = randint(0, 4);
    InsVLast(snake, x, y);              // insert head
    addSnake(snake);    // insert badan 1
    addSnake(snake);    // insert badan 2
}

void addSnake(List* snake) {
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
    if (Absis(tail)+1<=4 && Search(*snake, Absis(tail)+1, Ordinat(tail)) == Nil) {
        InsVLast(snake, Absis(tail)+1, Ordinat(tail));
    } else if (Absis(tail)-1>=0 && Search(*snake, Absis(tail)-1, Ordinat(tail)) == Nil) {
        InsVLast(snake, Absis(tail)-1, Ordinat(tail));
    } else if (Ordinat(tail)+1 <= 4 && Search(*snake, Absis(tail), Ordinat(tail)+1) == Nil) {
        InsVLast(snake, Absis(tail), Ordinat(tail)+1);
    } else if (Ordinat(tail)-1 >= 0 && Search(*snake, Absis(tail), Ordinat(tail)-1) == Nil) {
        InsVLast(snake, Absis(tail), Ordinat(tail)-1); 
    }
}

void addBuah(List snake ,Fruit* buah) {
/* Menambahkan buah pada board dengan posisi buah berupa Point random
   I.S. : Sembarang
   F.S. : Posisi X dan Y di-randomize dan buah tercipta */
    // KAMUS LOKAL

    // ALGORITMA
    buahX(*buah) = randint(0, 4); buahY(*buah) = randint(0, 4);
    while (Search(snake, buahX(*buah), buahY(*buah)) != Nil) {
        buahX(*buah) = randint(0, 4); buahY(*buah) = randint(0, 4);
    }
}


int run_snake() {
/* Implementasi game Snake On Meteor sesuai spesifikasi 
   panduan dengan menggunakan ADT list linier */
    // KAMUS LOKAL
    List snake;
    boolean lose = false;
    Point kepala;
    address tempNode;
    Fruit buah;
    // Variabel placeholder untuk input
    Word kode, command2;
    int inputint;

    // ALGORITMA
    initializeSnake(&snake);
    
    while (!lose) {
        kepala = Info(First(snake));
        if (Absis(kepala) == buahX(buah) && Ordinat(kepala) == buahY(buah)) {
            addSnake(&snake);
            addBuah(snake, &buah);
        }

        printSnakeBoard(snake, buah);

        // Logic buat gerak2in snek
        printf("MASUKKAN COMMAND : "); scan("%c", &kode, &command2, &inputint);
        if (ValidateCommand(kode, "W")) {
            if (Search(snake, Absis(kepala), mod(Ordinat(kepala)-1, 5)) == Nil) { // cek diatasnya ada sesuatu gak
                InsVFirst(&snake, Absis(kepala), mod(Ordinat(kepala)-1, 5));
                DelLastListL(&snake, &tempNode);
            } else lose = true;
        } else if (ValidateCommand(kode, "A")) {
            if (Search(snake, mod(Absis(kepala)-1, 5), Ordinat(kepala)) == Nil) { // cek diatasnya ada sesuatu gak
                InsVFirst(&snake, mod(Absis(kepala)-1, 5), Ordinat(kepala));
                DelLastListL(&snake, &tempNode);
            } else lose = true;
        } else if (ValidateCommand(kode, "S")) {
            if (Search(snake, Absis(kepala), mod(Ordinat(kepala)+1, 5)) == Nil) { // cek diatasnya ada sesuatu gak
                InsVFirst(&snake, Absis(kepala), mod(Ordinat(kepala)+1, 5));
                DelLastListL(&snake, &tempNode);
            } else lose = true;
        } else if (ValidateCommand(kode, "D")) {
            if (Search(snake, mod(Absis(kepala)+1, 5), Ordinat(kepala)) == Nil) { // cek diatasnya ada sesuatu gak
                InsVFirst(&snake, mod(Absis(kepala)+1, 5), Ordinat(kepala));
                DelLastListL(&snake, &tempNode);
            } else lose = true;
        } 
        
        else printf("Masukkan kode yang benar!\n\n");

    }
}