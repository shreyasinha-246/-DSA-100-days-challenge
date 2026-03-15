#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* createList(int n) {
    struct node *head = NULL, *temp = NULL, *newnode;
    int x, i;

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

    return head;
}

int main() {
    int n, m;
    struct node *head1, *head2, *temp1, *temp2;

    scanf("%d", &n);
    head1 = createList(n);

    scanf("%d", &m);
    head2 = createList(m);

    temp1 = head1;
    temp2 = head2;

    while(temp1 != NULL && temp2 != NULL) {
        if(temp1->data < temp2->data) {
            printf("%d ", temp1->data);
            temp1 = temp1->next;
        } else {
            printf("%d ", temp2->data);
            temp2 = temp2->next;
        }
    }

    while(temp1 != NULL) {
        printf("%d ", temp1->data);
        temp1 = temp1->next;
    }

    while(temp2 != NULL) {
        printf("%d ", temp2->data);
        temp2 = temp2->next;
    }

    return 0;
}