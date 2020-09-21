#include <stdio.h>

void hanoi(int level, char p1, char p2, char p3);

int main() {

    int level;
    printf("Enter the level of the hanoi tower : ");
    scanf("%d", &level);
    printf("\n");
    hanoi(level, 'A', 'B', 'C');

    return 0;
}

void hanoi(int level, char p1, char p2, char p3) {

    if (level == 1) {
        printf("Plate %c go to Plate %c\n", p1, p3);
    } else {
        hanoi(level - 1, p1, p3, p2);
        hanoi(1, p1, p2, p3);
        hanoi(level - 1, p2, p1, p3);
    }
}