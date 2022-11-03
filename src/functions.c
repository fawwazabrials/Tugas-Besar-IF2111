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
    for (i=0; i<W.Length-1; i++) {
        x = (x*10) + (W.TabWord[i] - '0');
    } return x;
}

boolean isKataEqual(Word W1, char* str) {
    // KAMUS LOKAL
    int i;
    Word W2;
    
    // ALGORITMA
    W2.Length = 0;
    while (*str != '\0') {
        W2.TabWord[W2.Length++] = *str;
        str++;
    }

    if (W1.Length != W2.Length) return false;
    else {
        for (i=0; i<W1.Length; i++) {
            if (W1.TabWord[i] != W2.TabWord[i]) return false;
        } return true;
    }
}

void input(Word *W) {
/* Hanya membaca 1 inputan */
    // KAMUS LOKAL
    int i;

    // ALGORITMA
    STARTWORD();
    for (i=0; i<(*W).Length; i++) {
        (*W).TabWord[i] = currentWord.TabWord[i];
    }
    (*W).Length = currentWord.Length;
}

void copyWord(Word asal, Word* jadi) {
    int i;

    for (i=0; i<asal.Length; i++) {
        (*jadi).TabWord[i] = currentWord.TabWord[i];
    }
    (*jadi).Length = currentWord.Length;
}

void displayWord(Word W) {
    // KAMUS LOKAL
    int i=0;

    // ALGORITMA
    for (i=0; i<W.Length; i++) {
        printf("%c", W.TabWord[i]);
    } printf("\n");
}