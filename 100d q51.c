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

// insert in BST
struct Node* insert(struct Node* root, int x) {
    if (!root) return newNode(x);

    if (x < root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);

    return root;
}

// find LCA
struct Node* LCA(struct Node* root, int a, int b) {
    if (!root) return NULL;

    if (a < root->data && b < root->data)
        return LCA(root->left, a, b);

    if (a > root->data && b > root->data)
        return LCA(root->right, a, b);

    return root;
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* root = NULL;

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        root = insert(root, x);
    }

    int a, b;
    scanf("%d %d", &a, &b);

    struct Node* ans = LCA(root, a, b);

    if (ans)
        printf("%d", ans->data);

    return 0;
}