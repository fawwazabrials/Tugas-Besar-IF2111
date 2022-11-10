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
   printf("Berikut adalah daftar game yang tersedia\n");
   DisplayArray(list);
}

void PLAYGAME(TabWord games, Queue *game_queue)
{   
    if (!isEmpty(*game_queue)) //kalo game_queue gk kosong
    {
        printf("Berikut adalah daftar Game-mu\n");

        DisplayQueue(*game_queue);
        ElTypeQueue gamename; //Tempat sampah pas dequeue
        if (GetElmtIdx(games, (*game_queue).buffer[(*game_queue).idxHead]) == 1)
        {
            printf("Loading RNG ...\n");
            run_rng();
        }

        else if (GetElmtIdx(games, (*game_queue).buffer[(*game_queue).idxHead]) == 2)
        {
            printf("Loading Diner Dash ...\n");
            dinerdash(); //ganti nama prosedur gamenya kalo dah jadi
        }

        else if (GetElmtIdx(games, (*game_queue).buffer[(*game_queue).idxHead]) == 3)
        {
            printf("Game DINOSAUR IN EARTH masih dalam maintenance, belum dapat dimainkan.\nSilakan pilih game lain.\n");
        }

        else if (GetElmtIdx(games, (*game_queue).buffer[(*game_queue).idxHead]) == 4)
        {
            printf("Game RISEWOMAN masih dalam maintenance, belum dapat dimainkan.\nSilakan pilih game lain.\n");
        }
        else if (GetElmtIdx(games, (*game_queue).buffer[(*game_queue).idxHead]) == 5)
        {
            printf("Game EIFFEL TOWER masih dalam maintenance, belum dapat dimainkan.\nSilakan pilih game lain.\n");
        }
        
        else if (GetElmtIdx(games, (*game_queue).buffer[(*game_queue).idxHead]) == 6)
        {
            printf("Loading 2048 ...\n");
            run_2048(); 
        }
        
        else
        {
            printf("Loading "); displayWord(HEAD((*game_queue))); printf(" ... \n");
            run_random();
        }

        dequeue(game_queue, &gamename);
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
    
        DisplayQueue(*game_queue);

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
    for (i=1;i<=gl.Neff;i++) {
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
void C_START (Word a,TabWord *T){
    int i,len;
    
    if (ValidateCommand(a, "START")) {
            STARTWORDFILE("config.txt");
            len = katatoint(currentWord);
            for (i=1; i<=len; i++) {
                ADV();
                ADVWORDFILE();
                SetEl(T, i, currentWord);
            }
    }
}

void LOAD (Word command2, TabWord *T)
{
    int i, len;
    STARTWORDFILE(WordToString(command2));
    len = katatoint(currentWord);
    for (i = 1; i <= len; i++)
        {
            ADV();
            ADVWORDFILE();
            SetEl(T, i, currentWord);
        }
}
