#include <stdio.h>
#include <stdlib.h>
#include "../../src/ADT/mesinkarakter.h"
#include "../../src/ADT/mesinkata.h"
#include "../../src/functions.h"

int main() {
    Word command1, command2;
    int inputint;

    printf("ENTER COMMAND : ");
    scan("%c %c %d", &command1, &command2, &inputint);
    while (!ValidateCommand(command1, "")) {
        printf("command1 adalah : "); displayWord(command1);
        printf("command2 adalah : "); displayWord(command2);
        printf("inputint adalah : %d\n", inputint);

        printf("ENTER COMMAND : ");
        scan("%c %c %d", &command1, &command2, &inputint);
    }
}