#ifndef map_H
#define map_H
#include <stdio.h>
#include "../boolean/boolean.h"
#include "../mesinkata/mesinkata.h"

/* MODUL Map */

// #define false 0
// #define true 1
#define NilMap 0
#define MaxEl 100
#define Undefined -999

// typedef int bool;
typedef Word keytypeMap;
typedef int valuetypeMap;
typedef int addressMap;

typedef struct {
	keytypeMap Key;
	valuetypeMap Value;
} infotypeMap;

typedef struct {
	infotypeMap Elements[MaxEl+1];
	addressMap Count;
} Map;

/* Definisi Map M kosong : M.Count = NilMap */
/* M.Count = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptyMap(Map *M);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count berNilMapai NilMap */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyMap(Map M);
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count berNilMapai NilMap */

boolean IsFullMap(Map M);
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count berNilMapai MaxEl */

/* ********** Operator Dasar Map ********* */
valuetypeMap ValueMap(Map M, keytypeMap k);
/* Mengembalikan NilMapai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void InsertMap(Map *M, keytypeMap k, valuetypeMap v);
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k, terurut secara menurun berdasarkan value,
        jika ada anggota M lain dengan value yang sama, elemen yang lebih baru diletakkan belakangan.
        Jika k sudah ada, operasi tidak dilakukan */

void DeleteMap(Map *M, keytypeMap k);
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean IsMemberMap(Map M, keytypeMap k);
/* Mengembalikan true jika k adalah member dari M */


#endif