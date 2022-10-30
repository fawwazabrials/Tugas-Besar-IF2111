/* File : game_rng.c */

#include "game_rng.h"
#include "functions.h"

/* TODO : ubah parameter ke ADT score waktu udh dibuat */

void run_rng(int* skor) {
/* PROSES : Sistem akan men-generate angka random dan pemain harus menebak angka tersebut. 
 *          Tiap kali input, sistem akan mencetak ke layar apakah tebakan lebih besar, 
 *          lebih kecil, atau sudah benar. Angka random akan berada diantara 0 - 100 (inklusif)
 * I.S : skor sembarang 
 * F.S : skor diisi skor dari pemain hasil permainan, skor diitung dengan rumus 100 - 5*tries */
    // KAMUS LOKAL
    int rand_int, in, tries=0;

    // ALGORITMA
    rand_int = randint(100);
    printf("Tebakan : ");
    scanf("%d", &in);

    while (rand_int != in) {
        if (in > rand_int) printf("Lebih kecil\n");
        else printf("Lebih besar\n");
        tries++;
        printf("Tebakan : ");
        scanf("%d", &in);
    }

    *skor = 100 - 5*tries;
}
