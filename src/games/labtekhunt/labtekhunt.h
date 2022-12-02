/* LABTEK HUNT */
#include <stdio.h>
#include <stdlib.h>
#include "../../functions.h"
#include "../../ADT/tree/tree.h"
#include "../../ADT/boolean/boolean.h"
#include "../../ADT/mesinkarakter/mesinkarakter.h"
#include "../../ADT/mesinkata/mesinkata.h"

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