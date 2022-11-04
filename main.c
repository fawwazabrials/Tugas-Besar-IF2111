#include <stdio.h>
#include <stdlib.h>
#include "src/ADT/mesinkarakter.h"
#include "src/ADT/mesinkata.h"
#include "src/ADT/array.h"
#include "src/ADT/queue.h"
#include "src/functions.h"

int main() {
    // KAMUS LOKAL
    Word masukan;
    TabWord games;
    Queue queue_game;
    boolean loop = true;
    int i, len;

    // ALGORITMA
    MakeEmpty(&games);
    CreateQueue(&queue_game);
    while (loop) {
        STARTWORD();

        // INPUT ADALAH START
        if (isKataEqual(currentWord, "START")) {
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
        else if (isKataEqual(currentWord, "LOAD")) {
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