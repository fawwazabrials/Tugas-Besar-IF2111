#include <stdio.h>
#include <stdlib.h>
#include "ADT/matriks.h"
#include "game_2048.h"

/* TODO : 1. Kalo ada 2 2 2 2 itu kecombine langsung jadi 8 0 0 0, harusnya 4 4 0 0
          2. Kalo user gak ngeinput, tetep muncul nilai baru
          3. Random 4 blom ada cuma 2 doang
          4. Ubah ke ADT Matriks?? */

// cd /d/ITB/"Semester 3"/Alstrukdat/Tugas-Besar-IF2111/bin

void run_2048() {
    // KAMUS LOKAL
    // Variabel untuk game
    Matriks board;
    int i, point_i, point_j, score=0;
    boolean wrong = false, loop = true;

    // Variabel placeholder untuk input
    Word kode, command2;
    int inputint;
    

    // ALGORITMA
    MakeMatriks(4, 4, &board);

    while (!isMatriksFull(board) && loop) {
        // clearScreen();
        if (wrong) printf("Masukkan kode yang benar!");
        else { // GENERATE NEW RANDOM NUMBER ON POINT
            point_i = randint(0, 3); point_j = randint(0, 3);
            while (Elmt(board, point_i, point_j) != 0) {
                point_i = randint(0, 3); point_j = randint(0, 3);
            }

            if (randint(0, 100) % 20 == 0) Elmt(board,point_i,point_j) = 4;
            else Elmt(board,point_i,point_j) = 2;
        }

        // Display game info ke player
        // clearScreen();
        printf("\n\n"); displayMatriks(board);
        printf("(W) Atas  (A) Kiri  (S) Bawah  (D) Kanan\n\nENTER COMMAND : ");
        scan("%c", &kode, &command2, &inputint);

        // printf("kode = ");
        // displayWord(kode);

        // Main algo buat gamenya
        wrong = false;
        if (ValidateCommand(kode, "W")) {
            for (i=0; i<board.NKolEff-1; i++) {
                geserMatriksAtas(&board, false);
                geserMatriksAtas(&board, true);
            }
        }
        else if (ValidateCommand(kode, "A")) {
            for (i=0; i<board.NKolEff-1; i++) {
                geserMatriksKiri(&board, false);
                geserMatriksKiri(&board, true);
            }
        }
        else if (ValidateCommand(kode, "S")) {
            for (i=0; i<board.NKolEff-1; i++) {
                geserMatriksBawah(&board, false);
                geserMatriksBawah(&board, true);
            }
        }
        else if (ValidateCommand(kode, "D")) {
            for (i=0; i<board.NKolEff-1; i++) {
                geserMatriksKanan(&board, false);
                geserMatriksKanan(&board, true);
            }
        }
        else if (ValidateCommand(kode, "QUIT")) loop = false;
        else wrong = true;
    }
}