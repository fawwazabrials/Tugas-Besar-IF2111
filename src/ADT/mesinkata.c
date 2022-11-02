#include <stdio.h>
#include "mesinkata.h"

boolean EndWord;
Word currentWord;

void IgnoreBlanks() {
    /* Mengabaikan satu atau beberapa BLANK
       I.S. : currentChar sembarang
       F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    
    // KAMUS LOKAL

    // ALGORITMA
    while (currentChar == BLANK) ADV();
}

void STARTWORD() {
    /* I.S. : currentChar sembarang
       F.S. : endWord = true, dan currentChar = MARK;
              atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
              currentChar karakter pertama sesudah karakter terakhir kata */
    
    // KAMUS LOKAL

    // ALGORITMA
    START();
    IgnoreBlanks();
    if (currentChar == MARK) EndWord = true;
    else {
        EndWord = false;
        CopyWord();
    }
}

void ADVWORD() {
    /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
       F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
              currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
              Jika currentChar = MARK, endWord = true.
       Proses : Akuisisi kata menggunakan procedure CopyWord */

    // KAMUS LOKAL

    // ALGORITMA
    IgnoreBlanks();
    if (currentChar == MARK) EndWord = true;
    else {
        EndWord = false;
        CopyWord();
        IgnoreBlanks();
    }
}

void CopyWord() {
    /* Mengakuisisi kata, menyimpan dalam currentWord
       I.S. : currentChar adalah karakter pertama dari kata
       F.S. : currentWord berisi kata yang sudah diakuisisi;
              currentChar = BLANK atau currentChar = MARK;
              currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
              Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */

    // KAMUS LOKAL

    // ALGORITMA
    currentWord.Length = 0;
    while (currentChar != BLANK && currentChar != MARK) {
        if (currentWord.Length < NMax) { // jika lebih akan terpotong
            currentWord.TabWord[currentWord.Length++] = currentChar;
            ADV();
        } else
            break;
            }
}