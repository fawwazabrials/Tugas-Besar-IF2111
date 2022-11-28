#ifndef MENU_COMMANDS_H
#define MENU_COMMANDS_H

#include "functions.h"
#include "games/RNG.h"
#include "games/2048.h"
#include "games/random.h"
#include "games/dinerdash.h"
#include "ADT/array.h"
#include "ADT/boolean.h"
#include "ADT/mesinkarakter.h"
#include "ADT/mesinkata.h"
#include "ADT/queue.h"
#include "ADT/stack.h"

void QUEUEGAME(TabWord games, Queue* game_queue);
/* Memasukan game yang dipilih user ke dalam antrian game untuk dimainkan.
   I.S. : games dan game_queue terdefinisi 
   F.S. : Game yang dipilih oleh user akan masuk ke dalam game_queue*/

void list_game (TabWord list);
/* Proses  : Membaca listglobal yang berisi nama nama game
            yang terdapat pada file
   I.S     : listglobal yang sudah terdefenisi
   F.S     : Menambilkan isi dari list ke layar */

void PLAYGAME(TabWord games, Queue *game_queue);
/*I.S. : game_queue terdefinisi
  F.S. : game_queue terdequeue dan dijalankan
  Proses : mengeluarkan game dari queue dan menjalankannya */

void SKIPGAME(TabWord games, Queue *game_queue);
/*I.S. : game_queue terdefinisi
F.S. : mengskip n buah game sesuai langkah yang diinginkan dari queue dan menjalankan game jika ada di game_queue
Proses :game_queue terdequeue sesuai berapa langkah skip yang diinginkan dan menjalankan game selanjutnya jika masih ada game di game_queue*/

void CREATEGAME(TabWord *T);
/* Menciptakan game baru yang bila dimainkan langsung menunjukan skor 
   I.S. : Sembarang 
   F.S. : Game tercipta dan masuk ke array game, nama game yang masuk sesuai dari input user */

void DELETEGAME(TabWord *gl, Queue gq);
/* Menghapus game yang ingin dihapus oleh user dengan syarat game harus hasil dari CREATE GAME
   I.S. : Sembarang 
   F.S. : Jika game merupakan hasil buatan user dari CREATE GAME, game berhasil dihapuskan 
          Jika game merupakan game bawaan dari file konfigurasi, game gagal dihapus */

void SAVE(TabWord gl, Word filename);
/* Menyimpan isi dari Array game ke sebuah file '.txt' dengan nama file berupa input dari user
   I.S. : Sembarang 
   F.S. : File filename.txt berhasil tercipta di folder data dengan isinya adalah isi dari array game */

void help();
/* Mencetak cara menuliskan command dan penjelasan dari command ke layar 
   I.S. : Sembarang 
   F.S. : Penjelasan seluruh command tercetak pada layar */

void C_START(Word a,TabWord *T);
/* Membaca file config.txt pada folder data dan memasukan isinya ke Array games
   I.S. : Sembarang
   F.S. : Isi dari config.txt masuk ke Array game */

void LOAD(Word command2, TabWord *T);
/* Membaca file dengan nama yang diinginkan user pada folder data dan memasukan isinya ke Array games
   I.S. : Sembarang
   F.S. : Jika file berhasil dibaca, isi dari Array game berisikan isi file.txt
          Jika file gagal dibaca, Array games tidak akan diisi dan memiliki Neff = 0 */

void SCOREBOARD (Map M, TabWord gl);
/* Menampilkan scoreboard setiap permainan */

#endif
