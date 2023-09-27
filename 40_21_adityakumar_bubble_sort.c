#include <stdio.h>

void bubbleSort(int *a, int n);

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
    bubbleSort(a, n);
    for (int i = 0; i < n; i++) {
        printf("a%d = %d\n", i + 1, a[i]);
    }

    return 0;
}

void bubbleSort(int *a, int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
