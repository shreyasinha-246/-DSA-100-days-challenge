#include <stdio.h>
#define MAX 100

int dq[MAX];
int front = -1, rear = -1;

// check empty
int isEmpty() {
    return (front == -1);
}

// push front
void push_front(int x) {
    if (front == -1) {
        front = rear = 0;
    } else if (front > 0) {
        front--;
    } else {
        printf("Overflow\n");
        return;
    }
    dq[front] = x;
}

// push back
void push_back(int x) {
    if (front == -1) {
        front = rear = 0;
    } else if (rear < MAX - 1) {
        rear++;
    } else {
        printf("Overflow\n");
        return;
    }
    dq[rear] = x;
}

// pop front
void pop_front() {
    if (isEmpty()) {
        printf("-1\n");
        return;
    }
    printf("%d\n", dq[front]);
    if (front == rear)
        front = rear = -1;
    else
        front++;
}

// pop back
void pop_back() {
    if (isEmpty()) {
        printf("-1\n");
        return;
    }
    printf("%d\n", dq[rear]);
    if (front == rear)
        front = rear = -1;
    else
        rear--;
}

// get front
void getFront() {
    if (isEmpty()) printf("-1\n");
    else printf("%d\n", dq[front]);
}

// get back
void getBack() {
    if (isEmpty()) printf("-1\n");
    else printf("%d\n", dq[rear]);
}

int main() {
    // demo usage (you can modify input as needed)
    push_back(10);
    push_back(20);
    push_front(5);

    getFront(); // 5
    getBack();  // 20

    pop_front(); // removes 5
    pop_back();  // removes 20

    return 0;
}