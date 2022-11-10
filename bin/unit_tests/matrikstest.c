#include "../../src/ADT/matriks.h"
#include "../../src/functions.h"
#include <stdio.h>

int main() {
    Matriks M;
    int i, placeholder=0;

    MakeMatriks(4,4,&M);
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

    displayMatriks(M);

    for (i=0; i<3; i++) geserMatriksBawah(&M, false, &placeholder);
    geserMatriksBawah(&M, true, &placeholder);
    for (i=0; i<3; i++) geserMatriksBawah(&M, false, &placeholder);

    displayMatriks(M);
}