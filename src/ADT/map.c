#include "stdio.h"
#include "map.h"

/* Definisi Map M kosong : M.Count = NilMap */
/* M.Count = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptyMap(Map *M){
    (*M).Count = NilMap;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count berNilMapai NilMap */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyMap(Map M){
    return((M).Count == NilMap);
}
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count berNilMapai NilMap */

boolean IsFullMap(Map M){
    return((M).Count == MaxEl);
}
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count berNilMapai MaxEl */

/* ********** Operator Dasar Map ********* */
valuetypeMap ValueMap(Map M, keytypeMap k){
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
/* Mengembalikan NilMapai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void InsertMap(Map *M, keytypeMap k, valuetypeMap v){
    infotypeMap el;
    el.Key =k; el.Value = v;
    int loc;
    if(!IsMemberMap(*M,k)){
        if (IsEmptyMap(*M)) {
            M->Elements[1] = el;
        } else {
            for (int i=1;i<=M->Count;i++) {
                loc = i;
                if (M->Elements[i].Value < v) {
                    for (int j=M->Count;j>=i;j++) {
                        M->Elements[j+1] = M->Elements[j];
                    }
                    break;
                }
            }
            M->Elements[loc] = el;
        }
        (*M).Count +=1;
    }
}
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k, terurut secara menurun berdasarkan value,
        jika ada anggota M lain dengan value yang sama, elemen yang lebih baru diletakkan belakangan.
        Jika k sudah ada, operasi tidak dilakukan */

void DeleteMap(Map *M, keytypeMap k){
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

boolean IsMemberMap(Map M, keytypeMap k){
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