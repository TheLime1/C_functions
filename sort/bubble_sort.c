#include <stdio.h>

#define SIZE 5

int main()
{
    int i, j;
    int array[SIZE] = {4, 3, 1, 2, 5}; // initialize the array

    // perform bubble sort
    for (i = 0; i < SIZE - 1; i++)
    {
        for (j = 0; j < SIZE - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                // swap the elements if they are in the wrong order
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    // print the sorted array
    printf("Sorted array: ");
    for (i = 0; i < SIZE; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
