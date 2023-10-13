#include <stdio.h>

// Function Prototypes
void insert(int array[]);
void delete(int array[]);
void traverse(int array[]);
void search(int array[]);

int n=0; // global variable

// Main function
int main() {
    int arr[100];// Declaring Array of size 100
    int op;

    while (1) {
        printf(" *********Array operations******** \n");
        printf("\n1.Insert Elements in Array");
        printf("\n2.Delete Elements from the Array");
        printf("\n3.Traverse the elements of the Array");
        printf("\n4.Search if the element is present or not in the Array\n");
        scanf("%d", &op);
	
        switch (op) {
            case 1:
                insert(arr);
                break;
            case 2:
                delete(arr);
                break;
            case 3:
                traverse(arr);
                break;
            case 4:
                search(arr);
                break;

            // Default msg if the choice is wrong
            default:
                printf("Invalid Choice");
        }
    }

    return 0; // Indicate successful program execution
}

// Function Definitions

// Insert Function
void insert(int array[]) {
	
	printf("Enter the element : ");
	if(n<100){
		scanf("%d",&array[n]);
		n++;
	}
	else{
		printf("\nArray is full ");
	}
	
	
}

// Delete function
void delete(int array[]) {
	int a;
	
	printf("Enter the element to be deleted :");
	scanf("%d",&a);
	for(int i=0;i<n;i++){
		if(a==array[i]){
			for(int j=i;j<n;j++){
				array[j]=array[j+1];
			}
			n=n-1;
			break;
		}
	}
	
}

// Traverse Function
void traverse(int array[]) {
	printf("Displaying all array Elements :\n");
    	for(int i=0;i<n;i++){
    		printf("%d \n",array[i]);
    	}	
}

// Search Function
void search(int array[]) {
	int j,k=0;
	printf("Searching for element.. ");
	scanf("%d",&j);
    	printf("Checking Your Element ...\n");
    
    	for(int i=0;i<n;i++){
    
    	if(j==array[i]){
    		k=1;
    	}
    
    	}
    	if(k==1){
    		printf("Element is present \n");
    	}else{
    		printf("Element is not present \n");
    	}
    
}
