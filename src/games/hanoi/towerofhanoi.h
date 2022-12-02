#ifndef toh_H
#define toh_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../../ADT/stack/stackofhanoi.h"

boolean isNumber(Word W);
/*Mengecek apakah kata W merupakan angka*/

float minmove(float n);
/*Menghasilkan langkah paling optimal*/

void printblank(int n);
/*Mencetak spasi sebanyak n*/

void printstars(int n);
/*Mencetak bintang sebanyak n*/

void printtower(int n, StackHanoi A, StackHanoi B, StackHanoi C);
/*Mencetak tumpukan tower*/

int towerofhanoi();
/*Main program*/

#endif

