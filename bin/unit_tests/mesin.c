#include <stdio.h>
#include <stdlib.h>
#include "../../src/ADT/mesinkarakter.h"
#include "../../src/ADT/mesinkata.h"
#include "../../src/functions.h"

void displayWord(Word W) {
    printf("%s\n", W.TabWord);
}

int main() {
    STARTFILE("config.txt");
    while (!EOP) {
        printf("%c", currentChar);
        ADV();
    } printf("\n");
}