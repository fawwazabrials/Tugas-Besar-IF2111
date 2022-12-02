#include "map.h"
#include <stdio.h>

int main () {
    Map M;
    CreateEmptyMap(&M);
    printf("---Driver ADT Map---\n");
    printf("Cek apakah map kosong (1=ya,0=tidak,target=1): %d\n",IsEmptyMap(M));
    printf("Cek apakah map penuh (1=ya,0=tidak,target=0): %d\n",IsFullMap(M));
    printf("Masukkan dua buah kata lalu tekan enter: ");STARTWORD();
    printf("Cek apakah ada elemen dengan key \"");
        displayWord(currentWord,false);
        printf("\" (1=ya,0=tidak,target=0): %d\n",IsMemberMap(M,currentWord));
    printf("Cek nilai elemen dengan key \"");
        displayWord(currentWord,false);
        printf("\" jika key ada (target=-999 [tidak ditemukan]): %d\n",ValueMap(M,currentWord));
    printf("Memasukkan elemen dengan key \"");
        displayWord(currentWord,false);
        printf("\" dan value 7.\n");
    InsertMap(&M,currentWord,7);
    printf("Cek apakah ada elemen dengan key \"");
        displayWord(currentWord,false);
        printf("\" (1=ya,0=tidak,target=1): %d\n",IsMemberMap(M,currentWord));
    printf("Cek nilai elemen dengan key \"");
        displayWord(currentWord,false);
        printf("\" jika key ada (target=7): %d\n",ValueMap(M,currentWord));
    printf("Masukkan sebuah kata lalu tekan enter: ");STARTWORD();
    printf("Memasukkan elemen dengan key \"");
        displayWord(currentWord,false);
        printf("\" dan value 71.\n");
    InsertMap(&M,currentWord,71);
    printf("Cek apakah ada elemen dengan key \"");
        displayWord(currentWord,false);
        printf("\" (1=ya,0=tidak,target=1): %d\n",IsMemberMap(M,currentWord));
    printf("Cek nilai elemen dengan key \"");
        displayWord(currentWord,false);
        printf("\" jika key ada (target=71): %d\n",ValueMap(M,currentWord));
    printf("Menghapus elemen dengan key \"");
        displayWord(currentWord,true);
        printf("\"\n");
    DeleteMap(&M,currentWord);
    printf("Cek apakah ada elemen dengan key \"");
        displayWord(currentWord,false);
        printf("\" (1=ya,0=tidak,target=0): %d\n",IsMemberMap(M,currentWord));
    printf("Cek nilai elemen dengan key \"");
        displayWord(currentWord,false);
        printf("\" jika key ada (target=-999 [tidak ditemukan]): %d\n",ValueMap(M,currentWord));
    printf("Selesai\n");
}