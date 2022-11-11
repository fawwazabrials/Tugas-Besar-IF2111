#include <stdio.h>
#include <stdlib.h>
#include "../../src/ADT/mesinkarakter.h"
#include "../../src/commands.h"

int main()
{
    Word W1, W2;
    int x;
    
    scan("%c", &W1, &W2, &x); // Menerima input dari user dan memasukkannya ke dalam W1. W2 dan x sembarang

    START(); // Membaca input dari stdin
    while (currentChar != MARK) // Selama currentChar bukan MARK (\n)
    {
        printf("%c", currentChar);
        ADV(); // Lanjut ke karakter berikutnya
    }

    RESETPITA(); // Mengembalikan state awal pita (pita kosong)

    STARTFILE("test1.txt"); // Membaca input dari file test1.txt
    while (currentChar != '\0') // Selama currentChar bukan akhir dari file (\0)
    {
        printf("%c", currentChar);
        ADV(); // Lanjut ke karakter berikutnya
    }
    return 0;
}