#include <stdio.h>

int main() {

   int rows, coef = 1, space, i, j;

   printf("Enter the number of rows: ");	// input for no. of lines of pascal traingle
   scanf("%d", &rows);

   for (i = 0; i < rows; i++) {
      for (space = 1; space <= rows - i; space++)
         printf("  ");			// space between each term to make a triangular shape
      for (j = 0; j <= i; j++) {
         if (j == 0 || i == 0)
            coef = 1;
         else
            coef = coef * (i - j + 1) / j;		// generates the middle term of pascal triangle
         printf("%4d", coef);
      }

      printf("\n");  // space between each line

   }

   return 0;
}
