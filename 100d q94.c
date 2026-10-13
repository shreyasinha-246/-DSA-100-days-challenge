//Problem: Sort an array using insertion sort.Stable sort. Good for nearly sorted arrays.

#include <stdio.h>

int main() {
    int n, arr[1000], i, j, key;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }

    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}

