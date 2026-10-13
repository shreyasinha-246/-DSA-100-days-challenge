//Problem: Implement Merge Sort - Implement the algorithm.Input:- First line: integer n- Second line: n space-separated integers.Output:- Print the sorted array or search result.Example:Input:5,64 34 25 12 22.Output:12 22 25 34 64

#include <stdio.h>

int arr[1000], temp[1000];

void merge(int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;

    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= high)
        temp[k++] = arr[j++];

    for (i = low; i <= high; i++)
        arr[i] = temp[i];
}

void mergeSort(int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;

        mergeSort(low, mid);
        mergeSort(mid + 1, high);
        merge(low, mid, high);
    }
}

int main() {
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    mergeSort(0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1)
            printf(" ");
    }

    printf("\n");

    return 0;
}

