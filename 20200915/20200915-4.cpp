#include<stdio.h>
#include<string.h>

void per(char *c1, int n1, int n2);

void swap(char *c1, char *c2);

int main() {

    char s[] = "ABC";
    int length = strlen(s);
    per(s, 0, length-1);
    return 0;
}

void per(char *c1, int n1, int n2) {

    int i;
    if(n1 == n2){
        printf("%s\n", c1);
    }else{
        for (i = n1; i <= n2; ++i) {
            swap((c1+n1), (c1+i));
            per(c1, (n1+1), n2);
            swap((c1+n1), (c1+i));
        }
    }

}

void swap(char *c1, char *c2) {

    char t;
    t = *c1;
    *c1 = *c2;
    *c2 = t;
}
