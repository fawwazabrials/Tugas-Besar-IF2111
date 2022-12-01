#include "commands.h"

Word CCommand;
Word ph1;       // placeholder for 'scan' function
int ph2;        // placeholder for 'scan' function

void QUEUEGAME(TabWord games, Queue* game_queue) {
/* Memasukan game yang dipilih user ke dalam antrian game untuk dimainkan.
   I.S. : games dan game_queue terdefinisi 
   F.S. : Game yang dipilih oleh user akan masuk ke dalam game_queue*/
    // KAMUS LOKAL
    int game_idx;

    // ALGORITMA

    printf("Berikut adalah daftar antrian game-mu\n");
    DisplayQueue(*game_queue);
    printf("\n");
    printf("Berikut adalah daftar game yang tersedia\n");
    DisplayArray(games);
    printf("\n");

    printf("Nomor game yang mau ditambahkan ke antrian: ");
    STARTWORD();
    game_idx = katatoint(currentWord);
    // displayWord(currentWord);

    if (game_idx <= GetLastIdx(games) && game_idx >= GetFirstIdx(games)) {
        if (isFull(*game_queue)) printf("Daftar antrian game-mu sudah penuh! Silahkan skip game atau mainkan game terlebih dahulu.\n");
        else {
            // displayWord(GetElmt(games, game_idx));
            enqueue(game_queue, GetElmt(games, game_idx));
            printf("\nGame berhasil ditambahkan kedalam daftar antrian.\n");
        }
    } else {
        printf("\nNomor permainan tidak valid, silahkan masukkan nomor game pada list.\n");
    }
}

void list_game(TabWord list){
/* Proses  : Membaca listglobal yang berisi nama nama game
            yang terdapat pada file
   I.S     : listglobal yang sudah terdefenisi
   F.S     : Menambilkan isi dari list ke layar */
   // KAMUS LOKAL

   // ALGORITMA
   printf("Berikut adalah daftar game yang tersedia\n");
   DisplayArray(list);
}

void PLAYGAME(TabWord games, Queue *game_queue) {
/*I.S. : game_queue terdefinisi
  F.S. : game_queue terdequeue dan dijalankan
  Proses : mengeluarkan game dari queue dan menjalankannya */
    // KAMUS LOKAL

    // ALGORITMA 
    if (!isEmpty(*game_queue)) //kalo game_queue gk kosong
    {
        printf("Berikut adalah daftar Game-mu\n");
        DisplayQueue(*game_queue);
        printf("\n");

        ElTypeQueue gamename; //Tempat sampah pas dequeue
        if (GetElmtIdx(games, (*game_queue).buffer[(*game_queue).idxHead]) == 1)     // RNG
        {
            printf("Loading RNG ...\n\n");
            run_rng();
        }

        else if (GetElmtIdx(games, (*game_queue).buffer[(*game_queue).idxHead]) == 2) // Diner DASH
        {
            printf("Loading Diner Dash ...\n\n");
            dinerdash();
        }

        else if (GetElmtIdx(games, (*game_queue).buffer[(*game_queue).idxHead]) == 3) // HANGMAN
        {
            printf("Loading HANGMAN ...\n\n");
            // hangman();
        }

        else if (GetElmtIdx(games, (*game_queue).buffer[(*game_queue).idxHead]) == 4) // TOWER OF HANOI
        {
            printf("Loading TOWER OF HANOI ...\n\n");
            towerofhanoi();
        }
        else if (GetElmtIdx(games, (*game_queue).buffer[(*game_queue).idxHead]) == 5) // SNAKE ON METEOR
        {
            printf("Loading SNAKE ON METEOR ...\n\n");
            run_snake();
        }
        
        else if (GetElmtIdx(games, (*game_queue).buffer[(*game_queue).idxHead]) == 6) // 2048
        {
            printf("Loading 2048 ...\n\n");
            run_2048(); 
        }
        
        else // Game Random
        {
            printf("Loading "); displayWord(HEAD((*game_queue))); printf(" ... \n\n");
            run_random();
        }

        dequeue(game_queue, &gamename);
    }
    else
    {
        printf("Antrian game-mu kosong, silahkan tambah game terlebih dahulu.\n");
        QUEUEGAME(games, game_queue); //panggil prosedur QUEUEGAME jika game_queue kosong
    }
}

void SKIPGAME(TabWord games, Queue *game_queue, int n) {
/*I.S. : game_queue terdefinisi
F.S. : mengskip n buah game sesuai langkah yang diinginkan dari queue dan menjalankan game jika ada di game_queue
Proses :game_queue terdequeue sesuai berapa langkah skip yang diinginkan dan menjalankan game selanjutnya jika masih ada game di game_queue*/
    // KAMUS LOKAL

    // ALGORITMA
    if (!isEmpty(*game_queue))
    {
        printf("Berikut adalah daftar Game-mu\n");
        DisplayQueue(*game_queue);
        printf("\n");

        ADVWORD();
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
        printf("Antrian game-mu kosong, silakan tambah game terlebih dahulu.\n");
    }
}

void CREATEGAME(TabWord *T) {
/* Menciptakan game baru yang bila dimainkan langsung menunjukan skor 
   I.S. : Sembarang 
   F.S. : Game tercipta dan masuk ke array game, nama game yang masuk sesuai dari input user */
    // KAMUS LOKAL
    int i;
    boolean found;
    // ALGORITMA
    if (IsFull(*T)) printf("List game-mu penuh! Silahkan DELETE GAME terlebih dahulu.\n");
    else {
        printf("Masukkan nama game yang akan ditambahkan: ");
        scan("%s", &CCommand, &ph1, &ph2);
        i = GetFirstIdx(*T);
        found = false;
        while (i <= GetLastIdx(*T) && ! found) {
            if (isKataEqual(T->TI[i], CCommand)) {
                found = true;
            }
            i++;
        }
        if (found) {
            printf("Game telah ada di list.\n");
        } else {
            InsertLast(T, CCommand);
        }
        printf("Game berhasil ditambahkan\n");
    }
}

void DELETEGAME (TabWord *gl, Queue gq) {
/* Menghapus game yang ingin dihapus oleh user dengan syarat game harus hasil dari CREATE GAME
   I.S. : Sembarang 
   F.S. : Jika game merupakan hasil buatan user dari CREATE GAME, game berhasil dihapuskan 
          Jika game merupakan game bawaan dari file konfigurasi, game gagal dihapus */
    // KAMUS LOKAL

    // ALGORITMA
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

void SAVE(TabWord gl, Word filename, Stack history, Map scoreboard[]) {
/* Menyimpan isi dari Array game ke sebuah file '.txt' dengan nama file berupa input dari user
   I.S. : Sembarang 
   F.S. : File filename.txt berhasil tercipta di folder data dengan isinya adalah isi dari array game */
    // KAMUS LOKAL
    char a[351] = "../data/";
    int i,j,k;
    Word w;

    // ALGORITMA
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
    if (history.TOP < 1) {
        fprintf(saveFile,"0\n");
    } else {
        fprintf(saveFile,"%d\n",history.TOP);
        while (!(IsEmptyStack(history))) {
            Pop(&history,&i);
            for (j=0;j<gl.TI[i].Length;j++) {
                saveLine[j] = gl.TI[i].TabWord[j];
                saveLine[j+1] = 0;
            }
            fprintf(saveFile,"%s\n",saveLine);
        }
    }
    for (i=1;i<=gl.Neff;i++) {
        fprintf(saveFile,"%d\n",scoreboard[i].Count);
        for (j=1;j<=scoreboard[i].Count;j++) {
            for (k=0;k<scoreboard[i].Elements[j].Key.Length;k++) {
                saveLine[k] = scoreboard[i].Elements[j].Key.TabWord[k];
                saveLine[k+1] = 0;
            }
            fprintf(saveFile,"%s",saveLine);
            fprintf(saveFile," %d\n",scoreboard[i].Elements[j].Value);
        }
    }
    fclose(saveFile);
    printf("Save file berhasil disimpan.\n");
    return;
}

void help() {
/* Mencetak cara menuliskan command dan penjelasan dari command ke layar 
   I.S. : Sembarang 
   F.S. : Penjelasan seluruh command tercetak pada layar */
    // KAMUS LOKAL

    // ALGORITMA
    printf("\n================================ LIST COMMAND YANG VALID ================================ \n");
    printf("1.  START \t\t  : Membaca file konfigurasi sistem. \n");
    printf("2.  LOAD <filename>\t  : Membaca file berisi list game yang dapat dimainkan dan histori.\n");
    printf("3.  SAVE <filename>\t  : Menyimpan state game pada suatu file .txt.\n");
    printf("4.  CREATE GAME \t  : Menambahkan game baru pada daftar game\n");
    printf("5.  LIST GAME \t\t  : Menampilkan daftar game pada sistem\n");
    printf("6.  DELETE GAME \t  : Menghapus sebuah game dari daftar game.\n");
    printf("\t\t\t    *) Game yang dihapus hanya game yang dibuat pengguna secara custom.\n");
    printf("\t\t\t    *) 5 game pertama pada file konfigurasi tidak dapat dihapus.\n");
    printf("\t\t\t    *) Game yang di dalam queue game saat ini tidak dapat dihapus.\n");
    printf("7.  QUEUE GAME \t\t  : Mendaftarkan permainan ke dalam list.\n");
    printf("8.  PLAY GAME \t\t  : Memainkan game dengan urutan pertama di antrian.\n");
    printf("9.  SKIP GAME <n>\t  : Melewatkan permainan sebanyak <n>.\n");
    printf("10. SCOREBOARD \t\t  : Menampilkan scoreboard masing-masing game.\n");
    printf("11. RESET SCOREBOARD\t  : Melakukan reset pada scoreboard.\n");
    printf("12. HISTORY <n>\t\t  : Menampilkan history/riwayat permainan.\n");
    printf("13. RESET HISTORY\t  : Melakukan reset pada history.\n");
    printf("14. QUIT \t\t  : Keluar dari program.\n");
    printf("15. HELP \t\t  : Mengeluarkan list ini.\n");

}
void C_START (Word a,TabWord *T){
/* Membaca file config.txt pada folder data dan memasukan isinya ke Array games
   I.S. : Sembarang
   F.S. : Isi dari config.txt masuk ke Array game */
    // KAMUS LOKAL
    int i,len;

    // ALGORITMA
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

void LOAD (Word command2, TabWord *T) {
/* Membaca file dengan nama yang diinginkan user pada folder data dan memasukan isinya ke Array games
   I.S. : Sembarang
   F.S. : Jika file berhasil dibaca, isi dari Array game berisikan isi file.txt
          Jika file gagal dibaca, Array games tidak akan diisi dan memiliki Neff = 0 */
    // KAMUS LOKAL
    int i, len=0;

    // ALGORITMA
    STARTWORDFILE(WordToString(command2));
    len = katatoint(currentWord);
    for (i = 1; i <= len; i++)
        {
            ADV();
            ADVWORDFILE();
            SetEl(T, i, currentWord);
        }
}

void HISTORY(TabWord games, Stack *game_history, int n) //*game_history adalah stack yang berisi ID dari game yang sudah dimainkan
{
    if (!IsEmptyStack(*game_history))
    {
        if (n <= Top(*game_history)) // 5 <= 6, 6 <= 6
        {
            printf("Berikut adalah daftar Game yang telah dimainkan :\n");

            int trash;            // variabel untuk menyimpan ID game yang sudah dimainkan
            Stack temp;           // Stack sementara untuk menyimpan ID game yang sudah dimainkan
            temp = *game_history; // Mengisi stack sementara dengan stack game_history

            for (int i = 0; i < n; i++)
            {
                printf("%d. ", i + 1);
                displayWord(games.TI[InfoTop(temp)]); // Mencetak nama game yang sudah dimainkan
                printf("\n");
                Pop(&temp, &trash);
            }
        }
        else
        {
            printf("Berikut adalah daftar Game yang telah dimainkan :\n");

            int trash;            // variabel untuk menyimpan ID game yang sudah dimainkan
            Stack temp;           // Stack sementara untuk menyimpan ID game yang sudah dimainkan
            temp = *game_history; // Mengisi stack sementara dengan stack game_history

            for (int j = 0; j <= Top(*game_history); j++)
            {
                printf("%d. ", j + 1);
                displayWord(games.TI[InfoTop(temp)]); // Mencetak nama game yang sudah dimainkan
                printf("\n");
                Pop(&temp, &trash);
            }
        }
    }
    else
    {
        printf("Tidak ada permainan yang pernah dimainkan.\n");
    }
}

void SCOREBOARD (Map M[], TabWord gl) {
    for (int i = 1; i <= gl.Neff; i++) {
        printf("*** SCOREBOARD ");
        displayWord(gl.TI[i]);
        printf(" ***\n");
        if (M[i].Count == 0) {
            printf("--- Scoreboard kosong 😔 main yuk! ---\n");
        } else {
            for (int j=1; j<=M[i].Count; j++) {
                printf(" (%d) ",j);
                displayWord(M[i].Elements[j].Key);
                printf(" : %d\n",M[i].Elements[j].Value);
            }
        }
    }
    return;
}

void RESETSCOREBOARD(Map M[], TabWord gl){
/* Melakukan reset pada salah satu game atau semua game di scoreboard. */
/* I.S. Scoreboard terdefinisi */
/* F.S. Elemen-elemen pada salah satu atau semua scoreboard dihapus */
    // KAMUS LOKAL
    int scoreidx, i;
    // ALGORITMA
    printf("DAFTAR SCOREBOARD:\n");
    printf("0. ALL\n");
    DisplayArray(gl);

    printf("SCOREBOARD YANG INGIN DIHAPUS: ");
    STARTWORD();
    scoreidx = katatoint(currentWord);

    if (IsIdxEff(gl, scoreidx)) {
        if (scoreidx == 0) {
            printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD ALL (YA/TIDAK)?\n");
        } else {
            printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD ");
            displayWord(gl.TI[scoreidx]);
            printf(" (YA/TIDAK)?");
        }
        STARTWORD();
        if (ValidateCommand(currentWord, "YA")) {
            if (scoreidx == 0) {
                // Reset All
                MakeEmptyMapList(M, gl.Neff);
            } else {
                // Reset Salah Satu Game
                if (M[scoreidx].Count > 0) {
                    M[scoreidx].Count = NilMap;
                    printf("Scoreboard berhasil direset.\n");
                }              
            }
        } else if (ValidateCommand(currentWord, "TIDAK")) {
            printf("Scoreboard tidak jadi direset.\n");
        } else {
            printf("Command tidak valid. Scoreboard tidak jadi direset.\n");
        }
    } else {
        printf("Indeks tidak terdapat pada list game.\n");
    }

    return;
    
}

void RESETHISTORY(Stack *game_history) {
/* Melakukan reset pada stack history game yang pernah dimainkan
   I.S. : Sembarang, user sudah memilih YA
   F.S. : Stack game_history tidak memiliki elemen lagi */
    // KAMUS LOKAL

    // ALGORITMA
    CreateEmptyStack(game_history);
}