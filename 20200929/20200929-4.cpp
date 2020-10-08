#include <stdio.h>

int main() {

    int MaxExponent1, MaxExponent2, Element1, Power1, Element2, Power2, Arr[1000] = {0};
    char stop1, stop2;

    scanf("%d", &MaxExponent1);
    while (1) {

        scanf("%d%c[^\n]", &Element1, &stop1);
        scanf("%d%c[^\n]", &Power1, &stop1);
        Arr[Power1] += Element1;
        if (stop1 == '#') {
            break;
        }
    }

    scanf("%d", &MaxExponent2);
    while (1) {

        scanf("%d%c[^\n]", &Element2, &stop2);
        scanf("%d%c[^\n]", &Power2, &stop2);
        Arr[Power2] += Element2;
        if (stop2 == '#') {
            break;
        }
    }

    for (int i = 100; i >= 0; --i) {
        if (Arr[i] != 0) {
            printf("%d*x^%d", Arr[i], i);
            if (i != 0) {
                printf(" + ");
            }
        }

    }
    return 0;
}