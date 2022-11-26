#include "towerofhanoi.h"
//gcc -o toh towerofhanoi.c ../ADT/stackofhanoi.c ../ADT/mesinkata.c ../ADT/mesinkarakter.c
// ./toh

boolean isNumber(Word W) 
{
    // KAMUS LOKAL
    int i;

    // ALGORITMA
    for (i = 0; i < W.Length; i++) {
        if (W.TabWord[i] < '0' || W.TabWord[i] > '9') return false;
    }
    return true;
}

float minmove(float n)
/*Menghasilkan langkah paling optimal berdasarkan n disk*/
{
    //n = jumlah disk
    return pow(2, n)-1;
}

void printblank(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" ");
    }
}

void printstars(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("*");
    }
}

void printtower(int n, Stack A, Stack B, Stack C)
{
    for (int i = 0; i < n; i++)
    {
        int value1 = A.T[n-i-1];
        int value2 = B.T[n-i-1];
        int value3 = C.T[n-i-1];
        if (value1 != 0)
        {
            printblank(n-value1);
            printstars(value1*2-1);
            printblank(n-value1);
        }
        else
        {
            printblank(n-value1-1);
            printf("|");
            if (n % 4 != 0) printblank(n-value1);
            else printblank(n-value1-1);
        }
        printf("\t");
        if (n % 4 == 0) printf("\t");
        if (value2 != 0)
        {
            printblank(n-value2+1);
            printstars(value2*2-1);
            printblank(n-value2);
        }
        else
        {
            printblank(n-value2);
            printf("|");
            printblank(n-value2);
        }
        printf("\t");
        if (value3 != 0)
        {
            printblank(n-value3+1);
            printstars(value3*2-1);
            printblank(n-value3);
        }
        else
        {
            printblank(n-value3);
            printf("|");
            printblank(n-value3);
        }
        printf("\n");
    }
    printblank(n-1);
    printf("A");
    printblank(n);
    printf("\t");
    printblank(n);
    printf("B");
    printblank(n);
    printf("\t");
    printblank(n);
    printf("C");
    printblank(n);
    printf("\n\n");
}

void towerofhanoi() //Bismillah Bisa :D halo aku gibran
{  
    //Membuat Stack Kosong (Isi semua elemen 0 dengan Top(*S) = n-1)
    Stack A, B, C, win; //tower A, B, C, dan win
    int score, temp1, temp2, value1, value2, value3;
    boolean valid = false;

    CreateEmptyS(&A);
    CreateEmptyS(&B);
    CreateEmptyS(&C);

    printf("-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-||WELCOME TO||-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-\n");
    printf(" ______   ___   __    __    ___  ____        ___   _____      __ __   ____  ____    ___  ____ \n");
    printf("|      | /   \\ |  |__|  |  /  _]|    \\      /   \\ |     |    |  |  | /    ||    \\  /   \\|    |\n");
    printf("|      ||     ||  |  |  | /  [_ |  D  )    |     ||   __|    |  |  ||  o  ||  _  ||     ||  | \n");
    printf("|_|  |_||  O  ||  |  |  ||    _]|    /     |  O  ||  |_      |  _  ||     ||  |  ||  O  ||  | \n");
    printf("  |  |  |     ||  `  '  ||   [_ |    \\     |     ||   _]     |  |  ||  _  ||  |  ||     ||  | \n");
    printf("  |  |  |     | \\      / |     ||  .  \\    |     ||  |       |  |  ||  |  ||  |  ||     ||  | \n");
    printf("  |__|   \\___/   \\_/\\_/  |_____||__|\\_|     \\___/ |__|       |__|__||__|__||__|__| \\___/|____|\n");
    printf("\n\n");
    printf("Selamat datang di permainan Tower of Hanoi!\n");
    //Menerima masukan jumlah disk
    int n;
    while (!valid)
    {
        printf("Masukan jumlah piringan : ");
        STARTWORD();
        printf("\n\n");
        if (!isNumber(currentWord))
        {
            printf("Masukan salah, silakan masukan kembali jumlah piringan.\n");
        }
        else
        {
            n = WordToInt(currentWord);
            ADVWORD();
            if (EndWord && n > 0) valid = true;
            else printf("Masukan salah, silakan masukan kembali jumlah piringan.\n");

        }
    }

    for(int i = n; i > 0; i--)
    {
        PushS(&A, i);
    }

    win = A; //Kondisi win ketika sama dengan kondisi awal tower A

    int countmoves = 0; //Penghitung jumlah langkah

    while (!isStackEqual(C, win))
    {
        printtower(n, A, B, C);
        printf("TIANG ASAL: ");
        STARTWORD();

        if (currentWord.TabWord[0] == 'A')
        {
            temp1 = 1;
        }
        else if (currentWord.TabWord[0] == 'B')
        {
            temp1 = 2;
        }
        else if (currentWord.TabWord[0] == 'C')
        {
            temp1 = 3;
        }
        ADVWORD();
        if (!EndWord) temp1 = 0;

        printf("TIANG TUJUAN: ");
        STARTWORD();
        printf("\n");
        if (currentWord.TabWord[0] == 'A')
        {
            temp2 = 1;
        }
        else if (currentWord.TabWord[0] == 'B')
        {
            temp2 = 2;
        }
        else if (currentWord.TabWord[0] == 'C')
        {
            temp2 = 3;
        }
        ADVWORD();
        if (!EndWord) temp2 = 0;

        value1 = getTop(A);
        value2 = getTop(B);
        value3 = getTop(C);
        if (temp1 == 1 && value1 != 0)
        {
            if (temp2 == 2)
            {
                if (value1 < value2 || value2 == 0)
                {
                    PopS(&A, &temp1);
                    PushS(&B, temp1);
                    countmoves++;
                }
                else
                {
                    printf("Tidak bisa dipindahkan.\n");
                }
                
            }
            else if (temp2 == 3)
            {
                if (value1 < value3 || value3 == 0)
                {
                    PopS(&A, &temp1);
                    PushS(&C, temp1);
                    countmoves++;
                }
                else
                {
                    printf("Tidak bisa dipindahkan.\n");
                }
            }
            else
            {
                printf("Masukan tidak valid\n");
            }
        }
        else if (temp1 == 2 && value2 != 0)
        {
            if (temp2 == 1){
                if (value2 < value1 || value1 == 0)
                {
                    PopS(&B, &temp1);
                    PushS(&A, temp1);
                    countmoves++;
                }
                else
                {
                    printf("Tidak bisa dipindahkan.\n");
                }
                
            }
            else if (temp2 == 3)
            {
                if (value2 < value3 || value3 == 0)
                {
                    PopS(&B, &temp1);
                    PushS(&C, temp1);
                    countmoves++;
                }
                else
                {
                    printf("Tidak bisa dipindahkan.\n");
                }
            }
            else
            {
                printf("Masukan tidak valid\n");
            }
        }
        else if (temp1 == 3 && value3 != 0)
        {
            if (temp2 == 1)
            {
                if (value3 < value1 || value1 == 0)
                {
                    PopS(&C, &temp1);
                    PushS(&A, temp1);
                    countmoves++;
                }
                else
                {
                    printf("Tidak bisa dipindahkan.\n");
                }
                
            }
            else if (temp2 == 2)
            {
                if (value3 < value2 || value2 == 0)
                {
                    PopS(&C, &temp1);
                    PushS(&B, temp1);
                    countmoves++;
                }
                else
                {
                    printf("Tidak bisa dipindahkan.\n");
                }
                
            }
            else
            {
                printf("Masukan tidak valid\n");
            }
        }
        else 
        {
            printf("Masukan tidak valid\n");
        }
    }
    printtower(n, A, B, C);
    score = ((minmove(n) / countmoves) * 10 * n/5); //Menghitung skor akhir
    printf("Selamat!!! Anda telah menyelesaikan tantangan Tower of Hanoi :D\n");
    printf("Skor Anda adalah : %d\n", score);
}

int main()
{
    towerofhanoi();
    return 0;
}