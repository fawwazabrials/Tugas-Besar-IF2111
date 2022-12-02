#include "../../src/ADT/set.c"
#include "../../src/ADT/mesinkata.c"
#include "../../src/ADT/mesinkarakter.c"
#include <stdio.h>

int main()
{
    printf("====================== DRIVER SET ======================\n");
    Set S;
    Word A, B;
    CreateEmptySet(&S);
    A.TabWord[0] = 'A';
    A.Length = 1;
    B.TabWord[0] = 'B';
    B.Length = 1;

    if (IsEmptySet(S))
    {
        printf("Set Kosong, CreateEmptySet dan IsEmptySet Berhasil\n");
    }

    printf("Proses insert element ke set\n ");
    printf("enqeue WORD A\n");
    InsertSetElmt(&S, A);
    if (!IsEmptySet(S))
    {
        printf("insert element berhasil\n");
    }
    else
    {
        printf("insert element gagal\n");
    }

    printf("Menguji isfullset output diharapkan false\n ");
    if (IsFullSet(S))
    {
        printf("Isfullset gagal\n");
    }
    else
    {
        printf("Isfullset berhasil\n");
    }

    printf("Mengecek fungsi IsMememberset dengan WORD B diharapkan hasil false\n");
    if (!IsMemberSet(S, B))
    {
        printf("Ismemberset berhasil Word B bukan member dari set\n");
    }
    else
    {
        printf("Ismemberset gagal\n");
    }
    printf("Mengecek fungsi IsMememberset dengan WORD A diharapkan hasil TRUE\n");
    if (IsMemberSet(S, A))
    {
        printf("Ismemberset berhasil Word A merupakan member dari set\n");
    }
    else
    {
        printf("Ismemberset gagal\n");
    }

    printf("Mengetes fungsi delete element set\n");
    printf("Delete element Word B dari set dan word B tidak pernah di insert\n");
    DeleteSetElmt(&S, B);
    if (!IsEmptySet(S))
    {
        printf("Delete elemen berhasil\n");
    }
    else
    {
        printf("Dekete element gagal\n");
    }

    printf("Delete element Word A dari set maka Set akan menjadi empty set\n");
    DeleteSetElmt(&S, A);
    if (IsEmptySet(S))
    {
        printf("Delete elemen berhasil\n");
    }
    else
    {
        printf("Dekete element gagal\n");
    }
}