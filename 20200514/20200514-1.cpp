#include <stdio.h>
#include <stdlib.h>

struct Data {
    char data;
    Data *next;
};

void push(Data *top, char s) {  // char s, not char *s, because you only scan one character at one time

    Data *newPtr = (Data *) malloc(sizeof(Data)); //redefine the type
    newPtr->next = NULL;
    newPtr->data = s;   //give character s to newPtr->data
    newPtr->next = top->next; //(top->next) is same as *head
    top->next = newPtr;     //point to newPtr's top
}

char pop(Data *top) {

    if (top != NULL) {
        char value = top->next->data; //(top->next) is same as *head
        top->next = top->next->next;
        return value;
    } else {
        return '\0';
    }
}

void printlist(Data *top) {

    char c = pop(top);  //call Function, and point to top
    while (c != '\0') {
        printf("%c", c);
        c = pop(top);   //pop Function will point to next data when call
    }
}

int main() {

    Data *topPtr = (Data *) malloc(sizeof(Data));   //redefine the type
    topPtr->next = NULL;
    char s[100];
    printf("(Push)Enter a sentence : ");
    scanf("%s", s);
    for (int i = 0; s[i] != '\0'; ++i) {
        push(topPtr, s[i]);
    }
    printf("(Pop)Reverse sentence into: ");
    printlist(topPtr);

    return 0;
}