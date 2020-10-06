#include <stdio.h>

int main() {

    long long int num[100] = {0}, counter[1000] = {0};

    long long int i = 0, count = 0;


    while (scanf("%lld", &num[i])) {

        if (num[i] == '#') {
            break;
        }
        i++;
    }

    for (int j = 0; j < i; ++j) {
        count++;
        if (num[j] > num[j + 1]) {
            counter[j] = count;
            count = 0;
        }
    }

    for (int j = 0; j < i; ++j) {
        for (int k = 0; k < i; ++k) {
            if(counter[j] > counter[k]){
                int t;
                t = counter[j];
                counter[j] = counter[k];
                counter[k] = t;
            }
        }
    }

    printf("%lld", counter[0]);


    return 0;
}


