#include <stdio.h>

void disbits(unsigned int value);

void reversebits(unsigned int value);

int main() {

    unsigned int x;
    scanf("%u", &x);

    disbits(x);
    reversebits(x);
    return 0;
}

void disbits(unsigned int value) {

    unsigned int c;

    unsigned int displaymark = 1 << 31;
    printf("%u = ", value);

    for (int c = 1; c < 33; ++c) {
        putchar(value & displaymark ? '1' : '0');
        value <<= 1;

        if (c % 4 == 0) {
            putchar(' ');
        }
    }
    printf("\n");
}

void reversebits(unsigned int value) {
    int i = 0;
    unsigned int c;
    char a[32] = {0};
    unsigned int displaymark = 1 << 31;
    printf("%u = ", value);

    for (int c = 0; c < 32; ++c) {
        a[c] = (value & displaymark ? '1' : '0');
        value <<= 1;

    }

    while (a[i] != '\0') {
        i++;
    }
    for (int j = i - 1; j >= 0; --j) {
        if ((j+1) % 4 == 0) {
            putchar(' ');
        }
        printf("%c", a[j]);

    }


    printf("\n");
}