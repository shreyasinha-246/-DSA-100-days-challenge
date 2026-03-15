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

int length(struct node *head) {
    int count = 0;
    while(head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

int main() {
    int n, m, d;
    struct node *head1, *head2, *t1, *t2;

    scanf("%d", &n);
    head1 = createList(n);

    scanf("%d", &m);
    head2 = createList(m);

    int len1 = length(head1);
    int len2 = length(head2);

    t1 = head1;
    t2 = head2;

    if(len1 > len2) {
        d = len1 - len2;
        while(d--) t1 = t1->next;
    } else {
        d = len2 - len1;
        while(d--) t2 = t2->next;
    }

    while(t1 != NULL && t2 != NULL) {
        if(t1->data == t2->data) {
            printf("%d", t1->data);
            return 0;
        }
        t1 = t1->next;
        t2 = t2->next;
    }

    printf("No Intersection");

    return 0;
}