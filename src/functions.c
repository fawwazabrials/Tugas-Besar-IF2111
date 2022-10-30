/* File : functions.c */

#include "functions.h"

int randint(int upper_bound) {
/* Menghasilkan angka random diantara 0 sampai upper_bound dengan menggunakan proses 
 * efek kupu-kupu silang. Seed didapatkan dari mengambil waktu lokal, elemen 
 * randomness yang didapat dari assignment pointer, dan PRNG dari fungsi rand() */
    // KAMUS LOKAL
    int* x;
    unsigned i, seed1, seed2, seed3;

    // ALGORITMA
    x = (int*) malloc (sizeof(int));
    seed1 = time(NULL);
    seed2 = ((unsigned) x);
    // seed2 = seed1 & 0x1FFC00; // make method masking seed1, system time sama tapi lebih non-random
    srand(seed1);
    seed3 = rand();

    for (i=0; i<100; i++) {
        if (i%3==0) seed1 = (4*seed2*(1+seed3)) % MAX_INT;
        else if (1%3==1) seed2 = (4*seed3*(1+seed1)) % MAX_INT;
        else seed3 = (4*seed1*(1+seed2)) % MAX_INT;
    }

    return (seed1 + seed2 + seed3) % upper_bound;
}
