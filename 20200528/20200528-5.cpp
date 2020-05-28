#include <iostream>

#define sumarray(integer, n)\
for(int i=0; i<n; i++)\
    sum += integer[i]


using namespace std;

int main() {
    int sum = 0;
    int integer[5] = {1, 2, 3, 4, 5};

    sumarray(integer, 5);

    printf("The sum is : %d",sum);

    return 0;
}