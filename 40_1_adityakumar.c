<<<<<<< HEAD
#include <stdio.h>

// Function to check if a number is part of the Fibonacci series
int isFibonacci(int num) {
    int a = 0, b = 1;

    while (a < num) {
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
=======
#include<stdio.h>

int fibo(int a,int b,int c);

void main(){
	
	int c,d,a = 0, b = 1;
	
	printf("Enter the no. of elements you want : ");
	scanf("%d",&c);
	
	// if user enter 1
	if(c==1){
		printf("%d",a);
	}
	// if user entered 2
	if(c==2){
	printf("%d %d",a,b);
	}
	//if user enters greater than 2
	printf("%d %d",a,b);  // 0 and 1 will be printed
	fibo(a,b,c); // remaining number will be printed with fibo()
	
	
}


int fibo(int a,int b,int c){

	if(c==2){	// if c decreases to 2 then program ends
		return 0;
	}
	else{	
		printf(" %d",a+b);  // 3rd and next elements will be printed
		return fibo(b,a+b,c-1);  //  c decreases by 1
	}	
	
>>>>>>> 58e2d1c6b7e81a50760e4d1a18696e1ace2df76a
}
