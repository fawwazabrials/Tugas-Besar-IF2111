#include "ADT/mesinkata.c"
#include "ADT/mesinkarakter.c"
#include "functions.c"
#include <stdio.h>
#include <string.h>

int main() {
    Word word;
    Word placeholder1;
    int placeholder2;

    scan("%s", &word, &placeholder1, &placeholder2);
    
    printf("Word: \n");
    displayWord(word);

    // char* string;
    // WordToString(word, string);
    char* string = WordToString(word);

    // for (int i = 0; i < strlen(string); i++) {
    //     printf("%d : %c\n", i, string[i]);
    // }

    printf("String : %s\n", string);

    char* str1 = (char*) malloc(NMax * sizeof(char)); 
    char* str2 = (char*) malloc(NMax * sizeof(char));
    separateSpace(string, str1, str2);
    printf("String 1 : %s\n", str1);
    printf("String 2 : %s\n", str2);

    return 0;
}

// void inputToCommand(Word inputCommand, char* command, char* commandID) {
//     /* Memisahkan input menjadi command dan commandID */
//     /* I.S. Word inputCommand terdefinisi */
//     /* F.S. inputCommand menjadi string dan terpisahkan menjadi command dan commandID */
//     int i = 0;
//     if (inputCommand.TabWord[i] == 'C') {
//         command = "COOK";
//         i = 6;
//         int j = 0;
//         while (i <= 7) {
//             commandID[j] = inputCommand.TabWord[i];
//             i++;
//             j++;
//         }
//     } else if (inputCommand.TabWord[i] == 'S') {
//         command = "SERVE";
//         i = 7;
//         int j = 0;
//         while (i <= 8) {
//             commandID[j] = inputCommand.TabWord[i];
//             i++;
//             j++;
//         }
//     }
// }