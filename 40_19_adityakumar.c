#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // isdigit and isalpha functions from ctype.h

// maximum size of the stack
#define MAX_STACK_SIZE 50

// Precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

int main() {
    char infix[50];
    char postfix[50];
    char stack[MAX_STACK_SIZE];
    int top = -1;
    int i, j;
    char token;

    printf("Enter an Infix Expression: ");
    fgets(infix, sizeof(infix), stdin);

    for (i = 0, j = 0; infix[i]; i++) {
        token = infix[i];

        if (token == ' ' || token == '\t' || token == '\n') {
            continue; // Skip whitespace and newline characters
        }

        if (isdigit(token) || isalpha(token)) {
            postfix[j++] = token;
        } else if (token == '+' || token == '-' || token == '*' || token == '/') {
            while (top >= 0 && stack[top] != '(' && precedence(stack[top]) >= precedence(token)) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = token;
        } else if (token == '(') {
            stack[++top] = token;
        } else if (token == ')') {
            while (top >= 0 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            if (top >= 0 && stack[top] == '(') {
                top--;
            }
        }
    }

    // Push all remaining elements from the stack into postfix
    while (top >= 0) {
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
