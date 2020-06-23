#include <stdio.h>
#include <string.h>
int main(){

    char *check[5] = {"action", "banana", "promotion", "art", "vacation"};

    for (int i = 0; i < 5; ++i) {
        if(strstr(check[i], "tion") != NULL){
            printf("%s\n", check[i]);
        }
    }

    return 0;
}
