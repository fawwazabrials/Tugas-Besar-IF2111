#include <stdio.h>
#include <stdlib.h>
#include "../../src/ADT/mesinkarakter.h"
#include "../../src/ADT/mesinkata.h"
#include "../../src/functions.h"

int main() {
    printf("------- Testing 1 : Menguji STARTWORD, ADVWORD, dan CopyWord -------\n");
    printf("Ketik ""TESTING MESIN KATA"" ke CLI\n\n");

    printf("input : ");
    STARTWORD();

    printf("--- Expected result :\n");
    printf("TESTING\nMESIN\nKATA\n");
    printf("--- Result :\n");
    while (!EndWord) {
        displayWord(currentWord);
        ADVWORD();
    }

    printf("\n------- Testing 2 : Menguji ResetCurrentWord -------\n\n");
    printf("--- Expected result :\n");
    printf("length = 0\nkata = \n");
    ResetCurrentWord(currentWord);
    printf("--- Result :\n");
    printf("length = %d\nkata = \n", currentWord.Length);
    displayWord(currentWord);

    printf("\n------- Testing 3 : Menguji STARTLINE dan CopyWordWithBlanks -------\n");
    printf("Ketik ""TESTING START LINE"" ke CLI\n\n");
    printf("input : "); STARTLINE();
    printf("--- Expected result :\n");
    printf("TESTING START LINE\n");
    printf("--- Result :\n");
    displayWord(currentWord);

    printf("\n------- Testing 4 : Menguji STARTWORFILE -------\n");
    printf("--- Expected result : TESTING MESIN KATA BACA DARI FILE\n");
    STARTWORDFILE("mesinkatatest.c");
    printf("--- Result : "); displayWord(currentWord);


    // Buat kata untuk testing isKataEqual
    Word W1, W2, W3;
    W1.Length=3;
    W1.TabWord[0] = 'H'; W1.TabWord[1] = 'A'; W1.TabWord[2] = 'I';
    W2.Length=3;
    W2.TabWord[0] = 'H'; W2.TabWord[1] = 'A'; W2.TabWord[2] = 'I';
    W3.Length=5;
    W3.TabWord[0] = 'H'; W3.TabWord[1] = 'E'; W3.TabWord[2] = 'L'; W3.TabWord[3] = 'L'; W3.TabWord[4] = 'O';

    printf("\n------- Testing 4 : Menguji isKataEqual -------\n");
    printf("Comparing ""HAI"" with ""HAI""\n");
    printf("--- Expected result : isSame = 1\n");
    printf("--- Result : isSame = %u\n", isKataEqual(W1, W2));
    displayWord(W1);displayWord(W2);
    printf("Comparing ""HAI"" with ""HELLO""\n");
    printf("--- Expected result : isSame = 0\n");
    printf("--- Result : isSame = %u\n", isKataEqual(W1, W3));

    // Buat kata untuk testing isKataInt
    W1.Length=3;
    W1.TabWord[0] = '1'; W1.TabWord[1] = '2'; W1.TabWord[2] = '3';

    printf("\n------- Testing 4 : Menguji isKataEqual -------\n");
    printf("Cheking if ""HAI"" is integer\n");
    printf("--- Expected result : isSame = 0\n");
    printf("--- Result : isSame = %u\n", isKataInt(W2));
    printf("Cheking if ""123"" is integer\n");
    printf("--- Expected result : isSame = 1\n");
    printf("--- Result : isSame = %u\n", isKataInt(W1));
}