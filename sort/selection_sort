#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5

// Function definition for "selection_sort"
// Takes an integer array and its size as arguments and sorts the array in ascending order using the selection sort algorithm
void selection_sort(int arr[], int size)
{
    int i, j, min_idx;
    for (i = 0; i < size - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// Function declaration for "selection_sort"
void selection_sort(int arr[], int size);

int main()
{
    int arr[SIZE] = {5, 1, 4, 2, 3};

    // call the "selection_sort" function
    selection_sort(arr, SIZE);

    // print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
