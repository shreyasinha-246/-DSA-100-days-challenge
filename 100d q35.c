#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int q[n];
    int front = 0, rear = -1;

    // Enqueue
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        q[++rear] = x;
    }

    // Display queue
    for (int i = front; i <= rear; i++) {
        printf("%d ", q[i]);
    }

    return 0;
}