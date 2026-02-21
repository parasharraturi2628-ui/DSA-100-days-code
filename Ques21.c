//Create and Traverse Singly Linked List

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    int n;
    scanf("%d", &n);

    struct node *head = NULL, *tail = NULL;

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);

        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = x;
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
    }

    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
