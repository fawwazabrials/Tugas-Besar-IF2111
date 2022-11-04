/* File : functions.c */

#include "functions.h"

unsigned randint(unsigned lower_bound, unsigned upper_bound) {
/* PREKONDISI : Angka lower_bound dan upper_bound tidak negatidf (>0)*/
/* Menghasilkan angka random diantara lower_bound sampai upper_bound dengan menggunakan proses 
 * efek kupu-kupu silang. Seed didapatkan dari mengambil waktu lokal dan elemen 
 * randomness yang didapat dari assignment pointer */
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

    return ((seed1 + seed2 + seed3) % (upper_bound - lower_bound + 1)) + lower_bound;
}

int katatoint(Word W) {
    // KAMUS LOKAL
    int i, x = 0;

    // ALGORITMA
    for (i=0; i<W.Length; i++) {
        x = (x*10) + (W.TabWord[i] - '0');
    } return x;
}

void list_game(TabWord list){
    /*
    Proses  : Membaca listglobal yang berisi nama nama game
              yang terdapat pada file
    I.S     : listglobal yang sudah terdefenisi
    F.S     : Menambilkan isi dari list ke layar
    */

   //Kamus Lokal

   //Algoritma
   printf("Berikut adalah daftar game yang tersedia");
   DisplayArray(list);
}