#include <stdio.h>
#include <stdlib.h>
#include "../../src/ADT/mesinkarakter.h"
#include "../../src/ADT/mesinkata.h"

void displayWord(Word W) {
    printf("%s\n", W.TabWord);
}

int main() {
    STARTWORD();
    while (!EndWord) {
        displayWord(currentWord);
        ADVWORD();
    }
}