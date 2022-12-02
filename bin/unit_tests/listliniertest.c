#include "../../src/ADT/listlinier.h"
#include <stdio.h>

int main() {
    List L;
    CreateEmptyListL(&L);
    infotypeLL Xdel, Ydel;

    printf("================== DRIVER LIST LINIER ==================\n");
    if (IsListLEmpty(L)) {
        printf("** List kosong\n");
    }
    printf("** Testing prosedur InsVFirst.\n");
    printf("** Inserting a point of (1,2) and (3,4) in that order\n");
    InsVFirst(&L, 1, 2);
    InsVFirst(&L, 3, 4);
    printf("\n** Expected outcome: [(3,4),(1,2)]\n");
    PrintInfoListL(L);
    printf("\n** Testing prosedur InsVLast\n");
    printf("** Inserting a point of (5,6)\n");
    InsVLast(&L, 5, 6);
    printf("\n** Expected outcome: [(3,4),(1,2),(5,6)]\n");
    PrintInfoListL(L);

    printf("\n** Testing DelVFirst\n");
    DelVFirst(&L, &Xdel, &Ydel);
    printf("** Expected outcome: [(1,2),(5,6)]\n");
    PrintInfoListL(L);
    DelVLast(&L, &Xdel, &Ydel);
    printf("\n** Testing DelVLast\n");
    printf("** Expected outcome: [(1,2)]\n");
    PrintInfoListL(L);
    return 0;
}