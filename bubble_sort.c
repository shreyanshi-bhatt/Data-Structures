/* Bubble sort code */
#include <stdio.h>

////////Bubble Sort
/*
Compare with the right element
If it is lesser than current then swap
Keep swaping till all passes are completed and all elements on correct pos
Agar baju wala mujse chota hai to swap 
HERE MAX element reaches its place first
eg. 14,56,89,54,02
1. 14,56,54,02,89
2. 14,54,02,56,89
3. 14,02,54,56,89
4. 02,14,54,56,89
*/

int main()
{
  int array[100], n, c, d, swap; ///// one int array & 4 int vars

  printf("Enter number of elements "); //// Input of number of elements to sort
  scanf("%d", &n);

  printf("\nEnter %d integers\n", n); ///// Taking num inputs in array
  for (c = 0; c < n; c++)
    scanf("%d", &array[c]);

  for(c = 0 ; c < n - 1; c++)
  {
    for(d = 0 ; d < n - c - 1; d++)
    {
      if(array[d] > array[d+1]) /* For decreasing order use '<' instead of '>' */ //////////SWAP
      {
        swap       = array[d];
        array[d]   = array[d+1];
        array[d+1] = swap;
      }
    }
  }

  printf("Sorted list in ascending order:\n");//// Printing the elements of the sorted array
  for(c = 0; c < n; c++)
     printf("%d, ", array[c]);

  printf("\nSorted List in descending order: "); 
    for(c=n-1;c>=0;c--)
    {
        printf("%d, ",array[c]);
    }

  return 0;
}