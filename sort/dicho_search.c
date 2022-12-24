#include <stdio.h>

#define SIZE 10

int binary_search(int array[], int size, int key)
{
    int left, right, mid;

    left = 0;
    right = size - 1;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (array[mid] == key)
        {
            // the key has been found
            return mid;
        }
        else if (array[mid] < key)
        {
            // the key is in the right half of the array
            left = mid + 1;
        }
        else
        {
            // the key is in the left half of the array
            right = mid - 1;
        }
    }

    // the key was not found
    return -1;
}

int main()
{
    int array[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // initialize the array
    int key;
    int index;

    // read the key to be searched from the user
    printf("Enter the key to be searched: ");
    scanf("%d", &key);

    index = binary_search(array, SIZE, key);
    if (index >= 0)
    {
        printf("The key %d was found at index %d\n", key, index);
    }
    else
    {
        printf("The key %d was not found\n", key);
    }

    return 0;
}
