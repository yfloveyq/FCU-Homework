#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random() {

    int randnum;
    randnum = rand();
    srand(randnum);
    return randnum;
}

int main() {

    FILE *oddPtr, *evenPtr;

    oddPtr = fopen("odd.txt", "w+");
    evenPtr = fopen("even.txt", "w+");

    if (oddPtr == NULL && evenPtr == NULL) {
        printf("File cannot be opened.");
    } else {
        for (int i = 0; i < 10000; i++) {
            int r = random();
            if (r % 2 == 1) {
                fprintf(oddPtr, "%d\n", r);
            } else {
                fprintf(evenPtr, "%d\n", r);
            }
        }
        fclose(oddPtr);
        fclose(evenPtr);
        return 0;
    }
}