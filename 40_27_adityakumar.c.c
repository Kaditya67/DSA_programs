#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice, s, n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int a[n];
    int beg, end, mid;

    printf("Enter the elements of Array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    do {
        printf("Press 1 to Search\nPress 2 to Exit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to search: ");
                scanf("%d", &s);

                beg = 0;
                end = n - 1;
                mid = (beg + end) / 2;

                while (beg <= end && a[mid] != s) {
                    if (s < a[mid]) {
                        end = mid - 1;
                    } else {
                        beg = mid + 1;
                    }
                    mid = (beg + end) / 2;
                }
                
                if (beg <= end) {
                    printf("Element Found\n");
                } else {
                    printf("Element Not Found\n");
                }
                break;

            case 2:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    } while (1);

    return 0;
}
