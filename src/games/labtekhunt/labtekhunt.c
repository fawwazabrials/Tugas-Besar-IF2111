/* LABTEK HUNT */
#include "labtekhunt.h"

void bomb(int *skor, int *health) {
    /* I.S. Pemain bertemu bomb. Skor dan health terdefinisi */
    /* F.S. Skor dan health berkurang. */
    /* Muncul teks saat pemain bertemu bomb. */
    printf("Sekeliling pandangan Anda menjadi gelap. Sayup-sayup terdengar suara berupa bisikan lirih...\n");
    printf("'Mengapa saya masuk STI?'\n");
    printf("Anda pun tidak sadar bahwa suara itu muncul dari Anda sendiri...\n");
    printf("             . . .                  \n");  
    printf("               \\|/                  \n");           
    printf("             `--+--'                \n");          
    printf("               /|\\                  \n");          
    printf("              ' | '                 \n");          
    printf("                |                    \n");         
    printf("                |                    \n");         
    printf("            ,--'#`--.                \n");         
    printf("            |#######|                 \n");        
    printf("         _.-'#######`-._              \n");        
    printf("      ,-'###############`-.           \n");        
    printf("    ,'#####################`,          \n");       
    printf("   /#########################\\         \n");       
    printf("  |###########################|        \n");       
    printf(" |#############################|       \n");       
    printf(" |#############################|       \n");       
    printf(" |#############################|       \n");       
    printf(" |#############################|       \n");       
    printf("  |###########################|         \n");      
    printf("   \\#########################/        \n");        
    printf("    `.#####################,'          \n");       
    printf("      `._###############_,'            \n");       
    printf("         `--..#####..--'                \n");

    *skor = *skor - 50;
    *health = *health - 50;
    printf("Health anda sekarang adalah %d.\n", *health);
}

void treasure(int *skor) {
    /* I.S. Pemain bertemu treasure. Skor terdefinisi */
    /* F.S. Skor bertambah. */
    /* Muncul teks saat pemain bertemu treasure. */
    printf("Wow. Wow.. WOWWWWWWW!\n");
    printf("Anda menemukan TREASURE!!!!!\n");
    printf("Anda pun mengambil treasure tersebut dan memasukkannya dengan bahagia ke dalam tas.\n");
    *skor = *skor + 100;
    printf("Skor Anda bertambah menjadi %d.\n", *skor);
    printf("Anda keluar dari ruangan.\n");
}

boolean endLabtekHunt(int health, Tree P) {
    /* Game berakhir saat di akhir Tree atau health kurang dari 0. */
    return (health <= 0 ||  isTreeEmpty(P));
}

int run_labtekhunt() {
    /* GAME LABTEK HUNT */

    // KAMUS LOKAL
    Tree p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13;
    Tree loc, parent;
    p0 = newTreeNode(0);
    p1 = newTreeNode(1);
    p2 = newTreeNode(2);
    p3 = newTreeNode(3);
    p4 = newTreeNode(4);
    p5 = newTreeNode(5);
    p6 = newTreeNode(6);        // BOMB
    p7 = newTreeNode(7);
    p8 = newTreeNode(8);
    p9 = newTreeNode(9);        // BOMB
    p10 = newTreeNode(10);
    p11 = newTreeNode(11);
    p12 = newTreeNode(12);      // BOMB
    p13 = newTreeNode(13);
    int health = 100;
    int skor = 0;
    int hoki = 0;
    int round = 1;
    int nextStep;
    CreateTree(4, p11, p12, p13, &p4);
    CreateTree(3, p4, p9, p10, &p3);
    CreateTree(2, p3, p7, p8, &p2);
    CreateTree(1, p2, p5, p6, &p1);
    CreateTree(0, p1, NULL, NULL, &p0);

    // ALGORITMA
    printf("Welcome to Labtek Hunt!\n");
    printf("Dapatkah Anda menemukan semua harta karun di Labtek V atau apakah Anda akan bertemu dengan bomb?\n");
    printf("Ketik START untuk memulai game, HELP untuk melihat instruksi, atau EXIT.\n");
    printf("=== Masukkan command: ");
    STARTWORD();
    while (! ValidateCommand(currentWord, "START") && ! ValidateCommand(currentWord, "HELP") && ! ValidateCommand(currentWord, "EXIT")) {
        printf("INPUT SALAH! Ketik START untuk memulai game, HELP untuk melihat instruksi, atau EXIT.\n");
        printf("=== Masukkan command: ");
        STARTWORD();
    }

    if (ValidateCommand(currentWord, "HELP")) {
        printf("You've asked for help!\n");
        printf("\n====================================== HELP ======================================\n\n");
        printf("Objektif Anda adalah mencari semua harta karun dan menghindari bomb yang tersebar pada ruangan-ruangan.\n");
        printf("Ada 4 treasure dan 2 bomb yang tersebar. \n Jika Anda terkena 1 bomb, health dan skor Anda berkurang. Jika Anda terkena 2 bomb, maka GAME OVER.\n");
        printf("Anda bisa NAIK ke lantai setelahnya atau masuk ke ruangan-ruangan lain.\n");
        printf("Sehabis naik ke lantai setelahnya, Anda tidak bisa kembali ke lantai sebelumnya.\n(Misal, Anda sudah di Lt. 2, maka tidak bisa ke Lt. 1.\n");
        printf("Semoga mengerti! Kalau tidak, ya nasib.\n");
        printf("Jangan sampai memasukkan angka selain yang ada, atau terima konsekuensinya!\n");
        printf("Sekarang, ketik START untuk memulai game, atau EXIT untuk keluar.\n\n");
        printf("=== Masukkan command: ");
        STARTWORD();
    }

    if (ValidateCommand(currentWord, "START")) {
        loc = p0;
        parent = loc;
        while (! endLabtekHunt(health, loc)) {
            printf("\n====================================== BABAK %d ======================================\n\n", round);
            printf("Anda berada di ");
            switch (InfoRoot(loc)) {
                case 0:
                    printf("depan Labtek V.\n");
                    printf("Tidak ada ruangan yang buka di sekitar Anda...\nApa yang mau Anda lakukan?\n");
                    printf("1. NAIK ke lantai 2\n");
                    break;
                case 1:
                    printf("Lantai 1.\n");
                    printf("Not bad, not bad.\n");
                    printf("Apa yang mau Anda lakukan?\n");
                    printf("1. NAIK ke lantai 2.\n");
                    printf("2. MASUK ke ruangan 9301.\n");
                    printf("3. MASUK ke ruangan 9302.\n");
                    break;
                case 2:
                    printf("Lantai 2.\n");
                    printf("Hmmm... rasanya seperti tidak ada apa-apa disini. Ada beberapa ruangan yang menarik, tetapi.\n");
                    printf("Apa yang mau Anda lakukan?\n");
                    printf("1. NAIK ke lantai 3\n");
                    printf("2. MASUK ke Laboratorium Basis Data.\n");
                    printf("3. MASUK ke ruangan 7611.\n");
                    break;
                case 3:
                    printf("Lantai 3.\n");
                    printf("Wow! Sudah sampai sini saja.\n Apa yang mau Anda lakukan?\n");
                    printf("1. NAIK ke lantai 4.\n");
                    printf("2. MASUK ke ruangan 7609\n.");
                    printf("3. MASUK ke perpustakaan.\n");
                    break;
                case 4:
                    printf("Lantai 4.\n");
                    printf("You're finally on top!\n");
                    printf("Apa yang mau Anda lakukan?\n");
                    printf("1. MASUK ke sekre.\n");
                    printf("2. MASUK ke laboratorium IRK.\n");
                    printf("3. MASUK ke ruangan multimedia.\n");
                    printf("999. SELESAI.\n");
                    break;
                case 5:
                    printf("Ruang 9301.\n");
                    break;
                case 6:
                    printf("Ruang 9302.\n");
                    break;
                case 7:
                    printf("Laboratorium Basis Data.\n");
                    break;
                case 8:
                    printf("Ruang 7611.\n");
                    break;
                case 9:
                    printf("Ruang 7609.\n");
                    break;
                case 10:
                    printf("Perpustakaan (tutup jam 3!).\n");
                    break;
                case 11:
                    printf("Sekre HMIF.\n");
                    break;
                case 12:
                    printf("Laboratorium IRK.\n");
                    break;
                case 13:
                    printf("Multimedia.\n");
                    break;
            }

            printf("\nMasukkan INPUT: ");
            STARTWORD();
            while (! isKataInt(currentWord)) {
                printf("Masukkan integer, bukan kata!\n");
                printf("\n---> Masukkan INPUT: ");
                STARTWORD();
            }

            nextStep = WordToInt(currentWord);
            if (nextStep == 1) {
                if ((FirstC(loc)) != NULL) {
                    if (Status(FirstC(loc)) != true) {
                        printf("Anda memilih opsi 1! Let's hope that was the right choice.\n");
                        loc = FirstC(loc);
                        Status(loc) = true;
                    } else {
                        printf("Anda memasuki ruangan, tapi Anda rasa...\n");
                        printf("Kok udah pernah ke sini ya...\n");
                        printf("Rasa bersalah mencekam Anda...\n");
                        bomb(&skor, &health);
                    }
                } else {
                    printf("Anda mencoba memasuki area terlarang?!!\n");
                    bomb(&skor, &health);
                }
            } else if (nextStep == 2) {
                if ((SecondC(loc)) != NULL) {
                    if (Status(SecondC(loc)) != true) {
                        printf("Anda memilih opsi 2! Let's hope that was the right choice.\n");
                        loc = SecondC(loc);
                        Status(loc) = true;
                    } else {
                        printf("Anda memasuki ruangan, tapi Anda rasa...\n");
                        printf("Kok udah pernah ke sini ya...\n");
                        printf("Rasa bersalah mencekam Anda...\n");
                        bomb(&skor, &health);
                    }
                } else {
                    printf("Anda mencoba memasuki area terlarang?!!\n");
                    bomb(&skor, &health);
                }
            } else if (nextStep == 3) {
                if ((ThirdC(loc)) != NULL) {
                    if (Status(ThirdC(loc)) != true) {
                        printf("Anda memilih opsi 3! Let's hope that was the right choice.\n");
                        loc = ThirdC(loc);
                        Status(loc) = true;
                    } else {
                        printf("Anda memasuki ruangan, tapi Anda rasa...\n");
                        printf("Kok udah pernah ke sini ya...\n");
                        printf("Rasa bersalah mencekam Anda...\n");
                        bomb(&skor, &health);
                    }
                } else {
                    printf("Anda mencoba memasuki area terlarang?!!\n");
                    bomb(&skor, &health);
                }
            } else if (nextStep == 999) {
                printf("Anda sudah merasa cukup dengan petualangan Anda.\n");
                printf("It was a fun adventure, traveller, but we must part our ways here...\n");
                printf("Shall we meet again?\n");
                break;
            } else {
                printf("Anda membuka pintu-pintu lain secara paksa, dan langsung melangkahkan kaki..\n");
                printf("Sayangnya, pintu-pintu tersebut tidak mengarah ke mana pun, dan Anda pun merasakan bumi\n");
                printf("tiba-tiba menghilang dari bawah kaki... dan Anda jatuh... jatuh... jatuh... dan...\n");
                break;
            }

            if (InfoRoot(loc) == 5 || InfoRoot(loc) == 8 || InfoRoot(loc) == 9 || InfoRoot(loc) == 11) {
                treasure(&skor);
                loc = GetParent(p0, InfoRoot(loc), NULL);
            } else if (InfoRoot(loc) == 10 || InfoRoot(loc) == 7) {
                bomb(&skor, &health);
                loc = GetParent(p0, InfoRoot(loc), NULL);
            } else if (InfoRoot(loc) != 1 && InfoRoot(loc) != 2 && InfoRoot(loc) != 3 && InfoRoot(loc) != 4) {
                printf("Anda masuk ke dalam ruangan, tetapi Anda tidak menemukan apa-apa.\n");
                printf("Anda pun keluar ruangan, sedikit dongkol karena telah wasting time.");
                loc = GetParent(p0, InfoRoot(loc), NULL);
            }
            round++;
        }

        printf("\nGAME OVER.\nSkor anda adalah %d.\n", skor);
        return skor;
    }

    if (ValidateCommand(currentWord, "EXIT")) {
        printf("Anda merasa sudah cukup.\n");
        printf("Bye bye...\n");
        return skor;
    }

}