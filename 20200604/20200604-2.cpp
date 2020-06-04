#include <cstdio>
#include <cstdlib>

int main(int argc, char *argv[]){

    printf("enter %d numbers in total", argc-1);

    int num = 1;
    int t;

    for (int i = 1; i < argc; ++i) {
        t = atoi(argv[i]);
        num = num * t;
    }

    printf("\nproduct : %d\n", num);

    return 0;
}
