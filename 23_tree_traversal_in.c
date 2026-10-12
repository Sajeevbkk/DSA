#include <stdio.h>
#include <stdlib.h>

struct binarytree {
    int data;
    struct binarytree *lchild;
    struct binarytree *rchild;
};

typedef struct binarytree node;

node* buildTree() {
    int x;
    printf("Enter value (-1 for no node): ");
    scanf("%d", &x);

    if (x == -1) {
        return NULL;
    }

    node *p = (node*)malloc(sizeof(node));
    p->data = x;

    printf("Enter left child of %d:\n", x);
    p->lchild = buildTree();

    printf("Enter right child of %d:\n", x);
    p->rchild = buildTree();

    return p;
}

void inorder(node *root) {
    if (root != NULL) {
        printf("Going to left child of %d\n", root->data);
        inorder(root->lchild);

        printf("Visiting: %d\n", root->data);

        printf("Going to right child of %d\n", root->data);
        inorder(root->rchild);
    } else {
        printf("Hit NULL, going back\n");
    }
}

int main() {
    printf("Build the tree:\n");
    node *root = buildTree();

    printf("\nStarting Inorder Traversal:\n");
    inorder(root);

    return 0;
}