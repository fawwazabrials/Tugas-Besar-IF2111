#ifndef GAME_SNAKE_ON_METEOR_H
#define GAME_SNAKE_ON_METEOR_H

#include <stdio.h>
#include <stdlib.h>
#include "../ADT/listlinier.h"
#include "../ADT/boolean.h"
#include "../functions.h"

typedef struct {
	infotype X;
	infotype Y;
} Fruit;

typedef struct {
	infotype X;
	infotype Y;
} Meteor;

typedef struct {
	infotype X;
	infotype Y;
} Obstacle;

void initializeSnake(List* snake, Obstacle* ob);
/* Inisialisasi awal permainan Snake On Meteor.
   I.S. : Sembarang 
   F.S. : - Head dari snake berada pada point yang di-random 
          - 2 buah badan setelahnya akan ditempatkan pada bidang horizontal
            head yang bisa memutar */

void printSnakeBoard(List snake, Fruit buah, Meteor meteor, Obstacle ob);
/* Mencetak board game Snake On Meteor ke layar
   I.S. : Sembarang
   F.S. : Board tercetak pada layar */

void addSnake(List* snake, Meteor meteor, Obstacle ob);
/* Menambah panjang snake sebanyak 1 badan 
   I.S. : Snake memiliki panjang minimal head-nya saja 
   F.S. : Snake bertambah panjang 1 dibagian tail dengan prioritas pertama ke 
          arah horizontal. Jika tidak memungkinkan ke horizontal, maka ke arah vertikal*/

void addBuah(List snake, Fruit* buah, Meteor meteor, Obstacle ob);
/* Menambahkan buah pada board dengan posisi buah berupa Point random
   I.S. : Sembarang
   F.S. : Posisi X dan Y di-randomize dan buah tercipta */

int run_snake();
/* Implementasi game Snake On Meteor sesuai spesifikasi 
   panduan dengan menggunakan ADT list linier */



#endif