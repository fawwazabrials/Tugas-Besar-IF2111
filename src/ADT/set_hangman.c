
#include "stdio.h"
#include "set_hangman.h"
/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptySeth(Seth *S){
    (*S).Elements[MaxElSeth];
    (*S).Count = NilSeth;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Seth S kosong berkapasitas MaxElseth */
/* Ciri Seth kosong : count bernilai Nilseth */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptySeth(Seth S){
    return(S.Count == NilSeth);
}
/* Mengirim true jika Seth S kosong*/
/* Ciri Seth kosong : count bernilai Nilseth */

boolean IsFullSeth(Seth S){
    return(S.Count == MaxElSeth);
}
/* Mengirim true jika Seth S penuh */
/* Ciri Seth penuh : count bernilai MaxElseth */

/* ********** Operator Dasar Seth ********* */
void InsertSeth(Seth *S, infotypeSeth Elmt){
        if (!IsMemberSeth(*S,Elmt)){
            (*S).Elements[(*S).Count]= Elmt;
            (*S).Count +=1;
        }
}
/* Menambahkan Elmt sebagai elemen Seth S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

void DeleteSeth(Seth *S, infotypeSeth Elmt){
    //Kamus Lokal
    int i;
    boolean found;
    //Algoritma
    i= 0;
    if (IsMemberSeth(*S, Elmt)) {
        for (i = 0; i < (*S).Count; i++) {
            if ((*S).Elements[i] == Elmt && (i != ((*S).Count) - 1)) {
                found = true;
            }
            if (found) {
                (*S).Elements[i] = (*S).Elements[i+1];
            }
        }
        ((*S).Count)--;
    }
}
/* Menghapus Elmt dari Seth S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

boolean IsMemberSeth(Seth S, infotypeSeth Elmt){
    //Kamus Lokal
    int i;
    boolean found;
    //Algoritma
    i= 0;
    found =false;
    while ((i < (S).Count) && (!found)){
        if(Elmt == (S).Elements[i]){
            found = true;
        }
        else{
            i +=1;
        }
    }
    return(found);
}
/* Mengembalikan true jika Elmt adalah member dari S */
