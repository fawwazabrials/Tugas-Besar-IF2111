#include <stdio.h>
#include <stdlib.h>
#include "src/ADT/mesinkarakter.h"
#include "src/ADT/mesinkata.h"
#include "src/ADT/array.h"
#include "src/ADT/queue.h"
#include "src/functions.h"

int main() {
    // KAMUS LOKAL
    Word command1, command2;    // INPUT USER BERUPA COMMAND
    int inputint;               // INPUT USER BERUPA INTEGER

    TabWord games;              // Array untuk menyimpan game yang tersedia
    Queue antrian_game;         // Queue untuk menyimpan antrian game ketika BNMO berjalan

    boolean loop = true;
    int i, len;

    // ALGORITMA
    // Mengosongkan Array untuk games dan Queue untuk antrian game
    MakeEmpty(&games);
    CreateQueue(&antrian_game);

    while (loop) { // Looping menerima input untuk command SAVE dan LOAD
        printf("ENTER COMMAND : ");
        scan("%c %c", &command1, &command2, &inputint);

        if (ValidateCommand(command1, "START")) { // INPUT ADALAH START
            STARTWORDFILE("config.txt");
            len = katatoint(currentWord);
            for (i=1; i<=len; i++) {
                ADV();
                ADVWORDFILE();
                SetEl(&games, i, currentWord);
            }

            printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
            loop = false;
            // DisplayArray(games);
        }

        else if (ValidateCommand(command1, "LOAD")) { // INPUT ADALAH LOAD
            /* TODO : Tulis kode buat LOAD diatas sini, sebenernya tinggal 
             * copas SAVE aja tapi di STARTWORDFILE() nama filenya diganti 
             * sesuai masukan user, masukan nama file ada di command2 */
            
            printf("Save file berhasil dibaca. BNMO berhasil dijalankan.\n");
            loop = false;
        }

        else { // INPUT GAJELAS 
            printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
        }
    }

    loop = true; // Reset true untuk menu
    /* TODO : Taro looping menu dibawah ini, dalemnya validasi tiap command1 command2 
     * apakah sama dengan command yg tersedia, kalo iya panggil prosedur commandnya */
}