#include <stdio.h>

#define SIZE 10

int main()
{
    int i, left, right, mid, key;
    int array[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // initialize the array

    // read the key to be searched from the user
    printf("Enter the key to be searched: ");
    scanf("%d", &key);

    // perform binary search
    left = 0;
    right = SIZE - 1;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (array[mid] == key)
        {
            // the key has been found
            printf("The key %d was found at index %d\n", key, mid);
            return 0;
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
    printf("The key %d was not found\n", key);

    return 0;
}
