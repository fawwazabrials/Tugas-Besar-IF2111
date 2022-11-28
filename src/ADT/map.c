#include "stdio.h"
#include "map.h"

/* Definisi Map M kosong : M.Count = Nil */
/* M.Count = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptyMap(Map *M){
    (*M).Count = Nil;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyMap(Map M){
    return((M).Count == Nil);
}
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */

boolean IsFullMap(Map M){
    return((M).Count == MaxEl);
}
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */

/* ********** Operator Dasar Map ********* */
valuetype ValueMap(Map M, keytype k){
    int i;
    boolean found;
    i=0;
    found = false;
    while (i < (M).Count && !found){
        if( isKataEqual(M.Elements[i].Key, k) ){
            found = true;
        }
        else{
            i += 1;
        }
    }
    if (found){
        return((M.Elements[i]).Value);
        }
    else{
        return(Undefined);
    }
}
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void InsertMap(Map *M, keytype k, valuetype v){
    if(!IsMemberMap(*M,k)){
        (*M).Count +=1;
        ((*M).Elements[(*M).Count]).Key= k;
        ((*M).Elements[(*M).Count]).Value= v;
    }
}
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void DeleteMap(Map *M, keytype k){
    //Kamus Lokal
    int i;
    boolean found;
    
    //Algoritma
    if(IsMemberMap(*M,k)){
        for(i=0;i<((*M).Count);i++){
            if( isKataEqual(M->Elements[i].Key, k) ){
                found = true;
            }
            if(found){
                ((*M).Elements[i]).Key = ((*M).Elements[i+1]).Key;
                ((*M).Elements[i]).Value = ((*M).Elements[i+1]).Value;
            }
        }
        (*M).Count -=1;
    }
}
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean IsMemberMap(Map M, keytype k){
    //Kamus Lokal
    int i;
    boolean found;
    //Algoritma
    i=0;
    found = false;
    while(i < M.Count && !found){
        if( isKataEqual(M.Elements[i].Key, k) ){
            found = true;
        }
        else{
            i +=1;
        }
    }
    return(found);
}
/* Mengembalikan true jika k adalah member dari M */


void MakeEmptyMapList (Map M[], int L) {
    /* I.S. Sembarang */
    /* F.S. Seluruh elemen array of Map M menjadi Map kosong.*/
    for (int i=0; i<L; i++) {
        CreateEmptyMap(&M[i]);
    }
}