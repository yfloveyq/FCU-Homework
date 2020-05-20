#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    Node *next;
};

void input(Node *top, int num) {    //using push method

    Node *newPtr = (Node *) malloc(sizeof(Node));
    newPtr->next = NULL;
    newPtr->data = num;
    newPtr->next = top->next;
    top->next = newPtr;
}

Node *search(Node *top, int num) {

    if (top == NULL) {
        return NULL;
    }
    if (top->data == num) {
        return top;
    }

    return search(top->next, num);
}

int main() {

    Node *topPtr = (Node *) malloc(sizeof(Node));
    topPtr->next = NULL;

    input(topPtr, 1);
    input(topPtr, 8);
    input(topPtr, 57);
    input(topPtr, 4);
    input(topPtr, 23);
    input(topPtr, 5);
    input(topPtr, 99);
    input(topPtr, 46);
    input(topPtr, 39);
    input(topPtr, 86);

    printf("Enter a number you want to search : ");
    int n = 0;
    scanf("%d", &n);

    Node *find = search(topPtr, n);

    if (find == NULL) {
        printf("Data not found");
    } else {
        printf("Data found : %d", find->data);
    }

    return 0;
}