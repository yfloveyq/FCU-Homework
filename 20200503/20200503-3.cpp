#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void transfer();

int random() {

    int randnum;
    randnum = rand();
    srand(randnum);
    return randnum;
}

int main() {

    FILE *wfPtr;

    wfPtr = fopen("numbers.txt", "w");

    if (wfPtr == NULL) {
        printf("File cannot be opened.");
    } else {
        for (int i = 0; i < 10; ++i) {
            int r;
            r = random();
            fprintf(wfPtr, "%d\n", r);
        }
    }
    fclose(wfPtr);
    transfer();

    return 0;
}

void transfer(){

    int w[10], sum=0, max=0;

    FILE *wfPtr;
    wfPtr = fopen("numbers.txt", "r");

    for (int j = 0; j < 10; ++j) {
        fscanf(wfPtr, "%d", &w[j]);
    }

    fclose(wfPtr);

    for (int k = 0; k < 10; ++k) {
        printf("%d\n", w[k]);
    }

    for (int j = 0; j < 10; ++j) {
        sum += w[j];
    }
    printf("sum = %d\n", sum);

    for (int k = 0; k < 10; ++k) {
        if (w[k] > max) {
            max = w[k];
        }
    }
    printf("max is : %d\n", max);

    int min = w[0];
    for (int k = 0; k < 10; ++k) {
        if (w[k] < min) {
            min = w[k];
        }
    }
    printf("min is : %d\n", min);

}
