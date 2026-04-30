#include <stdio.h>

int heap[100], size = 0;

// swap
void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

// heapify up
void heapifyUp(int i) {
    while (i > 0 && heap[(i-1)/2] > heap[i]) {
        swap(&heap[(i-1)/2], &heap[i]);
        i = (i-1)/2;
    }
}

// heapify down
void heapifyDown(int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < size && heap[l] < heap[smallest])
        smallest = l;
    if (r < size && heap[r] < heap[smallest])
        smallest = r;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// insert
void insert(int x) {
    heap[size] = x;
    heapifyUp(size);
    size++;
}

// extract min
void extractMin() {
    if (size == 0) {
        printf("-1\n");
        return;
    }
    printf("%d\n", heap[0]);
    heap[0] = heap[size-1];
    size--;
    heapifyDown(0);
}

// peek
void peek() {
    if (size == 0) printf("-1\n");
    else printf("%d\n", heap[0]);
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        char op[20];
        scanf("%s", op);

        if (op[0] == 'i') {
            int x;
            scanf("%d", &x);
            insert(x);
        }
        else if (op[0] == 'e') {
            extractMin();
        }
        else if (op[0] == 'p') {
            peek();
        }
    }
    return 0;
}