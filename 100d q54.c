#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int x) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x;
    n->left = n->right = NULL;
    return n;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    if (n == 0 || arr[0] == -1) return 0;

    // build tree
    struct Node* q[n];
    int front = 0, rear = 0;

    struct Node* root = newNode(arr[0]);
    q[rear++] = root;

    int i = 1;
    while (i < n) {
        struct Node* curr = q[front++];

        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            q[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            q[rear++] = curr->right;
        }
        i++;
    }

    // zigzag traversal
    front = 0; rear = 0;
    q[rear++] = root;

    int leftToRight = 1;

    while (front < rear) {
        int size = rear - front;
        int level[size];

        // collect level
        for (int i = 0; i < size; i++) {
            struct Node* curr = q[front++];
            level[i] = curr->data;

            if (curr->left)  q[rear++] = curr->left;
            if (curr->right) q[rear++] = curr->right;
        }

        // print level
        if (leftToRight) {
            for (int i = 0; i < size; i++)
                printf("%d ", level[i]);
        } else {
            for (int i = size - 1; i >= 0; i--)
                printf("%d ", level[i]);
        }

        leftToRight = !leftToRight;
    }

    return 0;
}