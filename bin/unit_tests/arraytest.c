#include "../../src/ADT/array.h"

int main() {
    TabWord T;
    int i=1;
    MakeEmpty(&T);

    STARTWORD();
    while (!EndWord) {
        SetEl(&T, i++, currentWord);
        ADVWORD();
    }

    TulisIsi(T);
    
}