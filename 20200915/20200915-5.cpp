#include <stdio.h>

void hanoi(int level, char p1, char p2, char p3);
int move=1;
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
        printf("%d:1 %c %c \n", move, p1, p3);
        move++;
    } else {
        hanoi(level - 1, p1, p3, p2);
        printf("%d:%d %c %c \n", move, level, p1, p3);
        move++;
        hanoi(level - 1, p2, p1, p3);
    }
}