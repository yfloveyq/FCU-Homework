#include <stdio.h>
#include <math.h>
unsigned long long int sum = 0;
unsigned long long int chess(unsigned long long int num, unsigned long long int counter);

int main() {

    unsigned long long int num, counter = 0;
    scanf("%llu", &num);
    printf("%llu", chess(num, counter));

    return 0;
}

unsigned long long int chess(unsigned long long int num, unsigned long long int counter) {

    if(num == 0){
        return 0;
    }
    if(num >= pow(2, 63)){
        return 64;
    }

    sum += pow(2,counter);
    if(sum < num){
        return chess(num, counter+1);
    }else{
        return counter+1;
    }
}