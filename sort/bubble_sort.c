#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5

// Function definition for "bubble_sort"
// Takes an integer array and its size as arguments and sorts the array in ascending order using the bubble sort algorithm
void bubble_sort(int arr[], int size)
{
    int i, j;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function declaration for "bubble_sort"
void bubble_sort(int arr[], int size);

int main()
{
    int arr[SIZE] = {5, 1, 4, 2, 3};

    // call the "bubble_sort" function
    bubble_sort(arr, SIZE);

    // print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
