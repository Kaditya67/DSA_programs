#include <stdio.h>

// Recursive function to perform merge sort on arr[l..r]
void msort(int arr[], int l, int r) {
    if (l < r) {
        
        int m = l + (r - l) / 2;    // Middle point

        // "Recursively sort"
        msort(arr, l, m);               // [1,3,4,2] --> [1,3]  [4,2]  --> [1][3][4][2]
        msort(arr, m + 1, r);


        // "Merge" the sorted halves
        int n1 = m - l + 1;
        int n2 = r - m;
        int L[n1], R[n2];   // Create temporary arrays


        // "Copy data" to temporary arrays L[] and R[]
        for (int i = 0; i < n1; i++)
            L[i] = arr[l + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[m + 1 + j];

        int i = 0, j = 0, k = l;


        //--------------  Merge the temporary arrays -----------------------
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }


        // ---------------- Copy the remaining elements of L[] and R[] -----------------
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    msort(arr, 0, n - 1);
 
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
