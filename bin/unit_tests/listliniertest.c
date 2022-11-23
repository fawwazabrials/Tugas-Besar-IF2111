#include "../../src/ADT/listlinier.h"
#include "../../src/ADT/listlinier.c"
#include <stdio.h>

int main() {
    printf("================== DRIVER LIST LINIER ==================\n");
    List L;
    CreateEmpty(&L);
    if (IsEmpty(L)) {
        printf("List kosong\n");
    }
    printf("Testing prosedur InsVFirst.\n");
    InsVFirst(&L, 1, 2);
    InsVFirst(&L, 3, 4);
    InsVLast(&L, 5, 6);
    printf("Expected outcome: [(3,4),(1,2),(5,6)]\n");
    PrintInfo(L);

    return 0;
}