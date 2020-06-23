#include <stdio.h>

int main(){

    FILE *bfPtr;

    if ((bfPtr = fopen("b.txt", "w")) == NULL)
        puts("file cannot be opened.");
    else{

        char a1;
        unsigned char a2;
        short int a3;
        unsigned short int a4;
        int a5;
        unsigned int a6;
        long int a7;
        unsigned long int a8;
        float a9;
        double a10;
        long double a11;

        fprintf(bfPtr,"char\t\t\t\t%d\nunsigned char\t\t\t%d\nshort int\t\t\t%d\nunsigned short int\t\t%d\nint\t\t\t\t%d\nunsigned int\t\t\t%d\nlong int\t\t\t%d\nunsigned long int\t\t%d\nfloat\t\t\t\t%d\ndouble\t\t\t\t%d\nlong double\t\t\t%d\n", sizeof(a1), sizeof(a2), sizeof(a3), sizeof(a4), sizeof(a5), sizeof(a6), sizeof(a7), sizeof(a8), sizeof(a9), sizeof(a10), sizeof(a11));
        fclose(bfPtr);
    }
}