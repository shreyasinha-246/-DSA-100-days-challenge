#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

int prec(char c) {
    if(c == '+' || c == '-') return 1;
    if(c == '*' || c == '/') return 2;
    return 0;
}

int main() {
    char exp[100], ch;
    int i = 0;

    scanf("%s", exp);

    while(exp[i]) {
        ch = exp[i];

        if(isalnum(ch)) { // operand
            printf("%c", ch);
        }
        else { // operator
            while(top != -1 && prec(stack[top]) >= prec(ch)) {
                printf("%c", stack[top--]);
            }
            stack[++top] = ch;
        }
        i++;
    }

    // pop remaining
    while(top != -1) {
        printf("%c", stack[top--]);
    }

    return 0;
}