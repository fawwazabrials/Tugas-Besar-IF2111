/* File : functions.c */

#include "functions.h"

unsigned randint(unsigned lower_bound, unsigned upper_bound) {
/* PREKONDISI : Angka lower_bound dan upper_bound tidak negatidf (>0)
 * Menghasilkan angka random diantara lower_bound sampai upper_bound dengan menggunakan proses 
 * efek kupu-kupu silang. Seed didapatkan dari mengambil waktu lokal dan elemen 
 * randomness yang didapat dari assignment pointer. */
    // KAMUS LOKAL
    int* x;
    unsigned i, seed1, seed2, seed3;

    // ALGORITMA
    x = (int*) malloc (sizeof(int));
    seed1 = time(NULL);
    seed2 = ((unsigned) x);
    srand(seed1);
    seed3 = rand();

    for (i=0; i<100; i++) {
        if (i%3==0) seed1 = (4*seed2*(1+seed3)) % MAX_INT;
        else if (1%3==1) seed2 = (4*seed3*(1+seed1)) % MAX_INT;
        else seed3 = (4*seed1*(1+seed2)) % MAX_INT;
    }

    return ((seed1*2 + seed2 + seed3) % (upper_bound - lower_bound + 1)) + lower_bound;
}

int katatoint(Word W) {
/* Mengkonversi kata ke integer. Jika kata bukan integer make akan mengembalikan -9999. */
    // KAMUS LOKAL
    int i, x = 0;

    // ALGORITMA
    if (isKataInt(W)) {
        for (i=0; i<W.Length; i++) {
            x = (x*10) + (W.TabWord[i] - '0');
        } 
    } else x = -9999;
    
    return x;
}

void scan(char* str, Word* W1, Word* W2, int* x) {
/* Implementasi dari scanf pada library stdio.h, hanya dapat menerima 3 buah tipe input, 2 Kata dan 1 int, dan setiap 
   pemanggilan harus menyertakan pointer ke semua elemen walaupun elemen tersebut tidak ingin di-inputkan.
 * %c untuk Command 1 kata; %s untuk 1 buah string dengan spasi (banyak kata); %d untuk integer
 * I.S. : W1, W2, dan x sembarang, str berupa elemen tipe aja yang akan diinputkan
 * F.S. : Setidaknya salah satu dari W1, W2, atau x berisikan dengan input user

/* CONTOH PEMANGGILAN
 * 1. scan("%c", &W1, &W2, &x) 
        Akan menerima 1 buah command dan hanya ditaruh di W1, W2 dan x sembarang
 * 2. scan("%c %d", &W1, &W2, &x) 
        Akan menerima 1 buah command dan 1 buah int, command akan ditaruh di 
        W1 dan integer akan ditaruh di x, W2 sembarang 
 * 3. scan("%s",  &W1, &W2, &x) 
        Akan menerima 1 buah line input yang akan ditaruh di W1, W2 dan x sembarang
 * 4. scan("%d",  &W1, &W2, &x) 
        Akan menerima 1 buah integer yang akan ditaruh di x, W1 dan W2 sembarang 
 * 5. scan("", &W1, &W2, &x)
        W1, W2, dan x sembarang, ngapain panggil gituan gak guna */
    // KAMUS LOKAL
    boolean first = false;

    // ALGORITMA
    (*W1).Length = 0;
    (*W2).Length = 0;

    while (*str != '\0') {
        if (*str == '%') {
            str++;
            if (*str == 'c') {
                if (!first) {
                    STARTWORD();
                    // copyWord(currentWord, W1);
                    (*W1) = currentWord;
                    first = true;
                } else {
                    ADVWORD();
                    // copyWord(currentWord, W2);
                    (*W2) = currentWord;
                }
            }

            else if(*str == 's') {
                STARTLINE();
                // copyWord(currentWord, W1);
                (*W1) = currentWord;
            }

            if (*str == 'd') {
                if (!first) {
                    STARTWORD();
                    (*x) = katatoint(currentWord);
                    first = true;
                } else {
                    ADVWORD();
                    (*x) = katatoint(currentWord);
                }
            }
        }
        else str++;
    } RESETPITA();
}

boolean ValidateCommand(Word W1, char* str) {
/* Membandingkan Word W1 dengan string str, mengembalikan true apabila W1 sama dengan str */
    // KAMUS LOKAL
    Word W2;

    // ALGORITMA
    W2.Length = 0;
    while (*str != '\0') {
        W2.TabWord[W2.Length++] = *str;
        str++;
    }

    return isKataEqual(W1, W2);
}

char* WordToString(Word W) {
    /* Meng-copy string dari Word */
    /* I.S. W terdefinisi */
    /* F.S. string ter-copy dan berisikan elemen-elemen dari array TabWord dari Word */
    char *s = (char*) malloc (W.Length * sizeof(char));
    int i;
    for (i = 0; i < W.Length && W.TabWord[i] != '\0'; i++) {
        *(s+i) = W.TabWord[i];
    }
    *(s + i) = '\0';
    return s;
}
