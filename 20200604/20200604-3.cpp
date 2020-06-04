#include <stdio.h>

extern int random();

int compare(int, int);

int main() {
    int r;
    r = random();
    printf("The answer is : %d\n", r);
    printf("Please enter a number to guess : ");

    int n;

    scanf("%d", &n);
    int counter = 1;
    while (1) {
        if (compare(n, r) == 0) {
            printf("The number you insert is smaller than answer\nTry again(You have tried %d time)\n", counter);
        } else if (compare(n, r) == 1) {
            printf("The number you insert is bigger than answer\nTry again(You have tried %d time)\n", counter);
        } else {
            printf("your answer is correct(You have tried %d time)\n", counter);
            break;
        }
        scanf("%d", &n);
        counter++;
    }

    return 0;
}

int compare(int n, int r) {

    if (n < r) {
        return 0;
    } else if (n > r) {
        return 1;
    } else {
        return 2;
    }


}
