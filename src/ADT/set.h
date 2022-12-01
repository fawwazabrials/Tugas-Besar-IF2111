#ifndef set_H
#define set_H
#include <stdio.h>
#include "boolean.h"
#include "mesinkata.h"

/* MODUL Set
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

#define NilSet 0
#define MaxElSet 100

typedef int addressSet;
typedef Word infotypeSet;

typedef struct
{
    infotypeSet Elements[MaxElSet];
    addressSet Count;
} Set;

/* Definisi Set S kosong : S.Count = NilSet */
/* S.Count = jumlah element Set */
/* S.Elements = tempat penyimpanan element Set */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptySet(Set *S);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxElSet */
/* Ciri Set kosong : count bernilai NilSet */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptySet(Set S);
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai NilSet */

boolean IsFullSet(Set S);
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxElSet */

/* ********** Operator Dasar Set ********* */
void InsertSetElmt(Set *S, infotypeSet Elmt);
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

void DeleteSetElmt(Set *S, infotypeSet Elmt);
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

boolean IsMemberSet(Set S, infotypeSet Elmt);
/* Mengembalikan true jika Elmt adalah member dari S */

#endif