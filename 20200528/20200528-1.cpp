#include <iostream>

#define pi 3.14159

#define area(x) ((pi)*(x)*(x)*(x)*(4))/3

using namespace std;

int main(){

    float x;
    scanf("%f", &x);

    printf("The area is %f", area(x));

    return 0;
}