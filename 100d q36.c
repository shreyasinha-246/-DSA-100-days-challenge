#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int q[n];

    // Input elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &q[i]);
    }

    int front = 0, rear = n - 1;

    int m; // dequeue count
    scanf("%d", &m);

    // Dequeue m elements
    front = (front + m) % n;

    // Print circular queue
    int i = front;
    while (1) {
        printf("%d ", q[i]);
        if (i == rear) break;
        i = (i + 1) % n;
    }

    return 0;
}