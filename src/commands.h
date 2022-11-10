#ifndef MENU_COMMANDS_H
#define MENU_COMMANDS_H

#include "functions.h"
#include "ADT/array.h"
#include "ADT/boolean.h"
#include "ADT/mesinkarakter.h"
#include "ADT/mesinkata.h"
#include "ADT/queue.h"

void QUEUEGAME(TabWord games, Queue* game_queue);

void list_game (TabWord list);
    /*
    Proses  : Membaca listglobal yang berisi nama-nama game
              yang terdapat pada file
    I.S     : listglobal yang sudah terdefenisi
    F.S     : Menambilkan isi dari list ke layar
    */

void PLAYGAME(TabWord games, Queue *game_queue);
/*I.S. : game_queue terdefinisi
  F.S. : game_queue terdequeue dan dijalankan
  Proses : mengeluarkan game dari queue dan menjalankannya
*/

void SKIPGAME(TabWord games, Queue *game_queue);
/*I.S. : game_queue terdefinisi
F.S. : mengskip n buah game sesuai langkah yang diinginkan dari queue dan menjalankan game jika ada di game_queue
Proses :game_queue terdequeue sesuai berapa langkah skip yang diinginkan dan menjalankan game selanjutnya jika masih ada game di game_queue*/

void CREATEGAME(TabWord *T);

void DELETEGAME(TabWord *gl, Queue gq);

void SAVE(TabWord gl, Word filename);

void help();

void START (Word a,TabWord *T);
#endif
