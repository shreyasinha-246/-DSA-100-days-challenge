#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // check min-heap property
    for (int i = 0; i <= (n - 2) / 2; i++) {
        if (2*i + 1 < n && arr[i] > arr[2*i + 1]) {
            printf("NO");
            return 0;
        }
        if (2*i + 2 < n && arr[i] > arr[2*i + 2]) {
            printf("NO");
            return 0;
        }
    }

    printf("YES");
    return 0;
}