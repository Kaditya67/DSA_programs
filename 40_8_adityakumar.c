#include <stdio.h>

int compareArrays(int arr1[], int arr2[], int size) {
	for (int i = 0; i < size; i++) {
		if (arr1[i] != arr2[i]) {
			return 0; // Arrays are not identical
		}
	}
	    return 1; // Arrays are identical
}

int main() {
	int size = 5;
	int array1[] = {1, 2, 3, 4, 5};
	int array2[] = {1, 2, 3, 4, 5};
	
	    
	if (compareArrays(array1, array2, size)) {
		printf("Arrays are identical.\n");
	} else {
		printf("Arrays are not identical.\n");
	}
	    
	    return 0;
}

