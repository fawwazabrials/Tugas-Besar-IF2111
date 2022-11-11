/* File : game_rng.c */

#include "RNG.h"

/* TODO : ubah parameter ke ADT score waktu udh dibuat */

void run_rng() {
/* PROSES : Sistem akan men-generate angka random dan pemain harus menebak angka tersebut. 
 *          Tiap kali input, sistem akan mencetak ke layar apakah tebakan lebih besar, 
 *          lebih kecil, atau sudah benar. Angka random akan berada diantara 0 - 100 (inklusif)
 * I.S : skor sembarang 
 * F.S : skor diisi skor dari pemain hasil permainan, skor diitung dengan rumus 100 - 5*tries */
    // KAMUS LOKAL
    Word temp1, temp2;
    int rand_int, in, tries=0;

    printf("---------------------------------------------------\n");
    printf("         ___           ___           ___                 \n");
    printf("        /\\  \\         /\\  \\         /\\__\\          \n");
    printf("       /::\\  \\        \\:\\  \\       /:/ _/_          \n");
    printf("      /:/\\:\\__\\        \\:\\  \\     /:/ /\\  \\      \n");
    printf("     /:/ /:/  /    _____\\:\\  \\   /:/ /::\\  \\        \n");
    printf("    /:/_/:/__/___ /::::::::\\__\\ /:/__\\/\\:\\__\\      \n");
    printf("    \\:\\/:::::/  / \\:\\~~\\~~\\/__/ \\:\\  \\ /:/  /   \n");
    printf("     \\::/~~/~~~~   \\:\\  \\        \\:\\  /:/  /       \n");
    printf("      \\:\\~~\\        \\:\\  \\        \\:\\/:/  /      \n");
    printf("       \\:\\__\\        \\:\\__\\        \\::/  /        \n");
    printf("        \\/__/         \\/__/         \\/__/             \n\n");
    printf("---------------------------------------------------\n\n");


    // ALGORITMA
    rand_int = randint(0, 100);
    printf("Tebakan : ");
    scan("%d", &temp1, &temp2, &in);

    while (rand_int != in) {
        if (in > rand_int) printf("Lebih kecil\n");
        else printf("Lebih besar\n");
        tries++;
        printf("Tebakan : ");
        scanf("%d", &in);
    }

    printf("Skor-mu adalah %d\n", 100 - 5*tries);
}
