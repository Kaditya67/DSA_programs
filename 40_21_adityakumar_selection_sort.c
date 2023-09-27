#include <stdio.h>

void selectionSort(int *a, int n);

int main() {
    int n;
    printf("Specify the no. of elements :");
    scanf("%d", &n);
    printf("Enter elements : \n");
    int a[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("Before Sorting : \n");
    for (int i = 0; i < n; i++) {
        printf("a%d = %d\n", i + 1, a[i]);
    }

    printf("After Sorting : ");
    selectionSort(a, n);
    for (int i = 0; i < n; i++) {
        printf("a%d = %d\n", i + 1, a[i]);
    }

    return 0;
}

void selectionSort(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[i]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
