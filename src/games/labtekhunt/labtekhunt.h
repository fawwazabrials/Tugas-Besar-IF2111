/* LABTEK HUNT */
#include <stdio.h>
#include <stdlib.h>
#include "../functions.h"
#include "../ADT/tree.h"
#include "../ADT/boolean.h"
#include "../ADT/mesinkarakter.h"
#include "../ADT/mesinkata.h"

void bomb(int *skor, int *health);
/* I.S. Pemain bertemu bomb. Skor dan health terdefinisi */
/* F.S. Skor dan health berkurang. */
/* Muncul teks saat pemain bertemu bomb. */

void treasure(int *skor);
/* I.S. Pemain bertemu treasure. Skor terdefinisi */
/* F.S. Skor bertambah. */
/* Muncul teks saat pemain bertemu treasure. */

boolean endLabtekHunt(int health, Tree P);
/* Game berakhir saat di akhir Tree atau health kurang dari 0. */

int run_labtekhunt();
/* GAME LABTEK HUNT */