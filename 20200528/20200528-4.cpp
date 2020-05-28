#include <iostream>
#define Compare2(x,y) (x<y?x:y)
#define compare3(x,y,z) (Compare2(Compare2(x,y),z))

using namespace std;

int main(){

    float x,y,z;
    scanf("%f%f%f", &x,&y,&z);

    printf("The small one is : %f", compare3(x,y,z));

    return 0;
}
