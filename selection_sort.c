#include<stdio.h>

//////Selection Sort
/*
Find the min element and swap it with the first element
Find the second min element and swap it with second & so on 
HERE MIN element reaches its place first
eg. 14,56,89,54,02
1. 02,56,89,54,14
2. 02,14,89,54,56
3. 02,14,54,89,56
4. 02,14,54,56,89
SORTED
*/

int main()
{
    printf("Selection Sort Program\n");
    int array[100],n,c,d,position,temp; /////one int array & 5 ints

    printf("Enter the number of elements: ");
    scanf("%d",&n); //////Input of number of elements to sort

    printf("\nEnter %d elements",n); //////// Enter in an array
    for(c=0;c<n;c++)
    {
        scanf("%d",&array[c]);
    }

    for(c=0;c<n-1;c++)/////Selection Sort Algo
    {
        position = c;
        for(d=c+1;d<n;d++) ////For finding the min element
        {
            if(array[position] > array[d])
            {
                position = d;
            }
        }
        if(position != c) //// For swapping the min element with the respective pos
        {
            temp = array[c];
            array[c] = array[position];
            array[position] = temp;
        }
    }

    printf("\nSorted List in ascending order: "); ////Print the sorted array elements
    for(c=0;c<n;c++)
    {
        printf("%d, ",array[c]);
    }

    printf("\nSorted List in descending order: "); 
    for(c=n-1;c>=0;c--)
    {
        printf("%d, ",array[c]);
    }

    return 0;
}