#include "stdio.h"
#include "set.h"
/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptySet(Set *S){
    (*S).Elements[MaxEl];
    (*S).Count = Nil;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptySet(Set S){
    return(S.Count == Nil);
}
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */

boolean IsFullSet(Set S){
    return(S.Count == MaxEl);
}
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */

/* ********** Operator Dasar Set ********* */
void InsertSetElmt(Set *S, int Elmt){
        if (!IsMember(*S,Elmt)){
            (*S).Elements[(*S).Count]= Elmt;
            (*S).Count +=1;
        }
}
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

void DeleteSetElmt(Set *S, int Elmt){
    //Kamus Lokal
    int i;
    boolean found;
    //Algoritma
    i= 0;
    if (IsMember(*S, Elmt)) {
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
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

boolean IsMemberSet(Set S, int Elmt){
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
