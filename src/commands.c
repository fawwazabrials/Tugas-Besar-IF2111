#include "commands.h"

void QUEUEGAME(TabWord games, Queue* game_queue) {
    int game_idx;

    printf("Berikut adalah daftar antrian game-mu\n");
    DisplayQueue(*game_queue);
    printf("\n");
    printf("Berikut adalah daftar game yang tersedia\n");
    DisplayArray(games);
    printf("\n");

    printf("Nomor game yang mau ditambahkan ke antrian: ");
    STARTWORD();
    game_idx = katatoint(currentWord);

    if (game_idx <= GetLastIdx(games) && game_idx >= GetFirstIdx(games)) {
        if (isFull(*game_queue)) printf("Daftar antrian game-mu sudah penuh! Silahkan skip game atau mainkan game terlebih dahulu.\n");
        else {
            enqueue(game_queue, GetElmt(games, game_idx));
            printf("Game berhasil ditambahkan kedalam daftar antria.n\n");
        }
    } else {
        printf("Nomor permainan tidak valid, silahkan masukkan nomor game pada list.\n");
    }
}