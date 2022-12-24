#include <stdio.h>

#define SIZE 5

int main()
{
    int i, j;
    int array[SIZE] = {4, 3, 1, 2, 5}; // initialize the array

    // perform insertion sort
    for (i = 1; i < SIZE; i++)
    {
        int key = array[i]; // the element to be inserted
        j = i - 1;
        // shift the elements of the sorted part of the array to the right until the proper position for the key is found
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key; // insert the key into its proper position
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
