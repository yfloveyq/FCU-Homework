#include <iostream>

using namespace std;

struct node {
    int data;               //create an integer to collect data
    struct node *next;      //create node to jump
};

node *NewNode(int num) {     //create new memory size for data
    struct node *t = new node;   //struct data is from the upper Function
    t->data = num;       //put num into int data from struct node
    t->next = NULL;      //define the next element is NULL
    return t;
};

node *merge(node *Ptr1, node *Ptr2) {    //merge nodes

    if (!Ptr1) {               //when a!=0,!a=0, when a=0, !a=1.
        return Ptr2;
    }
    if (!Ptr2) {
        return Ptr1;
    }

    if (Ptr1->data < Ptr2->data) {    //compare two elments in struct
        Ptr1->next = merge(Ptr1->next, Ptr2); // use merge to combine two nodes
        //Ptr->next is NULL
        return Ptr1;
    } else {
        Ptr2->next = merge(Ptr2->next, Ptr1);
        return Ptr2;
    }

}

void printnum(node *data) {     //print numbers

    while (data != NULL) {
        printf("%d ", data->data);      // data(struct name)->data(integer)
        data = data->next;
    }
}

int main() {

    node *head1 = NewNode(1);    // point head1 to function NewNode
    head1->next = NewNode(4);    // push pointer

    node *head2 = NewNode(3);    // point head2 to function NewNode
    head2->next = NewNode(7);    // push pointer

    node *mergenum = merge(head1, head2);    // give number

    printnum(mergenum);   //call Function

    return 0;
}