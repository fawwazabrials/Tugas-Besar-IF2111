#include "commands.h"

Word CCommand;
Word ph1;       // placeholder for 'scan' function
int ph2;        // placeholder for 'scan' function

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

void PLAYGAME(TabWord games, Queue *game_queue)
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
        
        if (ValidateCommand((*game_queue).buffer[(*game_queue).idxHead], r))
        {
            printf("Loading %s ...\n", (*game_queue).buffer[(*game_queue).idxHead]);
            dequeue(game_queue, &gamename);
            run_rng();
        }

        else if (ValidateCommand((*game_queue).buffer[(*game_queue).idxHead], dd))
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
       QUEUEGAME(games, game_queue); //panggil prosedur QUEUEGAME jika game_queue kosong
    }
}

void SKIPGAME(TabWord games, Queue *game_queue)
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

            PLAYGAME(games, game_queue); 
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
        QUEUEGAME(games, game_queue); //panggil prosedur QUEUEGAME jika game_queue kosong
    }
}

void CREATEGAME(TabWord *T) {
    printf("Masukkan nama game yang akan ditambahkan: ");
    scan("%s", &CCommand, &ph1, &ph2);
    InsertLast(T, CCommand);
    printf("Game berhasil ditambahkan\n");
}

void DELETEGAME (TabWord *gl, Queue gq) {
    list_game(*gl); // Cetak daftar game
    // Input
    printf("\n");
    printf("Masukkan nomor game yang akan dihapus: ");
    scan("%d", &CCommand, &ph1, &ph2);
    printf("\n");
    // Proses
    if (IsIdxEff(*gl,ph2)) {
        if ((ph2<=6)||(isInQueue(gq,gl->TI[ph2]))) {
            printf("Game gagal dihapus.\n");
        } else {
            DeleteAt(gl,ph2);
            printf("Game berhasil dihapus.\n");
        }
    } else {
        printf("Nomor game yang dimasukkan tidak valid.\n");
    }
    return;
}

void SAVE(TabWord gl, Word filename) {
    char a[351] = "../data/";
    int i,j;
    for (i=0;i<filename.Length;i++) {
        a[8+i] = filename.TabWord[i];
        a[9+i] = '\0';
    }
    char saveLine[51] = {0};
    FILE *saveFile = fopen(a,"w");
    fprintf(saveFile,"%d\n",gl.Neff);
    for (i=1;i<gl.Neff;i++) {
        for (j=0;j<gl.TI[i].Length;j++) {
            saveLine[j] = gl.TI[i].TabWord[j];
            saveLine[j+1] = 0;
        }
        fprintf(saveFile,"%s\n",saveLine);
    }
    fclose(saveFile);
    printf("Save file berhasil disimpan.\n");
    return;
}

void help() {
    printf("\n============================== LIST COMMAND YANG VALID ============================== \n\n");
    printf("1.  START \t\t: Membaca file konfigurasi sistem. \n");
    printf("2.  LOAD <filename>\t: Membaca file berisi list game yang dapat dimainkan dan histori.\n");
    printf("3.  SAVE <filename>\t: Menyimpan state game pada suatu file .txt.\n");
    printf("4.  CREATEGAME \t\t: Menambahkan game baru pada daftar game\n");
    printf("5.  LISTGAME \t\t: Menampilkan daftar game pada sistem\n");
    printf("6.  DELETEGAME \t\t: Menghapus sebuah game dari daftar game.\n");
    printf("\t\t\t  (*) Game yang dihapus hanya game yang dibuat pengguna secara custom.\n");
    printf("\t\t\t  (*) 5 game pertama pada file konfigurasi tidak dapat dihapus.\n");
    printf("\t\t\t  (*) Game yang di dalam queue game saat ini tidak dapat dihapus.\n");
    printf("7.  QUEUEGAME \t\t: Mendaftarkan permainan ke dalam list.\n");
    printf("8.  PLAYGAME \t\t: Memainkan game dengan urutan pertama di antrian.\n");
    printf("9.  SKIPGAME <n>\t: Melewatkan permainan sebanyak <n>.\n");
    printf("10. QUIT \t\t: Keluar dari program.\n");
    printf("11. HELP \t\t: Mengeluarkan list ini.\n");

}
