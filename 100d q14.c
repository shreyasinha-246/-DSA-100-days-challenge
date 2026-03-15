#include <stdio.h>

int main() {
    int n;
    int a[50][50];
    int i, j, flag = 1;

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(i == j) {
                if(a[i][j] != 1) {
                    flag = 0;
                    break;
                }
            } else {
                if(a[i][j] != 0) {
                    flag = 0;
                    break;
                }
            }
        }
        if(flag == 0)
            break;
    }

    if(flag == 1)
        printf("Identity Matrix");
    else
        printf("Not an Identity Matrix");

    return 0;
}