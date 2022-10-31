#include <stdio.h>
#include "dinerdash.h"
#include "functions.c"

void dinerdash() {
    int saldo = 0;
    int rounds = 0;
    char* command;
    char id[2] = {'M'};
    QueueFood food;

    // Initializing Food
    for (int i = 0; i < 3; i++) {
        food.buffer[i].makanan[1] = i + '0';
        food.buffer[i].durasi = randint(1, 5); // randint yg bener nunggu fungsi dari fawwaz
        food.buffer[i].ketahanan = radint(1, 5);
        food.buffer[i].ketahanan = radint(10000, 50000);
    }

    printf(" _____  _                   _____            _        \n");  
    printf("|  __ \(_)                 |  __ \          | |       \n");
    printf("| |  | |_ _ __   ___ _ __  | |  | | __ _ ___| |__     \n");        
    printf("| |  | | | '_ \ / _ \ '__| | |  | |/ _` / __| '_ \    \n");
    printf("| |__| | | | | |  __/ |    | |__| | (_| \__ \ | | |   \n");
    printf("|_____/|_|_| |_|\___|_|    |_____/ \__,_|___/_| |_|   \n");                                     

    // Welcome Screen
    printf("Selamat Datang di Diner Dash!\n\n");
    printf("SALDO: %d\n\n", saldo);
    printf("Daftar Pesanan\n");
    printf("Makanan | Durasi memasak | Ketahanan | Harga\n");
    printf("--------------------------------------------\n");
    // LIST MAKANAN DI SINI
    printf("Daftar Makanan yang sedang dimasak\n");
    printf("Makanan | Sisa durasi memasak\n");
    printf("------------------------------\n");
    printf("        |                     \n\n");
    printf("Daftar Makanan yang dapat disajikan\n");
    printf("Makanan | Sisa ketahanan makanan\n");
    printf("------------------------------\n");
    printf("        |                      \n\n");

    printf("MASUKKAN COMMAND: ");
    scanf("%s", command);

    while (! IsFull(food) && rounds <= 15) {
        if (command == "COOK") {
            printf("Cook");
        } else if (command == "SERVE") {
            printf("Serve");
        }
        rounds++;
    }

}

int main(){
    dinerdash();
    return 0;
}
