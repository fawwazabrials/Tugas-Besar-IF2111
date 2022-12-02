#include "matriks.h"
#include "../../functions.h"
#include <stdio.h>

int main() {
    Matriks M,MCopy;
    int i,max,score;
    //MakeMatriks
    score = 0;

    MakeMatriks(4,4,&M);
    printf("MakeMatriks & Display Matriks\n");
    displayMatriks(M);
    
    /* M.Mem[0][3] = 2;
    M.Mem[1][3] = 0;
    M.Mem[2][3] = 0;
    M.Mem[3][3] = 2; */

    /* M.Mem[0][3] = 2;
    M.Mem[1][3] = 2;
    M.Mem[2][3] = 4;
    M.Mem[3][3] = 8; */

    M.Mem[0][3] = 2;
    M.Mem[1][3] = 2;
    M.Mem[2][3] = 2;
    M.Mem[3][3] = 2;
    printf("Mengisi Matriks manual\n");
    displayMatriks(M);

    //IsMatriksEmpty
    printf("\n");
    printf("IsEmptyMatriks\n");
    if(isMatriksEmpty(M)){
        printf("Matriks kosong\n");
    }
    else{
        printf("bukan matriks kosong dan makematriks berhasil\n");
    }

    //isMatriksFull
    printf("\n");
    printf("IsEMatriksFull\n");
    if(isMatriksFull(M)){
        printf("MAtriks full\n");
    }
    else{
        printf("matriks tidak full\n");
    } 

    //MaxinMatriks
    printf("\n");
    printf("MaxInMatriks\n");
    max = maxInMatriks(M);
    printf("%d adalah nilai max\n",max);

    //CopyMatriks & display matriks
    printf("\n");
    printf("CopyMatriks\n");
    printf("sebelum\n");
    MakeMatriks(4,4,&MCopy);
    printf(" matriks pertama\n");
    displayMatriks(M);
    printf(" matriks kedua\n");
    displayMatriks(MCopy);
    copyMatriks(M,&MCopy);
    printf("Sesudah");
    printf(" matriks pertama\n");
    displayMatriks(M);
    printf(" matriks kedua\n");
    displayMatriks(MCopy);

    //GESER MATRIKS
    printf("\n");
    printf("Geser matriks ke bawah\n");
    printf("sebelum\n");
    printf("Score = %d\n",score);
    displayMatriks(M);
    for(i=0;i<4;i++){
        geserMatriksBawah(&M,&score,true);
    }
    printf("Sesudah\n");
    printf("Score = %d\n",score);
    displayMatriks(M);

    printf("\n");
    printf("Geser matriks ke atas\n");
    printf("sebelum\n");
    printf("Score = %d\n",score);
    displayMatriks(M);
    for(i=0;i<4;i++){
        geserMatriksAtas(&M,&score,false);
    }
    printf("Sesudah\n");
    printf("Score = %d\n",score);
    displayMatriks(M);
    for (i=0; i<3; i++) {geserMatriksBawah(&M,&score,false);
    geserMatriksBawah(&M,&score,true);
    }

    printf("\n");
    printf("Geser matriks ke kanan\n");
    printf("sebelum\n");
    printf("Score = %d\n",score);
    displayMatriks(M);
    for(i=0;i<4;i++){
        geserMatriksKanan(&M,&score,false);
    }
    printf("Sesudah\n");
    printf("Score = %d\n",score);
    displayMatriks(M);
}