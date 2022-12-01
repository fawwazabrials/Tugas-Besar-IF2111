#include "hangman.h"

int run_hangman(){
    //kamus lokal
    int life,idx,i,tertebak,score,command3;
    char* list_kata[10];
    Set input,passed,cek;
    boolean valididx,validanswer,continue_game ,continue_tebak_kata;
    char *kata, *temp, tebakan, string_idx;
    Word command1,command2;

    //Algoritma
    CreateEmpty(&passed);
    list_kata ={"Ayam","Babi","Alstrukdat","Arsikom","Cicak","botol","laptop","ikan","helm","router"};
    life =10;
    tertebak=0;
    score = 0;
    continue_game = true;

    while(life >0 && continue_game ){
        
        //Melakukkan random index
        valididx = false;
        while (!valididx){
            
            idx = randint(0, 5000) % 10;
            string_idx = '0'+ idx;
            if(!IsMemberSet(passed,(string_idx))){
                InsertSetElmt(&passed,string_idx);
                valididx = true;
            }
        }
        kata= list_kata[idx];
        CreateEmpty(&cek);
        i=0;
        while (kata[i] != '\0'){
            InsertSetElmt(&cek,kata[i]);
            i++;
        }
        CreateEmpty(&input);
        continue_tebak_kata = true;
        //looping tebak tebakanss
        while (life > 0 && continue_tebak_kata){
            
            hangman(life);
            printf("Kata tebakan : ");
            i=0;
            
            while (kata[i] != '\0'){
                
                if(IsMemberSet(input,kata[i])){
                    printf("%c",kata[i]);
                }
                else{
                    printf("_");
                }
                if(kata[i] == '\0'){
                    printf("\n");
                }
                i++;
            }
            
            printf("Masukkan Tebakan : ");
            scan("%c",&command1,&command2,&command3);
            temp = WordToString(command1);
            tebakan = temp[0] ;
            
            if(IsMemberSet(cek,tebakan)){
                InsertSetElmt(&input,tebakan);
            }
            else{
                life --;
            }
            i=0;
            continue_tebak_kata = false;
            while(kata[i] != '\0'){
                if(!IsMemberSet(input,kata[i])){
                    continue_tebak_kata = true;
                }
                i++;
            }
        }
        i=0;
        if(passed.Count == 10){
            continue_game = false;
        }
        if (!continue_tebak_kata){
            score ++;       
        }
    }
    if(score >2){
        score = (score * 100) - (10-life)*10;
    }
    else if (score > 1){
        score = (score * 100) - (10-life)*5;
    }
    else{
        score = (score * 100);
    }

    if(!continue_game){
        printf("Selamat anda telah menyelesaikan game hang_man\n");
    }
    else{
        printf("Coba lagi dilain kesempatan untuk menyelesaikan permainan ini\n");
    }
    printf("Score anda adalah %d\n",score);
    return score;
}

void hangman(int life){
    switch (life)
    {
    case 9:
    printf("   __________________________           \n");
    printf("   |    |___________________|           \n");
    printf("   |    |             ||                \n");
    printf("   |    |                               \n");
    printf("   |    |                               \n");
    printf("   |    |                               \n");
    printf("   |    |                               \n");
    printf("   |    |                               \n");
    printf("   |____|                               \n");
    printf("   //  \\\\                             \n");
    printf("  //    \\\\                            \n");
    printf(" //      \\\\                           \n");
    printf("//        \\\\                          \n");    
        break;
    case 8:
    printf("   __________________________           \n");
    printf("   |    |___________________|           \n");
    printf("   |    |          ___||___             \n");
    printf("   |    |                               \n");
    printf("   |    |                               \n");
    printf("   |    |                               \n");
    printf("   |    |                               \n");
    printf("   |    |                               \n");
    printf("   |____|                               \n");
    printf("   //  \\\\                             \n");
    printf("  //    \\\\                            \n");
    printf(" //      \\\\                           \n");
    printf("//        \\\\                          \n");
        break;
    case 7:
    printf("   __________________________           \n");
    printf("   |    |___________________|           \n");
    printf("   |    |          ___||___             \n");
    printf("   |    |          |                    \n");
    printf("   |    |          |                    \n");
    printf("   |    |                               \n");
    printf("   |    |                               \n");
    printf("   |    |                               \n");
    printf("   |____|                               \n");
    printf("   //  \\\\                             \n");
    printf("  //    \\\\                            \n");
    printf(" //      \\\\                           \n");
    printf("//        \\\\                          \n");
        break;
    case 6:
    printf("   __________________________           \n");
    printf("   |    |___________________|           \n");
    printf("   |    |          ___||___             \n");
    printf("   |    |          |      |             \n");
    printf("   |    |          |      |             \n");
    printf("   |    |                               \n");
    printf("   |    |                               \n");
    printf("   |    |                               \n");
    printf("   |____|                               \n");
    printf("   //  \\\\                             \n");
    printf("  //    \\\\                            \n");
    printf(" //      \\\\                           \n");
    printf("//        \\\\                          \n");
        break;
    case 5:
    printf("   __________________________           \n");
    printf("   |    |___________________|           \n");
    printf("   |    |          ___||___             \n");
    printf("   |    |          |      |             \n");
    printf("   |    |          |______|             \n");
    printf("   |    |                               \n");
    printf("   |    |                               \n");
    printf("   |    |                               \n");
    printf("   |____|                               \n");
    printf("   //  \\\\                             \n");
    printf("  //    \\\\                            \n");
    printf(" //      \\\\                           \n");
    printf("//        \\\\                          \n");
        break;
    case 4:
    printf("   __________________________           \n");
    printf("   |    |___________________|           \n");
    printf("   |    |          ___||___             \n");
    printf("   |    |          |      |             \n");
    printf("   |    |          |______|             \n");
    printf("   |    |             ||                \n");
    printf("   |    |             ||                \n");
    printf("   |    |             ||                \n");
    printf("   |____|             ||                \n");
    printf("   //  \\\\                             \n");
    printf("  //    \\\\                            \n");
    printf(" //      \\\\                           \n");
    printf("//        \\\\                          \n");
        break;
    case 3:
    printf("   __________________________           \n");
    printf("   |    |___________________|           \n");
    printf("   |    |          ___||___             \n");
    printf("   |    |          |      |             \n");
    printf("   |    |          |______|             \n");
    printf("   |    |             ||                \n");
    printf("   |    |           //||                \n");
    printf("   |    |          // ||                \n");
    printf("   |____|             ||                \n");
    printf("   //  \\\\                             \n");
    printf("  //    \\\\                            \n");
    printf(" //      \\\\                           \n");
    printf("//        \\\\                          \n");
        break;
    case 2:
    printf("   __________________________           \n");
    printf("   |    |___________________|           \n");
    printf("   |    |          ___||___             \n");
    printf("   |    |          |      |             \n");
    printf("   |    |          |______|             \n");
    printf("   |    |             ||                \n");
    printf("   |    |           //||\\\\            \n");
    printf("   |    |          // || \\\\           \n");
    printf("   |____|             ||                \n");
    printf("   //  \\\\                             \n");
    printf("  //    \\\\                            \n");
    printf(" //      \\\\                           \n");
    printf("//        \\\\                          \n");
        break;
    case 1:
    printf("   __________________________           \n");
    printf("   |    |___________________|           \n");
    printf("   |    |          ___||___             \n");
    printf("   |    |          |      |             \n");
    printf("   |    |          |______|             \n");
    printf("   |    |             ||                \n");
    printf("   |    |           //||\\\\            \n");
    printf("   |    |          // || \\\\           \n");
    printf("   |____|             ||                \n");
    printf("   //  \\\\           //                \n");
    printf("  //    \\\\         //                 \n");
    printf(" //      \\\\                           \n");
    printf("//        \\\\                          \n");
        break;
    case 0:
    printf("GAME OVER");
    printf("   __________________________           \n");
    printf("   |    |___________________|           \n");
    printf("   |    |          ___||___             \n");
    printf("   |    |          |      |             \n");
    printf("   |    |          |______|             \n");
    printf("   |    |             ||                \n");
    printf("   |    |           //||\\\\            \n");
    printf("   |    |          // || \\\\           \n");
    printf("   |____|             ||                \n");
    printf("   //  \\\\           //  \\\\          \n");
    printf("  //    \\\\         //     \\\\        \n");
    printf(" //      \\\\                           \n");
    printf("//        \\\\                          \n");
        break;
    default:
    printf("   __________________________           \n");
    printf("   |    |___________________|           \n");
    printf("   |    |                               \n");
    printf("   |    |                               \n");
    printf("   |    |                               \n");
    printf("   |    |                               \n");
    printf("   |    |                               \n");
    printf("   |    |                               \n");
    printf("   |____|                               \n");
    printf("   //  \\\\                             \n");
    printf("  //    \\\\                            \n");
    printf(" //      \\\\                           \n");
    printf("//        \\\\                          \n");
        break;
    }
}

