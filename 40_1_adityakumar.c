#include <stdio.h>

// Function to check if a number is part of the Fibonacci series
int isFibonacci(int num) {
    int a = 0, b = 1;

    while (a <= num) {
        int temp = a;
        a = b;
        b = temp + b;
    }

    return a == num;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (isFibonacci(num)) {
        printf("%d is part of the Fibonacci series.\n", num);
    } else {
        printf("%d is not part of the Fibonacci series.\n", num);
    }

    return 0;
}