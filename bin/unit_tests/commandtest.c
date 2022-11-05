#include <stdio.h>
#include <stdlib.h>
#include "../../src/ADT/mesinkarakter.h"
#include "../../src/ADT/queue.h"
#include "../../src/ADT/mesinkata.h"
#include "../../src/ADT/array.h"
#include "../../src/functions.h"
#include "../../src/commands.h"

void ultidisplay(Queue Q, TabWord T) {
    printf("HASIL SETELAH :\n");
    printf("GAMES:\n");
    DisplayArray(T);
    printf("QUEUE:\n");
    DisplayQueue(Q);
    printf("\n");
}

int main() {
    return 0;
}