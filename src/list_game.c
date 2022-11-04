/* File : list_game.c */


#include "list_game.h"

void list_game(TabWord list){
    /*
    Proses  : Membaca listglobal yang berisi nama nama game
              yang terdapat pada file
    I.S     : listglobal yang sudah terdefenisi
    F.S     : Menambilkan isi dari list ke layar
    */

   //Kamus Lokal
   int i,j;

   //Algoritma
   j = 1;
   for(i=0;i<list.Neff;i++){
    printf("%d. %s\n",j,list.TI[i]);
    j +=1;
   }
}