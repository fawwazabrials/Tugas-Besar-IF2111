#include <stdio.h>
#include "matriks.h"

/* ADT Matriks ini dibuat untuk kepentingan game 2048, sehingga banyak primitif yang tidak diimplementasikan 
   karena tidak dibutuhkan (terutama fungsi matematis seperti transpose atau determinan) dan banyak juga 
   primitif yang diimplementasikan dengan membayangkan game 2048 sebagai pengguna ADT utama. */

/*************************** PRIMITIF ASLI MATRIKS ***************************/
void MakeMatriks (int NB, int NK, Matriks * M) {
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori
   I.S. : NB dan NK adalah valid untuk memori matriks yang dibuat
   F.S. : Matriks M sesuai dengan definisi di atas terbentuk */
    // KAMUS LOKAL
    int i, j;

    // ALGORITMA
    NBrsEff(*M) = NB;
    NKolEff(*M) = NK;
    for (i=0; i<NBrsEff(*M); i++) {
        for (j=0; j<NKolEff(*M); j++) {
            Elmt(*M,i,j) = 0;
        }
    }
} 

boolean isMatriksEmpty(Matriks M) {
/* Mengembalikan true apabila matriks kosong. 
   Syarat dari matriks kosong adalah seluruh elemen dalam matriks bernilai 0. */
    // KAMUS LOKAL
    int i, j;

    // ALGORITMA
    for (i=0; i<NBrsEff(M); i++) {
        for (j=0; j<NKolEff(M); j++) {
            if (Elmt(M,i,j) != 0) return false;
        }
    } return true;
}

boolean isMatriksFull(Matriks M) {
/* Mengembalikan true apabila matriks sudah penuh. 
   Syarat dari matriks kosong adalah tidak ada elemen dalam matriks bernilai 0. */
    // KAMUS LOKAL
    int i, j;

    // ALGORITMA
    for (i=0; i<NBrsEff(M); i++) {
        for (j=0; j<NKolEff(M); j++) {
            if (Elmt(M,i,j) == 0) return false;
        }
    } return true;
}

int maxInMatriks(Matriks M) {
/* Mengembalikan nilai terbesar dalam matriks. */
    // KAMUS LOKAL
    int i, j, maxi=-1;

    // ALGORITMA
    for (i=0; i<NBrsEff(M); i++) {
        for (j=0; j<NKolEff(M); j++) {
            if (Elmt(M, i, j) > maxi) maxi = Elmt(M, i, j);
        }
    } return maxi;
}

void copyMatriks(Matriks in, Matriks* out) {
/* Menyalin seluruh isi Matriks in ke Matriks out.
   I.S. : in dan out sembarang 
   F.S. : in dan out memiliki isi yang sama */
    // KAMUS LOKAL
    int i, j;

    // ALGORITMA

    MakeMatriks(in.NBrsEff, in.NKolEff, out);
    for (i=0; i<in.NBrsEff; i++) {
        for (j=0; j<in.NKolEff; j++) {
        
            Elmt(*out, i, j) = Elmt(in, i, j);
        }
    }
}

void displayMatriks(Matriks M) {
/* Mencetak Matriks ke layar dalam bentuk kotak sebagai tambilan game 2048. 
   I.S. : Sembarang
   F.S. : Seluruh isi matriks tercetak ke layar */
    // KAMUS LOKAL
    int i, j;

    // ALGORITMA
    for (i=0; i<NBrsEff(M); i++) {
        printf("_________________________________\n\n|");
        for (j=0; j<NKolEff(M); j++) {
            printf("%6d\t|", Elmt(M,i,j));
        } printf("\n");
    } printf("_________________________________\n");
}


/************************* PRIMITIF MATRIKS UNTUK 2048 *************************/
void geserMatriksKanan(Matriks* M, int* score, boolean merge) {
/* Menggeser seluruh isi matriks ke kanan dengan bekas tempat elemen pergeseran menjadi 0. 
   I.F. : Sembarang
   F.S. : Seluruh elemen akan tergeser ke pojok kanan matriks, bila merge bernilai true maka 
          jika dalam penggeseran elemen sebelah kanannya memiliki nilai yang sama, nilai 
		  barunya adalah penjumlahan nilai sekarang dengan nilai kanannya. */
    // KAMUS LOKAL
    int i, j;

    // ALGORITMA
    for (i=0; i<NBrsEff(*M); i++) {
        for (j=NKolEff(*M)-1; j>0; j--) {
            if (merge && Elmt(*M, i, j) == Elmt(*M, i, j-1)) {
                Elmt(*M, i, j) += Elmt(*M, i, j-1);
                Elmt(*M, i, j-1) = 0;
            }

            else if (!merge && Elmt(*M, i, j) == 0) {
                Elmt(*M, i, j)  = Elmt(*M, i, j-1);
                *score += Elmt(*M, i, j);
                Elmt(*M, i, j-1)  = 0;
            }
        }
    }
}

void geserMatriksKiri(Matriks* M, int* score, boolean merge) {
/* Menggeser seluruh isi matriks ke kiri dengan bekas tempat elemen pergeseran menjadi 0. 
   I.F. : Sembarang
   F.S. : Seluruh elemen akan tergeser ke pojok kiri matriks, bila merge bernilai true maka 
          jika dalam penggeseran elemen sebelah kirinya memiliki nilai yang sama, nilai 
		  barunya adalah penjumlahan nilai sekarang dengan nilai kirinya. */
    // KAMUS LOKAL
    int i, j;

    // ALGORITMA
    for (i=0; i<NBrsEff(*M); i++) {
        for (j=0; j<NKolEff(*M)-1; j++) {
            if (merge && Elmt(*M, i, j) == Elmt(*M, i, j+1)) {
                Elmt(*M, i, j) += Elmt(*M, i, j+1);
                *score += Elmt(*M, i, j);
                Elmt(*M, i, j+1) = 0;
            }

            else if (!merge && Elmt(*M, i, j) == 0) {
                Elmt(*M, i, j)  = Elmt(*M, i, j+1);
                *score += Elmt(*M, i, j);
                Elmt(*M, i, j+1)  = 0;
            }
        }
    }
}

void geserMatriksAtas(Matriks* M, int* score, boolean merge) {
/* Menggeser seluruh isi matriks ke atas dengan bekas tempat elemen pergeseran menjadi 0. 
   I.F. : Sembarang
   F.S. : Seluruh elemen akan tergeser ke pojok atas matriks, bila merge bernilai true maka 
          jika dalam penggeseran elemen sebelah atasnya memiliki nilai yang sama, nilai 
		  barunya adalah penjumlahan nilai sekarang dengan nilai atasnya. */
    // KAMUS LOKAL
    int i, j;

    // ALGORITMA
    for (j=0; j<NKolEff(*M); j++) {
        for (i=0; i<NBrsEff(*M)-1; i++) {
            if (merge && Elmt(*M, i, j) == Elmt(*M, i+1, j)) {
                Elmt(*M, i, j) += Elmt(*M, i+1, j);
                Elmt(*M, i+1, j) = 0;
            }

            else if (!merge && Elmt(*M, i, j) == 0) {
                Elmt(*M, i, j)  = Elmt(*M, i+1, j);
                *score += Elmt(*M, i, j);
                Elmt(*M, i+1, j)  = 0;
            }
        }
    }
}

void geserMatriksBawah(Matriks* M, int* score, boolean merge) {
/* Menggeser seluruh isi matriks ke bawah dengan bekas tempat elemen pergeseran menjadi 0. 
   I.F. : Sembarang
   F.S. : Seluruh elemen akan tergeser ke pojok bawah matriks, bila merge bernilai true maka 
          jika dalam penggeseran elemen sebelah bawahnya memiliki nilai yang sama, nilai 
		  barunya adalah penjumlahan nilai sekarang dengan nilai bawahnya. */
    // KAMUS LOKAL
    int i, j;

    // ALGORITMA
    for (j=0; j<4; j++) {
        for (i=3; i>0; i--) {
            if (merge && Elmt(*M, i, j) == Elmt(*M, i-1, j)) {
                Elmt(*M, i, j) += Elmt(*M, i-1, j);
                Elmt(*M, i-1, j) = 0;
            }

            else if (!merge && Elmt(*M, i, j) == 0) {
                Elmt(*M, i, j)  = Elmt(*M, i-1, j);
                *score += Elmt(*M, i, j);
                Elmt(*M, i-1, j)  = 0;
            }
        }
    }
}
