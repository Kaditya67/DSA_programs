#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

int stack[MAX_SIZE];
int top = -1;

void push(int value) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        stack[top] = value;
    }
}

int pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        return -1; // or some error value
    } else {
        int value = stack[top];
        top--;
        return value;
    }
}

void display() {
    if (top < 0) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int count() {
    return top + 1;
}

void reverseString(char* str) {
    int length = strlen(str);

    // Push each character of the string onto the stack
    for (int i = 0; i < length; i++) {
        push(str[i]);
    }

    // Pop characters from the stack and overwrite the original string
    for (int i = 0; i < length; i++) {
        str[i] = pop();
    }
}

int main() {
    char str[MAX_SIZE];
    printf("Enter a string: ");
    scanf("%s", str);

    reverseString(str);
    printf("Reversed string: %s\n", str);

    return 0;
}
