//Count Nodes in Linked List

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    int n, x;
    struct Node *head = NULL, *temp = NULL, *newnode = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);

        newnode = (struct Node *)malloc(sizeof(struct Node));
        newnode->data = x;
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    int count = 0;
    temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    printf("%d", count);

    return 0;
}
