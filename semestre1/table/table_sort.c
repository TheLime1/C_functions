#include <stdio.h>

#define TABLE_SIZE 10

// function prototype
void bubble_sort(int table[], int size);

int main()
{
    int i;
    int table[TABLE_SIZE] = {3, 4, 1, 7, 2, 9, 5, 8, 6, 0}; // initialize the table with unsorted values

    // sort the table using bubble sort
    bubble_sort(table, TABLE_SIZE);

    // print the sorted table
    printf("Sorted table: ");
    for (i = 0; i < TABLE_SIZE; i++)
    {
        printf("%d ", table[i]);
    }
    printf("\n");

    return 0;
}

// function definition
void bubble_sort(int table[], int size)
{
    int i, j;

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (table[j] > table[j + 1])
            {
                // swap the elements
                int temp = table[j];
                table[j] = table[j + 1];
                table[j + 1] = temp;
            }
        }
    }
}
