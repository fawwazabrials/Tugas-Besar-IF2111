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
void quit();
    /* I.S.: sembarang
    F.S.: Program dihentikan */

void PLAYGAME(TabWord games, Queue *game_queue);

void SKIPGAME(TabWord games, Queue *game_queue);

void CREATEGAME(TabWord *T);

void help();

void START (Word a,TabWord *T);
#endif
