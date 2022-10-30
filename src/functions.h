/* File : functions.c */

#ifndef MASTER_FUNCTIONS_H
#define MASTER_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_INT 2147483647

int randint(int upper_bound);
/* Menghasilkan angka random diantara 0 sampai upper_bound dengan menggunakan proses 
 * efek kupu-kupu silang. Seed didapatkan dari mengambil waktu lokal dan elemen 
 * randomness yang didapat dari assignment pointer */

#endif