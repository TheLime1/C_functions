#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5

// Function definition for "insertion_sort"
// Takes an integer array and its size as arguments and sorts the array in ascending order using the insertion sort algorithm
void insertion_sort(int arr[], int size)
{
    int i, key, j;
    for (i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function declaration for "insertion_sort"
void insertion_sort(int arr[], int size);

int main()
{
    int arr[SIZE] = {5, 1, 4, 2, 3};

    // call the "insertion_sort" function
    insertion_sort(arr, SIZE);

    // print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
