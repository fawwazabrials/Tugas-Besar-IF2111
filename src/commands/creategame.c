/* CREATEGAME */

#include "../ADT/mesinkarakter.c"
#include "../ADT/mesinkarakter.h"
#include "../ADT/mesinkata.c"
#include "../ADT/mesinkata.h"
#include "../ADT/array.c"
#include "../ADT/array.h"
#include "../functions.c"

#include <stdlib.h>
#include <stdio.h>

Word CCommand;
Word ph1;
int ph2;

void CREATEGAME(TabWord T) {
    printf("Masukkan nama game yang akan ditambahkan: ");
    scan("%s", &CCommand, &ph1, &ph2);
    InsertLast(&T, CCommand);
    printf("Game berhasil ditambahkan\n");
}