#include <stdio.h>

int main() {

    int MaxExponent1, MaxExponent2, Element1, Element2, power1, power2, Arr1[2001] = {0},
            Arr2[2001] = {0}, Sum[10001] = {0};
    char stop1, stop2;

    scanf("%d", &MaxExponent1);

    while (1) {
        scanf("%d%c[^\n]", &Element1, &stop1);
        scanf("%d%c[^\n]", &power1, &stop1);
        Arr1[power1] += Element1;
        if (stop1 == '#') {
            break;
        }
    }

    scanf("%d", &MaxExponent2);

    while (1) {
        scanf("%d%c[^\n]", &Element2, &stop2);
        scanf("%d%c[^\n]", &power2, &stop2);
        Arr2[power2] += Element2;
        if (stop2 == '#') {
            break;
        }
    }

    for (int i = 0; i < MaxExponent1 + MaxExponent2; ++i) {
        for (int j = 0; j < MaxExponent1 + MaxExponent2; ++j) {
            if (Arr1[i] != 0 && Arr2[j] != 0) {
                Sum[i + j] += Arr1[i] * Arr2[j];
            }
        }
    }

    for (int i = MaxExponent1 + MaxExponent2; i >= 0; --i) {
        if (Sum[i] != 0) {
            printf("%d*x^%d", Sum[i], i);
            if (i != 0) {
                printf(" + ");
            }
        }
    }
    return 0;
}