//Problem: For each element, count how many smaller elements appear on right side.Use merge sort technique or Fenwick Tree (BIT).

#include <stdio.h>

int arr[1000], temp[1000], count[1000];

void mergeSort(int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(left, mid);
    mergeSort(mid + 1, right);

    int i = left, j = mid + 1, k = left;
    int smaller = 0;

    while (i <= mid && j <= right) {
        if (arr[j] < arr[i]) {
            temp[k++] = arr[j++];
            smaller++;
        } else {
            count[i] += smaller;
            temp[k++] = arr[i++];
        }
    }

    while (i <= mid) {
        count[i] += smaller;
        temp[k++] = arr[i++];
    }

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];
}

int main() {
    int n, original[1000];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &original[i]);
        arr[i] = original[i];
        count[i] = 0;
    }

    mergeSort(0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", count[i]);

    return 0;
}

