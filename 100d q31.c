#include <stdio.h>

int main() {
    int n, op, val;
    int stack[100], top = -1;

    scanf("%d", &n);

    while(n--) {
        scanf("%d", &op);

        if(op == 1) { // push
            scanf("%d", &val);
            stack[++top] = val;
        }
        else if(op == 2) { // pop
            if(top == -1) printf("Stack Underflow\n");
            else printf("%d\n", stack[top--]);
        }
        else if(op == 3) { // display
            if(top == -1) printf("\n");
            else {
                for(int i = top; i >= 0; i--)
                    printf("%d ", stack[i]);
                printf("\n");
            }
        }
    }

    return 0;
}