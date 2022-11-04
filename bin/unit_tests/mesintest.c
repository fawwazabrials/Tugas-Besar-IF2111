#include <stdio.h>
#include <stdlib.h>
#include "../../src/ADT/mesinkarakter.h"
#include "../../src/ADT/mesinkata.h"
#include "../../src/functions.h"

void displayWord(Word W) {
    // KAMUS LOKAL
    int i=0;

    // ALGORITMA
    for (i=0; i<W.Length; i++) {
        printf("%c", W.TabWord[i]);
    } printf("\n");
}

int main() {
    STARTWORDFILE("test.txt");
    while (!EndWord) {
        // printf("angka = %d\n", katatoint(currentWord));
        displayWord(currentWord);
        ADVWORD();
    }
}