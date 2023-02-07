#include<stdio.h>

void quicksort(int array[50],int first, int last)
{
    int i,j,pivot,temp;

    if(first<last)
    {
        pivot = first;
        i = first;
        j = last;

        while(i<j){
         while(array[i]<=array[pivot]&&i<last)
            i++;
         while(array[j]>array[pivot])
            j--;
         if(i<j){
            temp=array[i];
            array[i]=array[j];
            array[j]=temp;
         }
      }

        temp = array[pivot];
        array[pivot] = array[j];
        array[j] = temp;

        quicksort(array,first ,j-1);
        quicksort(array,j+1,last);

    }
}

int main()
{
    printf("Quick Sort Program\n");
    int array[50],n,c;

    printf("Enter the number of elements: "); //// Input number of elements to be sorted
    scanf("%d",&n);

    printf("\nEnter %d elements: ",n); ////Input nums into array
    for(c=0;c<n;c++)
    {
        scanf("%d",&array[c]);
    }

    quicksort(array,0,n-1); /////Call quicksort

    printf("\nSorted Array is: "); ///Print the sorted array
    for(c=0;c<n;c++)
    {
        printf("%d, ",array[c]);
    }

    return 0;
}

