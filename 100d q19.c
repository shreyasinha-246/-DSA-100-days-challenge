#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j;
    int a[100];
    int x, y;
    int minSum = 1000000;

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            int sum = a[i] + a[j];

            if(abs(sum) < abs(minSum)) {
                minSum = sum;
                x = a[i];
                y = a[j];
            }
        }
    }

    printf("%d %d", x, y);

    return 0;
}