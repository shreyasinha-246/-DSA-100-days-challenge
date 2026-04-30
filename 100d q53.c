#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

struct Node {
    int data;
    struct Node *left, *right;
};

struct Pair {
    struct Node* node;
    int hd;
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
    struct Node* q1[n];
    int f = 0, r = 0;

    struct Node* root = newNode(arr[0]);
    q1[r++] = root;

    int i = 1;
    while (i < n) {
        struct Node* curr = q1[f++];

        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            q1[r++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            q1[r++] = curr->right;
        }
        i++;
    }

    // vertical order using array
    int map[MAX][MAX], count[MAX] = {0};
    int offset = MAX / 2;

    struct Pair q[MAX];
    int front = 0, rear = 0;

    q[rear++] = (struct Pair){root, 0};

    int min = 0, max = 0;

    while (front < rear) {
        struct Pair p = q[front++];
        int hd = p.hd + offset;

        map[hd][count[hd]++] = p.node->data;

        if (p.node->left)
            q[rear++] = (struct Pair){p.node->left, p.hd - 1};

        if (p.node->right)
            q[rear++] = (struct Pair){p.node->right, p.hd + 1};

        if (p.hd < min) min = p.hd;
        if (p.hd > max) max = p.hd;
    }

    // print result
    for (int i = min + offset; i <= max + offset; i++) {
        for (int j = 0; j < count[i]; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }

    return 0;
}