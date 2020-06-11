#include <stdio.h>

int main() {
    int s = 0;
    int counter = 0;
    int starentercounter = 0;
    int counter1 = 0;

    start:

    if (counter > 4) {
        printf("\n");
        printf("%s", "*");
        goto starenter;
    }

    printf("%s", "*");
    ++counter;
    goto start;

    starenter:
    if(s == 9){
        printf("%s", "*");
        printf("\n");
        goto end;
    }

    if (starentercounter == 3) {
        printf("%s", "*");
        printf("%s", "\n");
        printf("%s", "*");
        starentercounter = 0;
        goto starenter;
    } else {
        printf("%s", " ");
        ++starentercounter;
        ++s;
        goto starenter;
    }

    end :
    if (counter1 > 4) {
        return 0;
    }

    printf("%s", "*");
    ++counter1;
    goto end;
}