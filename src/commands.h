#ifndef MENU_COMMANDS_H
#define MENU_COMMANDS_H

#include "functions.h"
#include "games/rng/RNG.h"
#include "games/2048/2048.h"
#include "games/random/random.h"
#include "games/dinerdash/dinerdash.h"
#include "games/hangman/hangman.h"
#include "games/hanoi/towerofhanoi.h"
#include "games/snake/snake.h"
#include "games/labtekhunt/labtekhunt.h"
#include "ADT/array/array.h"
#include "ADT/boolean/boolean.h"
#include "ADT/mesinkarakter/mesinkarakter.h"
#include "ADT/mesinkata/mesinkata.h"
#include "ADT/queue/queue.h"
#include "ADT/stack/stack.h"
#include "ADT/map/map.h"
#include "ADT/set/set.h"

void QUEUEGAME(TabWord games, Queue* game_queue);
/* Memasukan game yang dipilih user ke dalam antrian game untuk dimainkan.
   I.S. : games dan game_queue terdefinisi 
   F.S. : Game yang dipilih oleh user akan masuk ke dalam game_queue*/

void list_game (TabWord list);
/* Proses  : Membaca listglobal yang berisi nama nama game
            yang terdapat pada file
   I.S     : listglobal yang sudah terdefenisi
   F.S     : Menambilkan isi dari list ke layar */

void PLAYGAME(TabWord games, Queue *game_queue, Stack *history, Map scoreboard[]);
/*I.S. : game_queue, games, history, scoreboard[] terdefinisi
  F.S. : game_queue terdequeue dan dijalankan
  Proses : mengeluarkan game dari queue dan menjalankannya */

void SKIPGAME(TabWord games, Queue *game_queue, int n, Stack *history, Map scoreboard[]);
/*I.S. : game_queue terdefinisi
F.S. : mengskip n buah game sesuai langkah yang diinginkan dari queue dan menjalankan game jika ada di game_queue
Proses :game_queue terdequeue sesuai berapa langkah skip yang diinginkan dan menjalankan game selanjutnya jika masih ada game di game_queue*/

void CREATEGAME(TabWord *T);
/* Menciptakan game baru yang bila dimainkan langsung menunjukan skor 
   I.S. : Sembarang 
   F.S. : Game tercipta dan masuk ke array game, nama game yang masuk sesuai dari input user */

void DELETEGAME (TabWord *gl, Queue gq, Stack *history, Map scoreboard[]);
/* Menghapus game yang ingin dihapus oleh user dengan syarat game harus hasil dari CREATE GAME
   I.S. : Sembarang 
   F.S. : Jika game merupakan hasil buatan user dari CREATE GAME, game berhasil dihapuskan 
          Jika game merupakan game bawaan dari file konfigurasi, game gagal dihapus */

void SAVE(TabWord gl, Word filename, Stack history, Map scoreboard[]);
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

void LOAD (Word command2, TabWord *T, Stack *history, Map score[]);
/* Membaca file dengan nama yang diinginkan user pada folder data dan memasukan isinya ke Array games
   I.S. : Sembarang
   F.S. : Jika file berhasil dibaca, isi dari Array game berisikan isi file.txt
          Jika file gagal dibaca, Array games tidak akan diisi dan memiliki Neff = 0 */

void HISTORY(TabWord games, Stack *game_history, int n);
/* Menampilkan n langkah terakhir dari game yang sedang dimainkan
   I.S. : Sembarang
   F.S. : Jika game_history tidak kosong, n langkah terakhir dari game yang sedang dimainkan akan ditampilkan
          Jika game_history kosong, tidak ada perubahan pada layar */

void SCOREBOARD (Map M[], TabWord gl);
/* Menampilkan scoreboard setiap permainan */

void RESETSCOREBOARD (Map M[], TabWord gl);
/* Melakukan reset pada salah satu game atau semua game di scoreboard. */
/* I.S. Scoreboard terdefinisi */
/* F.S. Elemen-elemen pada salah satu atau semua scoreboard dihapus */

void RESETHISTORY(Stack *game_history, TabWord games);
/* Melakukan reset pada stack history game yang pernah dimainkan
   I.S. : Sembarang, user sudah memilih YA
   F.S. : Stack game_history tidak memiliki elemen lagi */

#endif
