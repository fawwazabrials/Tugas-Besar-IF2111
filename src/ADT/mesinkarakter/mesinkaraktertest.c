#include <stdio.h>
#include <stdlib.h>
#include "mesinkarakter.h"

int main()
{   
    boolean success;

    printf("====================== DRIVER MESINKARAKTER ======================\n");
    STARTFILE("test1.txt", &success); // Start reading from file
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