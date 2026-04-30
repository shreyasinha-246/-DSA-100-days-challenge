#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int q[n], stack[n];
    int top = -1;

    // input queue
    for (int i = 0; i < n; i++) {
        scanf("%d", &q[i]);
        stack[++top] = q[i]; // push into stack
    }

    // pop from stack (reverse)
    while (top != -1) {
        printf("%d ", stack[top--]);
    }

    return 0;
}