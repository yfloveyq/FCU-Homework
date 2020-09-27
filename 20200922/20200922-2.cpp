#include <cstdio>
#include <cmath>

int chess(unsigned long long int num, unsigned long long int counter);

int main() {

    unsigned long long int num;
    unsigned long long int counter = 0;

    scanf("%llu", &num);
    printf("%d", chess(num, counter));

    return 0;
}

int chess(unsigned long long num, unsigned long long int counter) {

    if(num == 0){
        return 0;
    }

    unsigned long long int sum = pow(2,(double )counter);

    if(num > sum){
        return chess(num-sum, counter+1);
    }else{
        return counter+1;
    }
}