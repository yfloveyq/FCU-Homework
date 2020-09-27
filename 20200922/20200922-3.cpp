#include <stdio.h>

void binary(long long int dec);

int main() {

    long long int a;
    scanf("%lld", &a);
    binary(a);
    return 0;
}

void binary(long long int dec) {

    if (dec > 0) {
        binary(dec / 2);
        printf("%lld", dec % 2);
    }
}