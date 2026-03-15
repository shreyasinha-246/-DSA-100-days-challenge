#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    int n, i, x, k;
    struct node *head = NULL, *temp = NULL, *newnode, *last;

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &x);

        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = x;
        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
            temp = head;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    scanf("%d", &k);

    if(head == NULL || head->next == NULL) {
        temp = head;
    } else {
        last = head;
        int count = 1;

        while(last->next != NULL) {
            last = last->next;
            count++;
        }

        k = k % count;

        if(k != 0) {
            last->next = head;

            int steps = count - k;
            temp = head;

            for(i = 1; i < steps; i++)
                temp = temp->next;

            head = temp->next;
            temp->next = NULL;
        }
    }

    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}