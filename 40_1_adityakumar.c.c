#include <stdio.h>
#include <math.h>

// 5n^2+4 or 5n^2

// Function to check if a number is a perfect square
int isPerfectSquare(int num) {
    int squareRoot = sqrt(num);
    return squareRoot * squareRoot == num;
}

// Function to check if a number is a Fibonacci number
int isFibonacci(int num) {
    return isPerfectSquare(5 * num * num + 4) || isPerfectSquare(5 * num * num - 4);
}

int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    if (isFibonacci(number)) {
        printf("%d is a Fibonacci number.\n", number);
    } else {
        printf("%d is not a Fibonacci number.\n", number);
    }

    return 0;
}
