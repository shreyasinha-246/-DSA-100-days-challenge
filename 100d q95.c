//Problem: Given n real numbers in [0,1), sort using bucket sort algorithm. Distribute into buckets, sort each, concatenate.

#include <stdio.h>

void bucketSort(float arr[], int n) {
    float bucket[100][100];
    int count[100] = {0};

    for (int i = 0; i < n; i++) {
        int index = arr[i] * n;
        bucket[index][count[index]++] = arr[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < count[i]; j++) {
            float key = bucket[i][j];
            int k = j - 1;

            while (k >= 0 && bucket[i][k] > key) {
                bucket[i][k + 1] = bucket[i][k];
                k--;
            }

            bucket[i][k + 1] = key;
        }
    }

    int index = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < count[i]; j++) {
            arr[index++] = bucket[i][j];
        }
    }
}

int main() {
    int n;
    float arr[100];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%f", &arr[i]);

    bucketSort(arr, n);

    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);

    return 0;
}

