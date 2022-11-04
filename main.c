#include <stdio.h>
#include <stdlib.h>
#include "src/ADT/mesinkarakter.h"
#include "src/ADT/mesinkata.h"
#include "src/ADT/array.h"
#include "src/functions.h"

int main() {
    // KAMUS LOKAL
    Word masukan;
    TabWord games;
    boolean loop = true;
    int i, len;

    // ALGORITMA
    MakeEmpty(&games);
    while (loop) {
        input(&masukan);

        // INPUT ADALAH START
        if (isKataEqual(masukan, "START")) {
            loop = false;
            STARTWORDFILE("config.txt");
            len = katatoint(currentWord);
            for (i=1; i<=len; i++) {
                ADV();
                ADVWORDFILE();
                SetEl(&games, i, currentWord);
            }

            // goto menu kalo udah dibuat
            // menu(games, queue_games);
        }

        // INPUT ADALAH LOAD
        else if (isKataEqual(masukan, "LOAD")) {
            printf("LOAD\n");
            ADVWORD();
            displayWord(currentWord);   // nama file yang bakal dibaca
            loop = false;
        }

        // INPUT GAJELAS 
        else {
            printf("MASUKAN SALAH!\n");
        }
    }
    
}