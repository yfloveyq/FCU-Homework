#include<stdio.h>

int calc(int n1, int n2, int sum);

int main() {

    int num1, num2, amount;
    scanf("%d", &amount);
    for (int i = 0; i < amount; ++i) {
        int sum = 1;
        scanf("%d%d", &num1, &num2);
        printf("%d\n", calc(num1, num2, sum));
    }

    return 0;
}

int calc(int n1, int n2, int sum) {

    if (n1 > 0 && n2 == 0) {
        return 1;
    }

    sum *= n1;
    n2--;

    if (n2 == 0) {
        return sum;
    } else {
        return calc(n1, n2, sum);
    }
}
