#include <stdio.h>
#include <stdlib.h>
#include "../../src/ADT/mesinkarakter.c"
#include "../../src/ADT/mesinkarakter.h"
#include "../../src/commands.h"

int main()
{   
    printf("====================== DRIVER MESINKARAKTER ======================\n");
    STARTFILE("test1.txt"); // Start reading from file
    while (!EOP)
    {
        printf("%c", currentChar);
        ADV(); // next char
    }

    START(); // Start reading from stdin
    while (!EOP)
    {
        printf("%c", currentChar);
        ADV(); // next char
    }

    return 0;
}