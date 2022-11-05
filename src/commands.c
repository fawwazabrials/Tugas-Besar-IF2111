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
    displayWord(currentWord);

    if (game_idx <= GetLastIdx(games) && game_idx >= GetFirstIdx(games)) {
        if (isFull(*game_queue)) printf("Daftar antrian game-mu sudah penuh! Silahkan skip game atau mainkan game terlebih dahulu.\n");
        else {
            displayWord(GetElmt(games, game_idx));
            enqueue(game_queue, GetElmt(games, game_idx));
            printf("Game berhasil ditambahkan kedalam daftar antrian.\n");
        }
    } else {
        printf("Nomor permainan tidak valid, silahkan masukkan nomor game pada list.\n");
    }
}

void list_game(TabWord list){
    /*
    Proses  : Membaca listglobal yang berisi nama nama game
              yang terdapat pada file
    I.S     : listglobal yang sudah terdefenisi
    F.S     : Menambilkan isi dari list ke layar
    */

   //Kamus Lokal

   //Algoritma
   printf("Berikut adalah daftar game yang tersedia");
   DisplayArray(list);
}

void quit() {
    /* I.S.: sembarang
    F.S.: Program dihentikan */
    printf("Anda keluar dari BNMO.\nBye bye 👋");
    return;
}

void PLAYGAME(Queue *game_queue)
{   
    if (!isEmpty(*game_queue)) //kalo game_queue gk kosong
    {
        printf("Berikut adalah daftar Game-mu\n");
    
        int i;
        int j = 0;
        for (i = (*game_queue).idxHead; i <= (*game_queue).idxTail; i++)
        {
            printf("%d. %s\n", i+1, (*game_queue).buffer[i]);
            j++;
        }

        ElTypeQueue gamename; //Tempat sampah pas dequeue
        char* r = "RNG";
        char* dd = "Diner Dash";
        
        if (isKataEqual((*game_queue).buffer[(*game_queue).idxHead], r))
        {
            printf("Loading %s ...\n", (*game_queue).buffer[(*game_queue).idxHead]);
            dequeue(game_queue, &gamename);
            run_rng();
        }

        else if (isKataEqual((*game_queue).buffer[(*game_queue).idxHead], dd))
        {
            printf("Loading %s ...\n", (*game_queue).buffer[(*game_queue).idxHead]);
            dequeue(game_queue, &gamename);
            dinerdash(); //ganti nama prosedur gamenya kalo dah jadi
        }
        
        else
        {
            printf("Game %s masih dalam maintenance, belum dapat dimainkan.\nSilakan pilih game lain.\n", (*game_queue).buffer[(*game_queue).idxHead]);
        }
    }
    else
    {
       QUEUEGAME(); //panggil prosedur QUEUEGAME jika game_queue kosong
    }
}

void SKIPGAME(Queue *game_queue)
{
    if (!isEmpty(*game_queue))
    {
        printf("Berikut adalah daftar Game-mu\n");
    
        int i;
        int j = 0;
        for (i = (*game_queue).idxHead; i <= (*game_queue).idxTail; i++)
        {
            printf("%d. %s\n", j, (*game_queue).buffer[i]);
            j++;
        }

        ADVWORD();
        int n = currentWord.TabWord[0] - '0';
        ElTypeQueue gamename; //tempat sampah pas dequeue

        if (n < length(*game_queue))
        {
            int i;
            for(i = (*game_queue).idxHead; i < n; i++)
            {
                dequeue(game_queue,&gamename);
            }

            PLAYGAME(); 
        }
        else
        {
            int i;
            for (i = (*game_queue).idxHead; i <= (*game_queue).idxTail; i++)
            {
                dequeue(game_queue,&gamename);
            }
            printf("Tidak ada permainan lagi dalam daftar game-mu.\n");
        }
    }

    else
    {
        QUEUEGAME(); //panggil prosedur QUEUEGAME jika game_queue kosong
    }
}
