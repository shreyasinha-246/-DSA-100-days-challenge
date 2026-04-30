#include <stdio.h>

int main() {
    int n, m, i;
    int stack[100], top = -1;

    scanf("%d", &n);

    // push all elements
    for(i = 0; i < n; i++) {
        scanf("%d", &stack[++top]);
    }

    scanf("%d", &m);

    // pop m elements
    for(i = 0; i < m; i++) {
        if(top != -1) top--;
    }

    // display from top to bottom
    for(i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}