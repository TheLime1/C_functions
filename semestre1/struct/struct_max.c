#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct
typedef struct element
{
    int value;
} element;

// Function to find the maximum element in the struct
element find_max(element *array, int size)
{
    element max;
    max.value = array[0].value;
    for (int i = 1; i < size; i++)
    {
        if (array[i].value > max.value)
        {
            max = array[i];
        }
    }
    return max;
}

int main()
{
    // Initialize the array of structs
    element array[5] = {{2}, {5}, {1}, {3}, {4}};

    // Find the maximum element
    element max = find_max(array, 5);

    // Print the maximum element
    printf("The maximum element has a value of %d.\n", max.value);

    return 0;
}
