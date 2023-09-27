#include<stdio.h>

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void qsort(int a[], int l, int h) {

    if (l < h) {
        
        int target = a[l]; // Choose the 1st element as the target
        int i = l;  

        for (int j = l + 1; j <= h; j++) {
            
            // If Target is greater than current element
            if (target >= a[j]) {
                
                i++;                // Increment index of the smaller element
                swap(&a[i], &a[j]); // Swap a[i] and a[j]
            }
        }

        swap(&a[i], &a[l]);

        // Recursively sort elements
        qsort(a, l, i - 1);
        qsort(a, i + 1, h);
    }
}

int main(){

    int n;
    printf("\n Enter the numbers to be sorted :");
    scanf("%d",&n);
    int a[n];

    printf("\n Enter Numbers one by one : \n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("\n Before Sorting : \n");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    
    // -------------- Sorting Starts ----------------

    qsort(a,0,n-1);

    // -------------- Sorting Ends ------------------
    printf("\n After Sorting : \n");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
   return 0; 
}