#include "../../src/ADT/queue.h"

int main() {
    Queue Q;
    CreateQueue(&Q);

    STARTWORD();
    while (!EndWord) {
        enqueue(&Q, currentWord);
        ADVWORD();
    }

    dequeue(&Q, &currentWord);

    DisplayQueue(Q);
}