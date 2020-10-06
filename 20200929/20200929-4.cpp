#include <stdio.h>

int main() {

    int num1, num2, temp1, temp2, temp3, temp4, arr[1000] = {0};
    char stop1, stop2;

    scanf("%d", &num1);
    while (1) {

        scanf("%d%c[^\n]", &temp1, &stop1);
        scanf("%d%c[^\n]", &temp2, &stop1);
        arr[temp2] += temp1;
        if (stop1 == '#') {
            break;
        }
    }

    scanf("%d", &num2);
    while (1) {

        scanf("%d%c[^\n]", &temp3, &stop2);
        scanf("%d%c[^\n]", &temp4, &stop2);
        arr[temp4] += temp3;
        if (stop2 == '#') {
            break;
        }
    }

    for (int i = 100; i >= 0; --i) {
        if (arr[i] != 0) {
            printf("%d*x^%d", arr[i], i);
            if (i != 0) {
                printf(" + ");
            }
        }

    }
    return 0;
}