//Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void zigzagTraversal(struct node* root) {
    if (root == NULL)
        return;

    struct node* stack1[100];
    struct node* stack2[100];
    int top1 = -1, top2 = -1;

    stack1[++top1] = root;

    while (top1 != -1 || top2 != -1) {
        while (top1 != -1) {
            struct node* temp = stack1[top1--];
            printf("%d ", temp->data);

            if (temp->left)
                stack2[++top2] = temp->left;
            if (temp->right)
                stack2[++top2] = temp->right;
        }

        while (top2 != -1) {
            struct node* temp = stack2[top2--];
            printf("%d ", temp->data);

            if (temp->right)
                stack1[++top1] = temp->right;
            if (temp->left)
                stack1[++top1] = temp->left;
        }
    }
}

int main() {
    struct node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    zigzagTraversal(root);

    return 0;
}
