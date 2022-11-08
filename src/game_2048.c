#include <stdio.h>
#include <stdlib.h>
#include "game_2048.h"

/* TODO : 1. Kalo ada 2 2 2 2 itu kecombine langsung jadi 8 0 0 0, harusnya 4 4 0 0
          2. Kalo user gak ngeinput, tetep muncul nilai baru
          3. Random 4 blom ada cuma 2 doang
          4. Ubah ke ADT Matriks?? */

boolean isFullMatriks(int mat[4][4]) {
    // KAMUS LOKAL
    int i, j;

    // ALGORITMA
    for (i=0; i<4; i++) {
        for (j=0; j<4; j++) {
            if (mat[i][j] == 0) return false;
        }
    } return true;
}

void displayMatriks(int mat[4][4]) {
    // KAMUS LOKAL
    int i, j;

    // ALGORITMA
    for (i=0; i<4; i++) {
        for (j=0; j<4; j++) {
            printf("%6d\t", mat[i][j]);
        } printf("\n");
    }
}

void run_2048() {
    // KAMUS LOKAL
    int mat[4][4], i, j, x, point_i, point_j, maxi=-1;
    Word command1, command2;
    int kode;
    boolean wrong = false, loop = true;

    // ALGORITMA
    // createEmpty
    for (i=0; i<4; i++) {
        for (j=0; j<4; j++) {
            mat[i][j] = 0;
        }
    }

    while (!isFullMatriks(mat) && loop) {
        point_i = randint(0, 3);
        point_j = randint(0, 3);
        while (mat[point_i][point_j] != 0) {
            // printf("nilai = %d", mat[point_i][point_j]);
            point_i = randint(0, 3);
            point_j = randint(0, 3);
        }

        mat[point_i][point_j] = 2;
        system("clear");
        if (wrong) printf("Masukkan kode yang benar!");
        printf("\n\n");
        displayMatriks(mat);
        printf("(W) Atas\t(A) Kiri\t(S) Bawah\t(D) Kanan\n\nENTER COMMAND : ");
        scan("%c", &command1, &command2, &kode);

        if (ValidateCommand(command1, "D")) { // kanan
            for (i=0; i<4; i++) {
                for (x=3; x>0; x--) {
                    for (j=3; j>0; j--) {
                        if (mat[i][j] == 0) {
                            mat[i][j] = mat[i][j-1];
                            mat[i][j-1] = 0;
                        }
                        if (mat[i][j-1] == mat[i][j]) {
                            mat[i][j] += mat[i][j-1];
                            if (mat[i][j] > maxi) maxi = mat[i][j];
                            mat[i][j-1] = 0;
                        }
                    }
                }
                wrong = false;
            }
        } else if (ValidateCommand(command1, "A")) {
            // kiri
            for (i=0; i<4; i++) {
                for (x=3; x>0; x--) {
                    for (j=0; j<3; j++) {
                        if (mat[i][j] == 0) {
                            mat[i][j] = mat[i][j+1];
                            mat[i][j+1] = 0;
                        }
                        if (mat[i][j+1] == mat[i][j]) {
                            mat[i][j] += mat[i][j+1];
                            if (mat[i][j] > maxi) maxi = mat[i][j];
                            mat[i][j+1] = 0;
                        }
                    }
                }
                wrong = false;
            }
        } else if (ValidateCommand(command1, "W")) {
            // atas
            for (j=0; j<4; j++) {
                for (x=3; x>0; x--) {
                    for (i=0; i<3; i++) {
                        if (mat[i][j] == 0) {
                            mat[i][j] = mat[i+1][j];
                            mat[i+1][j] = 0;
                        }
                        if (mat[i+1][j] == mat[i][j]) {
                            mat[i][j] += mat[i+1][j];
                            if (mat[i][j] > maxi) maxi = mat[i][j];
                            mat[i+1][j] = 0;
                        }
                    }
                }
                wrong = false;
            }
        } else if (ValidateCommand(command1, "S")) {
            // bawah
            for (j=0; j<4; j++) {
                for (x=3; x>0; x--) {
                    for (i=3; i>0; i--) {
                        if (mat[i][j] == 0) {
                            mat[i][j] = mat[i-1][j];
                            mat[i-1][j] = 0;
                        }
                        if (mat[i-1][j] == mat[i][j]) {
                            mat[i][j] += mat[i-1][j];
                            if (mat[i][j] > maxi) maxi = mat[i][j];
                            mat[i-1][j] = 0;
                        }
                    }
                }
                wrong = false;
            }
        } 
        if (ValidateCommand(command1, "QUIT")) {
            loop = false;
        }
        else {
            wrong = true;
        }
    }

    printf("Skor-mu adalah %d!\n", maxi);
}