#include <stdio.h>
#include<stdlib.h> 	// exit
#define MAX_SIZE 10 	// size of array 10

int stack[MAX_SIZE];
int top = -1;

void push(int value) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack is Overflow");
    } else {
        top++;
        stack[top] = value;
        printf("%d Pushed onto the stack.\n", value);
    }
}

void pop() {
    if (top < 0) {
        printf("Stack is Underflow\n");
    } else {
        printf("Popped element: %d\n", stack[top]);
        top--;
    }
}

void display() {
    if (top < 0) {
        printf("Stack is Undeflow\n");
    } else {
        printf("Stack elements:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int choice, value;

    while(1) {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                exit(1);
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }

    return 0;
}

