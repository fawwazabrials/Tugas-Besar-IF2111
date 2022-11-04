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
    Proses  : Membaca listglobal yang berisi nama nama game
              yang terdapat pada file
    I.S     : listglobal yang sudah terdefenisi
    F.S     : Menambilkan isi dari list ke layar
    */

#endif