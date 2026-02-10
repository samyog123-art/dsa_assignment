#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void reversePrint(struct node *head) {
    if (head == NULL)
        return;
    reversePrint(head->next);
    printf("%d ", head->data);
}

int main() {
    struct node *head = NULL, *temp, *newNode;
    int n, i, val;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newNode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &val);
        newNode->data = val;
        newNode->next = NULL;

        if (head == NULL)
            head = newNode;
        else
            temp->next = newNode;

        temp = newNode;
    }

    printf("Reverse traversal: ");
    reversePrint(head);

    return 0;
}
