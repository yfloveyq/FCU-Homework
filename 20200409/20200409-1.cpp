#include <stdio.h>

void packchar(unsigned int value);
void packchar1(unsigned int value);
int main() {

    char a, b, c, d;

    scanf("%c%c%c%c", &a, &b, &c, &d);

    packchar(a);
    printf("\n");
    packchar(b);
    printf("\n");
    packchar(c);
    printf("\n");
    packchar(d);
    printf("\n");
    packchar1(a << 8 | b);
    printf("\n");
    packchar1(a << 24 | b << 16 | c << 8 | d);
    printf("\n");


    return 0;
}

void packchar(unsigned int value) {

    unsigned int i;

    unsigned int dismark = 1 << 31;
    printf("%c->", value);
    for (int i = 1; i < 33; ++i) {
        putchar(value & dismark ? '1' : '0');
        value <<= 1;

        if (i % 4 == 0) {
            putchar(' ');
        }
    }

}
void packchar1(unsigned int value) {

    unsigned int i;

    unsigned int dismark = 1 << 31;

    for (int i = 1; i < 33; ++i) {
        putchar(value & dismark ? '1' : '0');
        value <<= 1;

        if (i % 4 == 0) {
            putchar(' ');
        }
    }

}