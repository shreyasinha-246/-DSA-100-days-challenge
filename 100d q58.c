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

// find index in inorder
int find(int in[], int start, int end, int val) {
    for (int i = start; i <= end; i++)
        if (in[i] == val) return i;
    return -1;
}

// build tree
struct Node* build(int pre[], int in[], int start, int end, int *pi) {
    if (start > end) return NULL;

    struct Node* root = newNode(pre[*pi]);
    (*pi)++;

    if (start == end) return root;

    int idx = find(in, start, end, root->data);

    root->left  = build(pre, in, start, idx - 1, pi);
    root->right = build(pre, in, idx + 1, end, pi);

    return root;
}

// postorder
void postorder(struct Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int n;
    scanf("%d", &n);

    int pre[n], in[n];
    for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);

    int pi = 0;
    struct Node* root = build(pre, in, 0, n - 1, &pi);

    postorder(root);
    return 0;
}