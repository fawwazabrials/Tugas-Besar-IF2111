#include <stdio.h>
#include <stdlib.h>
#include "../../src/ADT/mesinkarakter.h"
#include "../../src/ADT/mesinkata.h"
#include "../../src/functions.h"

int main() {
    STARTWORDFILE("config.txt");
    while (!EndWord) {
        printf("len = %d\n", currentWord.Length);
        displayWord(currentWord);
        ADV();
        ADVWORDFILE();
    }
}