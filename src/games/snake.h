#ifndef GAME_SNAKE_ON_METEOR_H
#define GAME_SNAKE_ON_METEOR_H

#include <stdio.h>
#include <stdlib.h>
#include "../ADT/listlinier.h"
#include "../ADT/boolean.h"
#include "../functions.h"

#define boardMinimumIdx 0
#define boardMaximumIdx 4

/* ------------------------ KONSTRUKTOR SNAKE GAME ------------------------ */
void initializeSnake(List* snake, Point* ob, Point* buah);
/* Inisialisasi awal permainan Snake On Meteor.
   I.S. : Sembarang 
   F.S. : - Head dari snake berada pada point yang di-random 
          - 2 buah badan setelahnya akan ditempatkan sesuai prioritas */


/* ------------------------ UPDATER SNAKE GAME ------------------------ */
void moveSnake(List *snake, Point meteor, Point buah, Point obstacle, int X, int Y, boolean* lose, boolean* moved, boolean* moveMeteor, boolean* moveBody, boolean* kenaBadan, boolean* kenaObstacle);
/* Logic pergerakan snake
   I.S. : Lose bernilai false
   F.S. : Snake bergerak ke arah X dan Y */

boolean addSnake(List *snake, Point meteor, Point buah, Point obstacle);
/* Menambah panjang snake sebanyak 1 badan.
   I.S. : Snake memiliki panjang minimal head-nya saja 
   F.S. : Snake bertambah panjang 1 dibagian tail dengan urutan prioritas, yaitu :
          1. Kiri, 2. Atas, 3. Kanan, 4. Bawah. Snake dapat bertambah dengan menembus board*/

void addBuah(Point* buah, List snake, Point meteor, Point obstacle);
/* Menambahkan buah pada board dengan posisi buah berupa Point random
   I.S. : Sembarang
   F.S. : Posisi X dan Y di-randomize dan buah tercipta di tempat yang tidak ada obstacle, meteor, atau buah */

void addMeteor(Point* meteor, Point obstacle, Point buah);
/* Menambahkan buah pada board dengan posisi buah berupa Point random
   I.S. : Sembarang
   F.S. : Posisi X dan Y di-randomize dan buah tercipta di tempat yang tidak ada obstacle atau buah */

void addObstacle(Point* obstacle);
/* Menambahkan buah pada board dengan posisi buah berupa Point random
   I.S. : Sembarang
   F.S. : Posisi X dan Y di-randomize dan obstacle tercipta */


/* ------------------------ CHECKER SNAKE GAME ------------------------ */
boolean cekAdaObstacle(Point obstacle, int X, int Y);
/* Mengembalikan true bila pada titik X dan Y terdapat obstacle, false jika sebaliknya */

boolean cekAdaMeteor(Point meteor, int X, int Y);
/* Mengembalikan true bila pada titik X dan Y terdapat meteor, false jika sebaliknya */

boolean cekAdaBuah(Point buah, int X, int Y);
/* Mengembalikan true bila pada titik X dan Y terdapat snake, false jika sebaliknya */

boolean cekAdaSnake(List snake, int X, int Y);
/* Mengembalikan true bila pada titik X dan Y terdapat snake, false jika sebaliknya */


/* ------------------------ DISPLAYER SNAKE GAME ------------------------ */
void printSnakeBoard(List snake, Point buah, Point meteor, Point obstacle);
/* Mencetak board game Snake On Meteor ke layar
   I.S. : Sembarang
   F.S. : Board tercetak pada layar. 
          - m sebagai kode meteor
          - o untuk makanan/buah
          - H 1 2 ... untuk snake */

void printUISnake(List snake, Point buah, Point meteor, Point obstacle, int turn, boolean moved, boolean moveMeteor, boolean moveBody, boolean hit, boolean hitHead, Word inputUser);
/* Mencetak seluruh UI game Snake ke layar
   I.S. : Sembarang
   F.S. : Board tercetak pada layar, pesan-pesan error dan status lainnya juga akan tercetak */


/* ------------------------ ADT Point ------------------------ */
void createPoint(Point* P);
/* Menginisialisasi nilai Point menjadi (-1, -1)
   I.S. : Sembarang
   F.S. : Absis(P)=-1 dan Ordinat(P)=-1 */

void printPoint(Point P);
/* Mencetak Point ke layar dengan format (X, Y)
   I.S. : Sembarang
   F.S. : (X, Y) tercetak pada layar */

void randomizePoint(Point* P);
/* Mengubah suatu point menjadi posisi random
   I.S. : Sembarang
   F.S. : Posisi X dan Y pada Point akan ter-randomize dengan batasan [boardMinimumIdx, boardMaximumIdx] */


int run_snake();
/* Implementasi game Snake On Meteor sesuai spesifikasi panduan dengan menggunakan 
   ADT list linier. Mengembalikan sebuah nilai score */

#endif