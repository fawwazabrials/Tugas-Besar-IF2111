#ifndef SET_HANGMAN_H
#define SET_HANGMAN_H
#include <stdio.h>
#include "boolean.h"
#include "mesinkata.h"

/* MODUL Seth
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

#define NilSeth 0
#define MaxElSeth 100

typedef int addressSeth;
typedef char infotypeSeth;

typedef struct
{
    infotypeSeth Elements[MaxElSeth];
    addressSeth Count;
} Seth;

/* Definisi Seth S kosong : S.Count = NilSet */
/* S.Count = jumlah element Seth */
/* S.Elements = tempat penyimpanan element Seth */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptySeth(Seth *S);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Seth S kosong berkapasitas MaxElSet */
/* Ciri Seth kosong : count bernilai NilSet */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptySeth(Seth S);
/* Mengirim true jika Seth S kosong*/
/* Ciri Seth kosong : count bernilai NilSet */

boolean IsFullSeth(Seth S);
/* Mengirim true jika Seth S penuh */
/* Ciri Seth penuh : count bernilai MaxElSet */

/* ********** Operator Dasar Seth ********* */
void InsertSethElmt(Seth *S, infotypeSeth Elmt);
/* Menambahkan Elmt sebagai elemen Seth S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

void DeleteSethElmt(Seth *S, infotypeSeth Elmt);
/* Menghapus Elmt dari Seth S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

boolean IsMemberSeth(Seth S, infotypeSeth Elmt);
/* Mengembalikan true jika Elmt adalah member dari S */

#endif