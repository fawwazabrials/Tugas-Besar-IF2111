#include "../../src/functions.h"
#include "../../src/games/RNG.h"
#include "../../src/games/dinerdash.h"
#include "../../src/games/2048.h"

int main() {
    Word c1, c2; int c3=-9999;

    while (c3 != 0) {
        printf("Masukan kode game yang ingin di-test :\n0. Quit\n1. RNG\n2. Diner Dash\n3. 2048\n");
        scan("%d", &c1, &c2, &c3);

        if (c3 == 1) {
            run_rng(); c3=0;
        } else if (c3 == 2) {
            dinerdash(); c3=0;
        } else if (c3 == 3) {
            run_2048(); c3=0;
        }
    }
    return 0;
}