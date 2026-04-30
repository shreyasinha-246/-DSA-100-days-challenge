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

// check mirror
int isMirror(struct Node* a, struct Node* b) {
    if (!a && !b) return 1;
    if (!a || !b) return 0;

    return (a->data == b->data) &&
           isMirror(a->left, b->right) &&
           isMirror(a->right, b->left);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    if (n == 0 || arr[0] == -1) {
        printf("YES");
        return 0;
    }

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

    if (isMirror(root->left, root->right))
        printf("YES");
    else
        printf("NO");

    return 0;
}