#include<stdio.h>

int main() {
    unsigned long long int level, num;

    scanf("%llu", &level);

    for (int i = 0; i < level + 1; i++) {
        num = 1;

        for (int j = 0; j <= i; j++) {
            printf("%llu", num);
            num = (num * (i - j) / (j + 1));
            if(i != j){
                printf(" ");
            }
        }
        printf("\n");

    }

    return 0;
}