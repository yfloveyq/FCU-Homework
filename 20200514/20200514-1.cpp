#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    Node *next;
};

void push(Node *top, char s) {  // char s, not char *s, because you only scan one character at one time

    Node *newPtr = (Node *) malloc(sizeof(Node)); //redefine the type
    newPtr->next = NULL;
    newPtr->data = s;   //give character s to newPtr->data
    newPtr->next = top->next; //(top->next) is same as *head
    top->next = newPtr;     //point to newPtr's top
}

char pop(Node *top) {

    if (top != NULL) {
        char value = top->next->data; //(top->next) is same as *head
        top->next = top->next->next;
        return value;
    } else {
        return '\0';
    }
}

void printlist(Node *top) {

    char c = pop(top);  //call Function, and point to top
    while (c != '\0') {
        printf("%c", c);
        c = pop(top);   //pop Function will point to next data when call
    }
}

int main() {

    Node *topPtr = (Node *) malloc(sizeof(Node));   //redefine the type
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