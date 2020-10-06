#include <stdio.h>

int main() {

    int i=0,s=0;
    int Arr[100] = {0};
    int NewArr[100] = {0};

    while(scanf("%d", &Arr[i])){

        if(Arr[i] == '#') break;
        i++;
    }

    for(int k=0; k<i; k++){
        if(Arr[k] != 0){
            NewArr[s] = Arr[k];
            s++;
        }
    }

    for (int j = 0; j < i; ++j) {
        printf("%d ", NewArr[j]);
    }

    return 0;
}