#include <stdio.h>
#include <stdlib.h>
#include "src/ADT/mesinkarakter.h"
#include "src/ADT/mesinkata.h"
#include "src/ADT/array.h"
#include "src/ADT/queue.h"
#include "src/functions.h"
#include "src/commands.h"

int main() {
    // KAMUS LOKAL
    Word command1, command2;    // INPUT USER BERUPA COMMAND
    int inputint;               // INPUT USER BERUPA INTEGER

    TabWord games;              // Array untuk menyimpan game yang tersedia
    Queue antrian_game;         // Queue untuk menyimpan antrian game ketika BNMO berjalan

    boolean working = false;    // boolean untuk mengecek apakah user sudah melakukkan start ataupun melakukkan load
    int i, len;

    // ALGORITMA
    //landing page
     printf("______    __    _____ ________  ______    ___________   _______________ ___    _____  ________ \n");
    printf("\\   \\__  /\\__  /  __ /   ____  /   __    /        __   /   ____    __  /   \\  /   __   \\   ____ \n");        
    printf(" \\   \\  /  \\__/  __ /   /___  /   __    /    ______   /   /   /   __  /     \\/     __   \\   \\___ \n");    
    printf("  \\   \\/    \\/  __ /   ____  /   __    /    /_____   /   /   /   __  /   /\\    /\\   __   \\   ____ \n"); 
    printf("   \\     /\\    __ /   /___  /   ____  /       __    /   /___/   __  /   /  \\  /  \\   __   \\   \\___ \n");
    printf("    \\___/__\\____ /_______  /________ /_________    /_____________  /___/    \\/    \\_____   \\_______ \n");
    printf("BNMO  |KELOMPOK 7 \n  ");
    printf("\n");
    printf("Start a new game(START) | load your previous data (LOAD \"namafile\") | Help(HELP) | Quit(QUIT) \n");
    printf("ENTER COMMAND : ");

    // Mengosongkan Array untuk games dan Queue untuk antrian game
    MakeEmpty(&games);
    CreateQueue(&antrian_game);

    //inputan awal
    printf("ENTER COMMAND : ");
    scan("%c %c", &command1, &command2, &inputint);
    while (!(ValidateCommand(command1, "QUIT"))) { // Looping menerima input untuk command SAVE dan LOAD

        if (ValidateCommand(command1, "START")) { // INPUT ADALAH START
            STARTWORDFILE("config.txt");
            len = katatoint(currentWord);
            for (i=1; i<=len; i++) {
                ADV();
                ADVWORDFILE();
                SetEl(&games, i, currentWord);
            }

            printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
            working = true;
            printf("Create game(CREATE GAME) | Save your  data (save \"namafile\") | Help(HELP)\n");\
            printf("Quit(QUIT)               | List game(LIST GAME)                | Delete Game (DELETE GAME)  \n");
            printf("Queue Game(QUEUE GAME)   | Play game(PLAY GAME)                | Skip Game(SKIP GAME)\n");
            printf("ENTER COMMAND : ");
            scan("%c %c", &command1, &command2, &inputint);
            // DisplayArray(games);
        }

        else if (ValidateCommand(command1, "LOAD")) { // INPUT ADALAH LOAD
            /* TODO : Tulis kode buat LOAD diatas sini, sebenernya tinggal 
             * copas SAVE aja tapi di STARTWORDFILE() nama filenya diganti 
             * sesuai masukan user, masukan nama file ada di command2 */
            //fungsi load
            printf("Save file berhasil dibaca. BNMO berhasil dijalankan.\n");
            working = true;
            printf("Create game(CREATE GAME) | Save your  data (save \"namafile\") | Help(HELP)\n");\
            printf("Quit(QUIT)               | List game(LIST GAME)                | Delete Game (DELETE GAME)  \n");
            printf("Queue Game(QUEUE GAME)   | Play game(PLAY GAME)                | Skip Game(SKIP GAME)\n");
            printf("ENTER COMMAND : ");
            scan("%c %c", &command1, &command2, &inputint);
        }
        else if(ValidateCommand(command1, "HELP") && working){//INPUT ADALAH HELP
            //fungsi help
            printf("Create game(CREATE GAME) | Save your  data (save \"namafile\") | Help(HELP)\n");\
            printf("Quit(QUIT)               | List game(LIST GAME)                | Delete Game (DELETE GAME)  \n");
            printf("Queue Game(QUEUE GAME)   | Play game(PLAY GAME)                | Skip Game(SKIP GAME)\n");
            printf("ENTER COMMAND : ");
            scan("%c %c", &command1, &command2, &inputint);
        }
        else if(ValidateCommand(command1, "HELP") && !working){//INPUT ADALAH HELP
            //fungsi help
            printf("Start a new game(START) | load your previous data (LOAD 'namafile') | Help(HELP) | Quit(QUIT) \n");
            printf("ENTER COMMAND : ");
            scan("%c %c", &command1, &command2, &inputint);
        }
        else if(ValidateCommand(command1, "CREATE") && ValidateCommand(command2, "GAME") && working ){//INPUT ADALAH CREATE GAME
            // fungsi create game
            printf("Create game(CREATE GAME) | Save your  data (save \"namafile\") | Help(HELP)\n");\
            printf("Quit(QUIT)               | List game(LIST GAME)                | Delete Game (DELETE GAME)  \n");
            printf("Queue Game(QUEUE GAME)   | Play game(PLAY GAME)                | Skip Game(SKIP GAME)\n");
            printf("ENTER COMMAND : ");
            scan("%c %c", &command1, &command2, &inputint);
        }
        else if(ValidateCommand(command1, "SAVE") && working){//INPUT ADALAH SAVE
            //fungsi save
            printf("Create game(CREATE GAME) | Save your  data (save \"namafile\") | Help(HELP)\n");\
            printf("Quit(QUIT)               | List game(LIST GAME)                | Delete Game (DELETE GAME)  \n");
            printf("Queue Game(QUEUE GAME)   | Play game(PLAY GAME)                | Skip Game(SKIP GAME)\n");
            printf("ENTER COMMAND : ");
            scan("%c %c", &command1, &command2, &inputint);
        }
        else if(ValidateCommand(command1, "LIST") && ValidateCommand(command2, "GAME") && working){//INPUT ADALAH LIST GAME
            //fungsi list game
            printf("Create game(CREATE GAME) | Save your  data (save \"namafile\") | Help(HELP)\n");\
            printf("Quit(QUIT)               | List game(LIST GAME)                | Delete Game (DELETE GAME)  \n");
            printf("Queue Game(QUEUE GAME)   | Play game(PLAY GAME)                | Skip Game(SKIP GAME)\n");
            printf("ENTER COMMAND : ");
            scan("%c %c", &command1, &command2, &inputint);
        }
        else if(ValidateCommand(command1, "DELETE") && ValidateCommand(command2, "GAME") && working){//INPUT ADALAH DELETE GAME
            //fungsi delete game
            printf("Create game(CREATE GAME) | Save your  data (save \"namafile\") | Help(HELP)\n");\
            printf("Quit(QUIT)               | List game(LIST GAME)                | Delete Game (DELETE GAME)  \n");
            printf("Queue Game(QUEUE GAME)   | Play game(PLAY GAME)                | Skip Game(SKIP GAME)\n");
            printf("ENTER COMMAND : ");
            scan("%c %c", &command1, &command2, &inputint);
        }
        else if(ValidateCommand(command1, "QUEUE") && ValidateCommand(command2, "GAME") && working){//INPUT ADALAH QUEUE GAME
            //fungsi queue game
            printf("Create game(CREATE GAME) | Save your  data (save \"namafile\") | Help(HELP)\n");\
            printf("Quit(QUIT)               | List game(LIST GAME)                | Delete Game (DELETE GAME)  \n");
            printf("Queue Game(QUEUE GAME)   | Play game(PLAY GAME)                | Skip Game(SKIP GAME)\n");
            printf("ENTER COMMAND : ");
            scan("%c %c", &command1, &command2, &inputint);
        }
        else if(ValidateCommand(command1, "PLAY") && ValidateCommand(command2, "GAME") && working){//INPUT ADALAH PLAY GAME
            //fungsi play game
            printf("Create game(CREATE GAME) | Save your  data (save \"namafile\") | Help(HELP)\n");\
            printf("Quit(QUIT)               | List game(LIST GAME)                | Delete Game (DELETE GAME)  \n");
            printf("Queue Game(QUEUE GAME)   | Play game(PLAY GAME)                | Skip Game(SKIP GAME)\n");
            printf("ENTER COMMAND : ");
            scan("%c %c", &command1, &command2, &inputint);
        }
        else if(ValidateCommand(command1, "SKIP") && ValidateCommand(command2, "GAME") && working){//INPUT ADALAH SKIP GAME
            //fungsi skip game
            printf("Create game(CREATE GAME) | Save your  data (save \"namafile\") | Help(HELP)\n");\
            printf("Quit(QUIT)               | List game(LIST GAME)                | Delete Game (DELETE GAME)  \n");
            printf("Queue Game(QUEUE GAME)   | Play game(PLAY GAME)                | Skip Game(SKIP GAME)\n");
            printf("ENTER COMMAND : ");
            scan("%c %c", &command1, &command2, &inputint);
        }
        else if(!(ValidateCommand(command1, "QUIT") && !working)){ // INPUT GAJELAS 
            printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
            printf("Start a new game(START) | load your previous data (LOAD \"namafile\") | Help(HELP) | Quit(QUIT) \n");
            printf("ENTER COMMAND : ");
            scan("%c %c", &command1, &command2, &inputint);
        }
        else if(!(ValidateCommand(command1, "QUIT") && !working)){ //INPUT GAJELAS
            printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
            printf("Create game(CREATE GAME) | Save your  data (save \"namafile\") | Help(HELP)\n");\
            printf("Quit(QUIT)               | List game(LIST GAME)                | Delete Game (DELETE GAME)  \n");
            printf("Queue Game(QUEUE GAME)   | Play game(PLAY GAME)                | Skip Game(SKIP GAME)\n");
            printf("ENTER COMMAND : ");
            scan("%c %c", &command1, &command2, &inputint);
        }
    }
    printf("Anda keluar dari game BNMO.\n");
    printf("Bye bye ...\n");
    working = false;
    return 0;
     // Reset true untuk menu
    /* TODO : Taro looping menu dibawah ini, dalemnya validasi tiap command1 command2 
     * apakah sama dengan command yg tersedia, kalo iya panggil prosedur commandnya */
}