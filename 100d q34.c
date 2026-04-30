#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

// Push
void push(struct Node** top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

// Pop
int pop(struct Node** top) {
    if (*top == NULL) return 0;
    struct Node* temp = *top;
    int val = temp->data;
    *top = temp->next;
    free(temp);
    return val;
}

int evaluate(char* exp) {
    struct Node* stack = NULL;
    int i = 0;

    while (exp[i]) {
        // Skip spaces
        if (exp[i] == ' ') {
            i++;
            continue;
        }

        // If digit
        if (isdigit(exp[i])) {
            int num = 0;
            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            push(&stack, num);
        }
        else {
            int b = pop(&stack);
            int a = pop(&stack);

            switch (exp[i]) {
                case '+': push(&stack, a + b); break;
                case '-': push(&stack, a - b); break;
                case '*': push(&stack, a * b); break;
                case '/': push(&stack, a / b); break;
            }
            i++;
        }
    }
    return pop(&stack);
}

int main() {
    char exp[100];
    printf("Enter postfix expression: ");
    fgets(exp, sizeof(exp), stdin);

    printf("Result = %d\n", evaluate(exp));
    return 0;
}