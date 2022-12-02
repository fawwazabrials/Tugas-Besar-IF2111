#include "stack.c"
#include <stdio.h>

int main()
{
    printf("====================== DRIVER STACK ======================\n");

    printf("Kita akan membuat stack kosong\n");
    printf(".\n");

    Stack S;
    CreateEmptyStack(&S); // Create empty stack

    printf("Lalu, kita akan mengecek apakah stack kosong\n");
    printf(".\n");
    if (IsEmptyStack(S)) //Mengecek apakah stack kosong
    {
        printf("Stack kosong\n");
    }
    else
    {
        printf("Stack tidak kosong\n");
    }

    printf("Setelah itu kita tambahkan elemen sebanyak %d ke stack\n", StackMaxEl);
    printf(".\n");

    for (int i = 0; i < StackMaxEl; i++) //Ngepush elemen sebanyak StackMaxEl ke stack
    {
        Push(&S, i);
    }

    printf("Lalu, kita akan mengecek apakah stack penuh\n");
    printf(".\n");

    if (IsFullStack(S)) //Mengecek apakah stack penuh
    {
        printf("Stack penuh\n");
    }
    else
    {
        printf("Stack tidak penuh\n");
    }

    printf("Setelah itu kita pop elemen sebanyak %d dari stack\n", StackMaxEl);
    printf(".\n");
    printf("Dan menge-printnya ke layar\n");
    printf(".\n");
    int X;
    for (int i = 0; i < StackMaxEl; i++) //Ngepop elemen sebanyak StackMaxEl dari stack
    {
        Pop(&S, &X);
        printf("%d ", X); //Print elemen yang di-pop
    }
}