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

    boolean loop= true;
    int i, len;

    // ALGORITMA
    // Mengosongkan Array untuk games dan Queue untuk antrian game

    clearScreen();

    printf("______    __    _____ ________  ______    ___________   _______________ ___    _____  ________ \n");
    printf("\\   \\__  /\\__  /  __ /   ____  /   __    /        __   /   ____    __  /   \\  /   __   \\   ____ \n");        
    printf(" \\   \\  /  \\__/  __ /   /___  /   __    /    ______   /   /   /   __  /     \\/     __   \\   \\___ \n");    
    printf("  \\   \\/    \\/  __ /   ____  /   __    /    /_____   /   /   /   __  /   /\\    /\\   __   \\   ____ \n"); 
    printf("   \\     /\\    __ /   /___  /   ____  /       __    /   /___/   __  /   /  \\  /  \\   __   \\   \\___ \n");
    printf("    \\___/__\\____ /_______  /________ /_________    /_____________  /___/    \\/    \\_____   \\_______ \n");
    printf("                                            BNMO  |  KELOMPOK 7 \n  ");
    printf("\n");
    printf("(START) Start a new game | (LOAD \"namafile\") Load your previous data | (HELP) Help | (QUIT) Quit\n");

    MakeEmpty(&games);
    CreateQueue(&antrian_game);

    while (loop) {
        printf("\n---- ENTER COMMAND : ");
        scan("%c %c", &command1, &command2, &inputint);

        if (ValidateCommand(command1, "START")) {           // INPUT ADALAH START
            C_START(command1,&games);
            splashScreen();
            printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
            loop = false;
            // DisplayArray(games);
        }

        else if (ValidateCommand(command1, "LOAD")) {       // INPUT ADALAH LOAD
            LOAD(command2, &games);
            if (games.Neff == 0) printf("Save file tidak ditemukan, silahkan masukkan nama file yang benar.\n");
            else {
                splashScreen();
                printf("Save file berhasil dibaca. BNMO berhasil dijalankan.\n");
                loop = false;
            }
        }

        else if(ValidateCommand(command1,"HELP")){          // INPUT ADALAH HELP
            help();
        }

        else if(ValidateCommand(command1,"QUIT")){          // INPUT ADALAH QUIT
            loop = false;
        }

        else{                                               // INPUT GAJELAS 
            printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
        }
    }

    loop = true;
    if (!ValidateCommand(command1,"QUIT")){
        while(loop){
            printf("\n===== ENTER COMMAND : ");
            scan("%c %c %d", &command1, &command2, &inputint);

            if(ValidateCommand(command1,"HELP")){                                               // INPUT ADALAH HELP
                splashScreen();
                help();
            }
            else if(ValidateCommand(command1,"CREATE") && ValidateCommand(command2,"GAME")) {   // INPUT ADALAH CREATE GAME
                splashScreen();
                CREATEGAME(&games);
            }
            else if(ValidateCommand(command1,"LIST") && ValidateCommand(command2,"GAME")) {     // INPUT ADALAH LIST GAME
                splashScreen();
                list_game(games);
            }
            else if(ValidateCommand(command1,"DELETE") && ValidateCommand(command2,"GAME")) {   // INPUT ADALAH DELETE GAME
                splashScreen();
                DELETEGAME(&games,antrian_game);
            }
            else if(ValidateCommand(command1,"QUEUE") && ValidateCommand(command2,"GAME")) {    // INPUT ADALAH QUEUE GAME
                splashScreen();
                QUEUEGAME(games,&antrian_game);
            }
            else if(ValidateCommand(command1,"PLAY") && ValidateCommand(command2,"GAME")) {     // INPUT ADALAH PLAY GAME
                splashScreen();
                PLAYGAME(games,&antrian_game);
            }
            else if(ValidateCommand(command1,"SKIP") && ValidateCommand(command2,"GAME")) {     // INPUT ADALAH SKIP GAME
                splashScreen();
                SKIPGAME(games,&antrian_game);
            }
            else if(ValidateCommand(command1,"SAVE")) {                                         // INPUT ADALAH SAVE
                splashScreen();
                SAVE(games, command2);
            }
            else if(ValidateCommand(command1,"QUIT")) {                                         // INPUT ADALAH QUIT
                loop = false;
            }
            else{                                                                               // IMPUT GAK JELAS
                printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
            }
        }
    }

    // quit();
    return 0;
}