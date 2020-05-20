#include <stdio.h>
#include <stdlib.h>

struct node {
    char data;
    node *next;
};

void print(node *head) {
    if (head == NULL) {
        printf("Error");
    } else {
        puts("The queue is : ");

        while (head != NULL){
            printf("%c", head->next->data);
            head = head->next;
        }
    }
}

void enqueue(node *head, node *tail, char item) {

    node *newPtr = (node *) malloc(sizeof(node));

    while (head->next != NULL){
        head = head->next;
    }

    newPtr->data = item;
    newPtr->next = NULL;
    head->next = newPtr;
}

int main() {

    node *head = (node *) malloc(sizeof(node));
    head->next = NULL;

    node *tail = (node *) malloc(sizeof(node));
    tail->next = NULL;

    enqueue(head, tail, 'H');
    enqueue(head, tail, 'e');
    enqueue(head, tail, 'l');
    enqueue(head, tail, 'l');
    enqueue(head, tail, 'o');
    enqueue(head, tail, 'W');
    enqueue(head, tail, 'o');
    enqueue(head, tail, 'r');
    enqueue(head, tail, 'l');
    enqueue(head, tail, 'd');

    print(head);

    return 0;
}