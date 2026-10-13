//Problem: Given meeting intervals, find minimum number of rooms required.Sort by start time and use min-heap on end times.

#include <stdio.h>
#include <stdlib.h>

struct Meeting {
    int start, end;
};

int compare(const void *a, const void *b) {
    struct Meeting *x = (struct Meeting *)a;
    struct Meeting *y = (struct Meeting *)b;
    return x->start - y->start;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int heap[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left] < heap[smallest])
        smallest = left;

    if (right < n && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, n, smallest);
    }
}

int minRooms(struct Meeting meetings[], int n) {
    if (n == 0)
        return 0;

    qsort(meetings, n, sizeof(struct Meeting), compare);

    int heap[n];
    int size = 0, maxRooms = 0;

    for (int i = 0; i < n; i++) {
        if (size > 0 && heap[0] <= meetings[i].start) {
            heap[0] = meetings[i].end;
            heapify(heap, size, 0);
        } else {
            heap[size] = meetings[i].end;
            size++;
            maxRooms++;
        }

        if (size > 0)
            heapify(heap, size, 0);
    }

    return maxRooms;
}

int main() {
    int n;
    scanf("%d", &n);

    struct Meeting meetings[n];

    for (int i = 0; i < n; i++)
        scanf("%d %d", &meetings[i].start, &meetings[i].end);

    printf("%d\n", minRooms(meetings, n));

    return 0;
}

