#include <stdio.h>

// ----------------- Insertion sort ----------------
void insertionSort(int arr[], int n) {
    
    for (int i = 1; i < n; i++) {
        int key = arr[i];   // Store the "current element" to be inserted
        int j = i - 1;      // Initialize the index for the "previous element"


        // Shift elements ahead that are greater than the key their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; 
            j--;
        }
        arr[j + 1] = key; // Insert the key into its correct position
    }

}

int main() {
    
    int n;
    printf("\n Enter the numbers to be sorted :");
    scanf("%d",&n);
    int arr[n];

    printf("\n Enter Numbers one by one : \n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printf("Unsorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]); // Print the unsorted array
    }

    insertionSort(arr, n); // Sort the array using insertion sort

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]); // Print the sorted array
    }

    return 0;
}
