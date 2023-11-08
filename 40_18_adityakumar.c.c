#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool isPalindrome(int num) {
    int originalNum = num;
    
    // Push digits onto the stack
    while (num != 0) {
        int digit = num % 10;
        push(digit);
        num /= 10;
    }

    // Pop digits and compare with original number
    int reversedNum = 0;
    while (top >= 0) {
        int digit = pop();
        reversedNum = reversedNum * 10 + digit;
    }

    return originalNum == reversedNum;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (isPalindrome(num)) {
        printf("%d is a palindrome.\n", num);
    } else {
        printf("%d is not a palindrome.\n", num);
    }

    return 0;
}
