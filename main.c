#include <stdio.h>
#include <stdlib.h>
#include "src/ADT/mesinkarakter.h"
#include "src/ADT/mesinkata.h"
#include "src/functions.h"

int main() {
    // KAMUS LOKAL
    Word masukan;
    boolean loop = true;
    int i, len;

    // ALGORITMA
    while (loop) {
        input(&masukan);
        if (isKataEqual(masukan, "START")) {
            loop = false;
            STARTWORDFILE("config.txt");
            len = katatoint(currentWord);
            for (i=0; i<len; i++) {
                ADV();
                ADVWORDFILE();
                // insert save here
            }

            printf("\nDONE START\n");
        }
        else if (isKataEqual(masukan, "LOAD")) {
            printf("LOAD\n");
            loop = false;
        } 
        else {
            printf("OTHERS\n");
        }
    }
    
}