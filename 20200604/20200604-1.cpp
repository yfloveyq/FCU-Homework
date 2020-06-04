#include <stdio.h>
#include <stdarg.h>

double product(int i, ...);

int main() {

    double w = 31.4;
    double x = 113.2;
    double y = 54.56;
    double z = 98.26;

    printf("w*x = %f\n", product(2, w, x));
    printf("w*x*y = %f\n", product(3, w, x, y));
    printf("w*x*y*z = %f\n", product(4, w, x, y, z));
}

double product(int i, ...){

    double total = 1;
    va_list ap;
    va_start(ap, i);

    for (int j = 0; j < i; ++j) {
        total *= va_arg(ap,double);
    }

    va_end(ap);

    return total;

}