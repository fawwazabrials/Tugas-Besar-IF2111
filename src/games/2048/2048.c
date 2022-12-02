#include <stdio.h>

#include "2048.h"

int run_2048() {
/* Implementasi permainan 2048 dalam C menggunakan ADT Matriks.
   I.S. : Sembarang
   F.S. : Game selesai dan skor akhir pemain ditampilkan pada layar */
    // KAMUS LOKAL
    // Variabel untuk game
    Matriks board, prev_board;
    int i, point_i, point_j, score=0, waktu_awal, waktu_akhir;
    boolean wrong = false, loop = true, undo = false;
    // Variabel placeholder untuk input
    Word kode, command2;
    int inputint;
    

    // ALGORITMA
    MakeMatriks(4, 4, &board);
    MakeMatriks(4, 4, &prev_board);
    waktu_awal = time(NULL);

    while (!isMatriksFull(board) && loop) {
        splashScreen();
        if (wrong) printf("Masukkan kode yang benar!");
        else { // GENERATE NEW RANDOM NUMBER ON POINT
            if (!undo) {
                point_i = randint(0, 3); point_j = randint(0, 3);
                while (Elmt(board, point_i, point_j) != 0) {
                    point_i = randint(0, 3); point_j = randint(0, 3);
                }

                if (randint(0, 100) % 20 == 0) Elmt(board,point_i,point_j) = 4;
                else Elmt(board,point_i,point_j) = 2;
            }
        }

        // Display game info ke player
        printf("\n\n"); displayMatriks(board);
        printf("\n(W) Atas  (A) Kiri  (S) Bawah  (D) Kanan\n(QUIT) Untuk keluar dari game\n(UNDO) Mengembalikan game ke state sebelumnya (Hanya dapat dilakukan maksimal 1x tiap turn)\n\nENTER COMMAND : ");
        scan("%c", &kode, &command2, &inputint);

        // Main algo buat gamenya
        wrong = false;
        if (ValidateCommand(kode, "QUIT")) loop = false;
        else if (ValidateCommand(kode, "UNDO")) {
            copyMatriks(prev_board, &board);
            undo = true; 
        } else {
            copyMatriks(board, &prev_board);
            undo = false;

            if (ValidateCommand(kode, "W")) {
                for (i=0; i<board.NKolEff; i++) geserMatriksAtas(&board, &score, false);
                geserMatriksAtas(&board, &score, true);
                for (i=0; i<board.NKolEff; i++) geserMatriksAtas(&board, &score, false);
            }
            else if (ValidateCommand(kode, "A")) {
                for (i=0; i<board.NKolEff; i++) geserMatriksKiri(&board, &score, false);
                geserMatriksKiri(&board, &score, true);
                for (i=0; i<board.NKolEff; i++) geserMatriksKiri(&board, &score, false);

            }
            else if (ValidateCommand(kode, "S")) {
                for (i=0; i<board.NKolEff; i++) geserMatriksBawah(&board, &score, false);
                geserMatriksBawah(&board, &score, true);
                for (i=0; i<board.NKolEff; i++) geserMatriksBawah(&board, &score, false);

            }
            else if (ValidateCommand(kode, "D")) {
                for (i=0; i<board.NKolEff; i++) geserMatriksKanan(&board, &score, false);
                geserMatriksKanan(&board, &score, true);
                for (i=0; i<board.NKolEff; i++) geserMatriksKanan(&board, &score, false);
            }
            else wrong = true;
        }
    }

    waktu_akhir = time(NULL);
    printf("\n\nGAME OVER!\nSkor-mu adalah %d\nWaktu bermain %02d:%02d\n\n", score, (waktu_akhir-waktu_awal)/60, (waktu_akhir-waktu_awal)%60);
    return score;

}