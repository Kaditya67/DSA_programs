#include<stdio.h>

void main(){
	int b;
	// array of numbers
	int a[10]={1,2,0,4,5,9,8,6,11,3};
	// b=1st element
	b = a[0]; 
	
	for(int i=0;i<10;i++){

		if(b < a[i]){ //if condition is true then a[i] will be assigned to b
			b = a[i];
		}
	
	}
	
	//  print largest element in array
	printf("Largest : %d",b);
}
