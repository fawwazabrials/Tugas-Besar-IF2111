/* File : game_rng.h */

#ifndef RNG_GAME_H
#define RNG_GAME_H

/* TODO : ubah parameter ke ADT score waktu udh dibuat */
void run_rng(int* skor);
/* PROSES : Sistem akan men-generate angka random dan pemain harus menebak angka tersebut. 
 *          Tiap kali input, sistem akan mencetak ke layar apakah tebakan lebih besar, 
 *          lebih kecil, atau sudah benar
 * I.S : skor sembarang 
 * F.S : skor diisi skor dari pemain hasil permainan */

int generate_score(int tries);
/* Menghasilkan skor yang didapatkan pemain  */

#endif