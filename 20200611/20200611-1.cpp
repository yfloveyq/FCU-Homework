#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("enter array size: ");
    int arrSize;
    scanf("%d", &arrSize);

    int *Ptr;
    Ptr = (int *) calloc(arrSize, sizeof(int));

    printf("enter number : \n");
    for (int i = 0; i < arrSize; ++i) {
        scanf("%d", Ptr + i);
    }

    for (int j = 0; j < arrSize; ++j) {
        printf("%d ", *(Ptr + j));
    }

    int n = arrSize / 2;

    Ptr = (int *) realloc(Ptr, n * sizeof(int));
    printf("\n");
    for (int k = 0; k < n; ++k) {
        printf("%d ", *(Ptr + k));
    }

    return 0;
}