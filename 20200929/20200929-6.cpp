#include <stdio.h>

int main() {

    char Arr[101][101] = {'\0', '\0'};
    int line, j = 0;

    scanf("%d", &line);

    for (int i = 0; i < line; ++i) {
        scanf(" %[^\n]", &Arr[i]);
    }

    int maxLength = 0;
    for (int i = 0; i < line; ++i) {
        while (1) {
            if (Arr[i][j] == '\0') {
                if (j > maxLength) {
                    maxLength = j;
                }
                j = 0;
                break;
            }
            j++;
        }
    }

    for (int i = 0; i < maxLength; ++i) {
        for (int k = line - 1; k >= 0; --k) {

            if (Arr[k][i] == '\0') {
                printf(" ");
            } else {
                printf("%c", Arr[k][i]);
            }
        }
        if (i != maxLength - 1) {
            printf("\n");
        }
    }

    return 0;
}