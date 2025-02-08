#include <stdlib.h>
#include <time.h>
#include "utils.h"

int random_int(int min, int max) {
    // Initialize random number generator only once (usually in main, but we do it here for simplicity)
    static int seeded = 0;
    if (!seeded) {
        srand(time(NULL));
        seeded = 1;
    }
    return min + rand() % (max - min + 1);
}