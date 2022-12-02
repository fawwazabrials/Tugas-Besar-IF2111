/*
 * NIM: 18221069
 * Nama: Gibran Fasha Ghazanfar
 * Tanggal: 22 Oktober 2022
 * Topik praktikum: Pra Praktikum 7
 * Deskripsi: Implementasi StackHanoi.h
 */
 #include "stackofhanoi.h"
 
/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyS(StackHanoi *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah StackHanoi S yang kosong berkapasitas MaxElStackHanoi */
/* jadi indeksnya antara 0.. MaxElStackHanoi */
/* Ciri StackHanoi kosong : TOP ber-1ai -1 */
{
	Top(*S) = -1;
	for (int i = 0; i < MaxElStackHanoi; i++)
	{
		(*S).T[i] = 0;
	}
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyS(StackHanoi S)
{
    return (Top(S) == -1);
}
/* Mengirim true jika StackHanoi kosong: lihat definisi di atas */
boolean IsFullS(StackHanoi S)
{
    return (Top(S) == MaxElStackHanoi - 1);
}
/* Mengirim true jika tabel penampung -1ai elemen StackHanoi penuh */

/* ************ Menambahkan sebuah elemen ke StackHanoi ************ */
void PushS(StackHanoi * S, infotypeStackHanoi X)
/* Menambahkan X sebagai elemen StackHanoi S. */
/* I.S. S mungkin kosong, tabel penampung elemen StackHanoi TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
	Top(*S)++;
	InfoTop(*S) = X;

}
/* ************ Menghapus sebuah elemen StackHanoi ************ */
void PopS(StackHanoi * S, infotypeStackHanoi* X)
/* Menghapus X dari StackHanoi S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah -1ai elemen TOP yang lama, TOP berkurang 1 */
{
	*X = InfoTop(*S);
    InfoTop(*S) = 0;
    Top(*S) -= 1;
}

int getTop(StackHanoi S) 
{
    if (IsEmptyS(S)) {
        return 0;
    } else {
        return InfoTop(S);
    }
}

boolean isStackEqual(StackHanoi a, StackHanoi b)
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