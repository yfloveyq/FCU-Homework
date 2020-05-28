#include <iostream>

#define compare(x, y) (x<y?x:y)

using namespace std;

int main() {

    float x, y;
    scanf("%f%f", &x, &y);

    printf("The small one is : %f", compare(x, y));


    return 0;
}