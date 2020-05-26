#include <stdio.h>
#include <stdlib.h>

struct Data {
    int value;
    struct Data *next;
};

void reverse(struct Data **head) {

    struct Data *pas = NULL;
    struct Data *now = *head;
    struct Data *next = NULL;

    while (now != NULL) {
        next = now->next;
        now->next = pas;
        pas = now;
        now = next;
    }
    *head = pas;
}

void push(struct Data **head, char c) {
    struct Data *newnum = (struct Data *) malloc(sizeof(struct Data));
    newnum->value = c;
    newnum->next = *head;
    *head = newnum;
}

void print(struct Data *head) {

    struct Data *t = head;
    while (t != NULL) {
        printf("%c ", t->value);
        t = t->next;
    }
}

int main() {

    struct Data *head = NULL;

    push(&head, 'a');
    push(&head, 'q');
    push(&head, 'v');
    push(&head, 'e');

    print(head);
    reverse(&head);
    printf("\n");
    print(head);

}