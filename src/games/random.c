#include "random.h"

int run_random() {
/* Bukan game beneran. Langsung mencetak skor yang berupa angka random ke layar.
   I.S. : Sembarang
   F.S. : Skor berupa integer random tercetak ke layar */
    // KAMUS LOKAL
    int skor;
    // ALGORITMA
    skor = randint(0, 5000);
    printf("GAME OVER!\n\nSkor-mu adalah %d\n", skor);
    return skor;

}