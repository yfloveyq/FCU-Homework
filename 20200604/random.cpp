#include <stdlib.h>
#include <time.h>

int random() {
    int r;
    srand(time(NULL));
    r = rand();

    return r % 13 + 1;
}