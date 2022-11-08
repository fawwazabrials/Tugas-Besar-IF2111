/* ********** Definisi TYPE MATRIKS dengan indeks dan elemen integer ********** */

#ifndef MATRIKS_H
#define MATRIKS_H

#include "boolean.h"

/* Ukuran minimum dan maksimum baris dan kolom */
#define MaxElBrs 4
#define MaxElKol 4

typedef int indeksMatriks; /* indeks baris, kolom */
typedef int ElTypeMatriks; 
typedef struct { 
	ElTypeMatriks Mem[MaxElBrs][MaxElKol];
    int NBrsEff; /* banyaknya/ukuran baris yg terdefinisi */
	int NKolEff; /* banyaknya/ukuran kolom yg terdefinisi */
} Matriks;

#define NBrsEff(M) (M).NBrsEff
#define NKolEff(M) (M).NKolEff
#define Elmt(M,i,j) (M).Mem[(i)][(j)]

/* ADT Matriks ini dibuat untuk kepentingan game 2048, sehingga banyak primitif yang tidak diimplementasikan 
   karena tidak dibutuhkan (terutama fungsi matematis seperti transpose atau determinan) dan banyak juga 
   primitif yang diimplementasikan dengan membayangkan game 2048 sebagai pengguna ADT utama. */

/*************************** PRIMITIF ASLI MATRIKS ***************************/
void MakeMatriks (int NB, int NK, Matriks * M); 
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori
   I.S. : NB dan NK adalah valid untuk memori matriks yang dibuat
   F.S. : Matriks M sesuai dengan definisi di atas terbentuk */

boolean isMatriksEmpty(Matriks M);
/* Mengembalikan true apabila matriks kosong. 
   Syarat dari matriks kosong adalah seluruh elemen dalam matriks bernilai 0. */

boolean isMatriksFull(Matriks M);
/* Mengembalikan true apabila matriks sudah penuh. 
   Syarat dari matriks kosong adalah tidak ada elemen dalam matriks bernilai 0. */

int maxInMatriks(Matriks M);
/* Mengembalikan nilai terbesar dalam matriks. */

void copyMatriks(Matriks in, Matriks* out);
/* Menyalin seluruh isi Matriks in ke Matriks out.
   I.S. : in dan out sembarang 
   F.S. : in dan out memiliki isi yang sama */

void displayMatriks(Matriks M);
/* Mencetak Matriks ke layar dalam bentuk kotak sebagai tambilan game 2048. 
   I.S. : Sembarang
   F.S. : Seluruh isi matriks tercetak ke layar */

/************************* PRIMITIF MATRIKS UNTUK 2048 *************************/
void geserMatriksKanan(Matriks* M, int* score, boolean merge);
/* Menggeser seluruh isi matriks ke kanan dengan bekas tempat elemen pergeseran menjadi 0. 
   I.F. : Sembarang
   F.S. : Seluruh elemen akan tergeser ke pojok kanan matriks, bila merge bernilai true maka 
          jika dalam penggeseran elemen sebelah kanannya memiliki nilai yang sama, nilai 
		  barunya adalah penjumlahan nilai sekarang dengan nilai kanannya. */

void geserMatriksKiri(Matriks* M, int* score, boolean merge);
/* Menggeser seluruh isi matriks ke kiri dengan bekas tempat elemen pergeseran menjadi 0. 
   I.F. : Sembarang
   F.S. : Seluruh elemen akan tergeser ke pojok kiri matriks, bila merge bernilai true maka 
          jika dalam penggeseran elemen sebelah kirinya memiliki nilai yang sama, nilai 
		  barunya adalah penjumlahan nilai sekarang dengan nilai kirinya. */

void geserMatriksAtas(Matriks* M, int* score, boolean merge);
/* Menggeser seluruh isi matriks ke atas dengan bekas tempat elemen pergeseran menjadi 0. 
   I.F. : Sembarang
   F.S. : Seluruh elemen akan tergeser ke pojok atas matriks, bila merge bernilai true maka 
          jika dalam penggeseran elemen sebelah atasnya memiliki nilai yang sama, nilai 
		  barunya adalah penjumlahan nilai sekarang dengan nilai atasnya. */

void geserMatriksBawah(Matriks* M, int* score, boolean merge);
/* Menggeser seluruh isi matriks ke bawah dengan bekas tempat elemen pergeseran menjadi 0. 
   I.F. : Sembarang
   F.S. : Seluruh elemen akan tergeser ke pojok bawah matriks, bila merge bernilai true maka 
          jika dalam penggeseran elemen sebelah bawahnya memiliki nilai yang sama, nilai 
		  barunya adalah penjumlahan nilai sekarang dengan nilai bawahnya. */

#endif