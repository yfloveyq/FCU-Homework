#include <stdio.h>

struct node {
    char s1;
    struct node *next;
};
node *head = NULL;
void concatenate(node *Ptr1, node *Ptr2);

int main() {

    node *one = new node();
    node *two = new node();
    node *three = new node();
    node *four = new node();
    node *t;

    one->s1 = 'a';
    one->next = two;
    two->s1 = 'b';
    two->next = NULL;

    three->s1 = 'c';
    three->next = four;
    four->s1 = 'd';
    four->next = NULL;

    head = one;
    t = head;

    concatenate(two, three);

    while(t != NULL){
        printf("%c ", t->s1);
        t=t->next;
    }

    return 0;
}

void concatenate(node *Ptr1, node *Ptr2) {
    if(Ptr1->next==NULL){
        Ptr1->next=Ptr2;
    }else{
        concatenate(Ptr1->next, Ptr2);
    }
}