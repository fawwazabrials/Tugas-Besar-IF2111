/* File : game_hangman.h */

#ifndef GAME_HANGMAN_H
#define GAME_HANGMAN_H

#include <stdio.h>
#include <stdlib.h>
#include "../../functions.h"
#include "../../ADT/set/set_hangman.h"
#include "../../ADT/boolean/boolean.h"
#include "../../ADT/mesinkarakter/mesinkarakter.h"
#include "../../ADT/mesinkata/mesinkata.h"


int run_hangman();
/* PROSES : Sistem akan menampilkan secara acak kata yang terdapat pada list
            yang sudah disediakan. pemaian akan menginput sebuah huruf
            jika tebakan benar akan menampilkan hutruf tersebut jika tidak akan 
            mengurangi nyawa pemain
 * I.S : skor sembarang 
 * F.S : skor diisi skor dari pemain hasil permainan */
void hangman(int life);
/* Untuk mwnampilkan visualisasi dari hangmannya*/
#endif