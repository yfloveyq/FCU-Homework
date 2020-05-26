#include <cstdio>
#include <cstdlib>
#include <time.h>

// self-referential structure
struct treeNode {
    struct treeNode *leftPtr; // pointer to left subtree
    int data; // node value
    struct treeNode *rightPtr; // pointer to right subtree
};

typedef struct treeNode TreeNode; // synonym for struct treeNode
typedef TreeNode *TreeNodePtr; // synonym for TreeNode*

// prototypes
void insertNode(TreeNodePtr *treePtr, int value);

void inOrder(TreeNodePtr treePtr);

// function main begins program execution
int main(void) {
    TreeNodePtr rootPtr = NULL; // tree initially empty

    srand(time(NULL));
    puts("The numbers being placed in the tree are:");

    // insert random values between 0 and 14 in the tree

    int item[8] = {12, 15, 8, 6, 12, 19, 2, 4};
    for (int i = 0; i < 8; ++i) {
        insertNode(&rootPtr, item[i]);
        printf("%d ", item[i]);
    }


    // traverse the tree inOrder
    puts("\n\nThe inOrder traversal is:");
    inOrder(rootPtr);

}

// insert node into tree
void insertNode(TreeNodePtr *treePtr, int value) {
    // if tree is empty
    if (*treePtr == NULL) {
        *treePtr = (treeNode *) malloc(sizeof(TreeNode));

        // if memory was allocated, then assign data
        if (*treePtr != NULL) {
            (*treePtr)->data = value;
            (*treePtr)->leftPtr = NULL;
            (*treePtr)->rightPtr = NULL;
        } else {
            printf("%d not inserted. No memory available.\n", value);
        }
    } else { // tree is not empty
        // data to insert is less than data in current node
        if (value <= (*treePtr)->data) {
            insertNode(&((*treePtr)->leftPtr), value);
        }

            // data to insert is greater than data in current node
        else if (value > (*treePtr)->data) {
            insertNode(&((*treePtr)->rightPtr), value);
        } else { // duplicate data value ignored
            printf("%s", "dup");
        }
    }
}

// begin inorder traversal of tree
void inOrder(TreeNodePtr treePtr) {
    // if tree is not empty, then traverse
    if (treePtr != NULL) {
        inOrder(treePtr->leftPtr);
        printf("%3d", treePtr->data);
        inOrder(treePtr->rightPtr);
    }
}

