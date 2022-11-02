#include <stdio.h>

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