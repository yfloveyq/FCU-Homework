#include <stdio.h>
#include <stdlib.h>

struct data {
    int value;
    struct data *next;
};

void reverse(struct data **head) {

    struct data *pas = NULL;
    struct data *now = *head;
    struct data *next = NULL;

    while (now != NULL) {
        next = now->next;
        now->next = pas;
        pas = now;
        now = next;
    }
    *head = pas;
}

void push(struct data **head, char c) {
    struct data *newnum = (struct data *) malloc(sizeof(struct data));
    newnum->value = c;
    newnum->next = *head;
    *head = newnum;
}

void print(struct data *head) {

    struct data *t = head;
    while (t != NULL) {
        printf("%c ", t->value);
        t = t->next;
    }
}

int main() {

    struct data *head = NULL;

    push(&head, 'a');
    push(&head, 'q');
    push(&head, 'v');
    push(&head, 'e');

    print(head);
    reverse(&head);
    printf("\n");
    print(head);

}