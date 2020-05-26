#include <iostream>
#include <queue>

using namespace std;

struct Data {
    int value;
    Data *leftchild;
    Data *rightchild;
};

void levelorder(Data *root);

Data *input(Data *root, int data);

int main() {

    Data *Ptr = NULL;
    int item[8] = {12, 15, 8, 6, 17, 19, 2, 4};

    for (int i = 0; i < 8; ++i) {
        Ptr = input(Ptr, item[i]);
    }

    levelorder(Ptr);

    return 0;
}

Data *input(Data *root, int data) {

    if (root == NULL) {
        root = new Data();      //new memory space
        root->value = data;     //insert the top of the binary tree
        root->rightchild = NULL;
        root->leftchild = NULL;
    } else if (data > root->value) {    //bigger number at the right
        root->rightchild = input(root->rightchild, data);
    } else {        //smaller at the left
        root->leftchild = input(root->leftchild, data);
    }

    return root;
}

void levelorder(Data *root) {
    if (root == NULL) {
        return ;
    }

    queue<Data *> line;     //queue with type<Data *>
    line.push(root);        //push Function

    while (!line.empty()) {
        Data *now = line.front();
        line.pop();         //pop Function
        printf("%d ", now->value);
        if (now->leftchild != NULL) {
            line.push(now->leftchild);
        }
        if (now->rightchild != NULL) {
            line.push(now->rightchild);
        }
    }
}