#include <stdio.h>

int main() {
    int n, i, j;
    int a[100];
    int count = 0, sum;

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for(i = 0; i < n; i++) {
        sum = 0;
        for(j = i; j < n; j++) {
            sum = sum + a[j];
            if(sum == 0) {
                count++;
            }
        }
    }

    printf("%d", count);

    return 0;
}