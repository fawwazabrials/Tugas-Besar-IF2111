/*
 * NIM: 18221069
 * Nama: Gibran Fasha Ghazanfar
 * Tanggal: 22 Oktober 2022
 * Topik praktikum: Pra Praktikum 7
 * Deskripsi: Implementasi stack.h
 */
 #include <stdio.h>
 #include "stackofhanoi.h"
 
/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyS(Stack *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */
{
	Top(*S) = Nil;
	for (int i = 0; i < MaxEl; i++)
	{
		(*S).T[i] = 0;
	}
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyS(Stack S)
{
    return (Top(S) == Nil);
}
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFullS(Stack S)
{
    return (Top(S) == MaxEl - 1);
}
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushS(Stack * S, infotype X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
	Top(*S)++;
	InfoTop(*S) = X;

}
/* ************ Menghapus sebuah elemen Stack ************ */
void PopS(Stack * S, infotype* X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
	*X = InfoTop(*S);
    InfoTop(*S) = 0;
    Top(*S) -= 1;
}

int getTop(Stack S) 
{
    if (IsEmptyS(S)) {
        return 0;
    } else {
        return InfoTop(S);
    }
}
boolean isStackEqual(Stack a, Stack b)
{
	if (Top(a) != Top(b))
	{
		return false;
	}
	else
	{
		for (int i = 0; i <= Top(a); i++)
		{
			if (a.T[i] != b.T[i])
			{
				return false;
			}
		}
		return true;
	}
}