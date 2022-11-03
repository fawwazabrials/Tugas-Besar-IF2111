#include <stdio.h>
#include "mesinkarakter.h"

char currentChar;
boolean EOP;
static FILE *pita;
static int retval;

void STARTFILE(char* file_name) {
    // KAMUS LOKAL
    static char path[150] = "..\\data\\";
    int i=0, len = 8;

    // ALGORITMA
    while (*file_name != '\0') {
        path[i+len] = *file_name;
        file_name++;
        i++;
    } path[i+len] = '\0';

    pita = fopen(path,"r");
    ADV();
}

void START() {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari stdin.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

    // KAMUS LOKAL

    // ALGORITMA    
    pita = stdin;
    ADV();
}

void ADV() {
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */

    // KAMUS LOKAL

    // ALGORITMA
    retval = fscanf(pita, "%c", &currentChar);
    EOP = (currentChar == MARK);
    // if (EOP) fclose(pita);
}

void CLOSEPITA() {
    fclose(pita);
}