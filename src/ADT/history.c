#include <stdio.h>
#include "stack.h"
#include "array.h"
#include "mesinkata.h"
#include "mesinkarakter.h"

//gcc -o coba history.c stack.c array.c mesinkata.c mesinkarakter.c
Word charpointertoWord(char *s)
{
    int i;
    Word w;
    for (i = 0; i < strlen(s); i++)
    {
        w.TabWord[i] = s[i];
    }
    w.Length = strlen(s);
    return w;
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

int main()
{
    TabWord games;
    games.Neff = 6;
    games.TI[0] = charpointertoWord("Game1");
    games.TI[1] = charpointertoWord("Game2");
    games.TI[2] = charpointertoWord("Game3");
    games.TI[3] = charpointertoWord("Game4");
    games.TI[4] = charpointertoWord("Game5");
    games.TI[5] = charpointertoWord("Game6");

    Stack game_history;
    CreateEmptyStack(&game_history);
    Push(&game_history, 4);
    Push(&game_history, 3);
    Push(&game_history, 1);

    int i;
    printf("Masukan i : ");
    scanf("%d", &i);
    HISTORY(games, &game_history, i);
    return 0;
}