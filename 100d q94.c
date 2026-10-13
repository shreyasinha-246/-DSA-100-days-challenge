//Problem: Sort array of non-negative integers using counting sort.Find max, build freq array, compute prefix sums, build output.

#include <stdio.h>

int main() {
    int n, arr[1000], output[1000];
    int count[10001] = {0};
    int i, max = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);

        if (arr[i] > max)
            max = arr[i];
    }

    for (i = 0; i < n; i++)
        count[arr[i]]++;

    for (i = 1; i <= max; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (i = 0; i < n; i++)
        printf("%d ", output[i]);

    return 0;
}



   
      

