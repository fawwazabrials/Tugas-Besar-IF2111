#include "../../src/ADT/listlinier.c"
#include <stdio.h>

int main() {
    printf("================== DRIVER LIST LINIER ==================\n");
    List L;
    CreateEmptyListL(&L);
    if (IsListLEmpty(L)) {
        printf("List kosong\n");
    }
    printf("Testing prosedur InsVFirst.\n");
    InsVFirst(&L, 1, 2);
    InsVFirst(&L, 3, 4);
    InsVLast(&L, 5, 6);
    printf("Expected outcome: [(3,4),(1,2),(5,6)]\n");
    PrintInfoListL(L);

    return 0;
}