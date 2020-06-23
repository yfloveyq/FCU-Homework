#include <stdio.h>

int main() {

    FILE *cfPtr;

    if ((cfPtr = fopen("a.txt", "w")) == NULL)
        puts("file cannot be opened.");
    else {
        fprintf(cfPtr, "Main File:\n");
        fprintf(cfPtr, "Account number\t Name\t\tBalance\n");
        fprintf(cfPtr, "100\t\t Alan Jones\t348.17\n");
        fprintf(cfPtr, "300\t\t Mary Smith\t27.19\n");
        fprintf(cfPtr, "500\t\t Sam Sharp\t0.00\n");
        fprintf(cfPtr, "700\t\t Suzy Green\t-14.22\n");
        fprintf(cfPtr, "\n");
        fprintf(cfPtr, "Transaction File:\n");
        fprintf(cfPtr, "Account number\t amount\n");
        fprintf(cfPtr, "100\t\t 27.14\n");
        fprintf(cfPtr, "300\t\t 62.11\n");
        fprintf(cfPtr, "400\t\t 100.56\n");
        fprintf(cfPtr, "900\t\t 82.17\n");
    }
    fclose(cfPtr);
}

