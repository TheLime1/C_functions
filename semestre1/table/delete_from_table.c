#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLS 5

// Function definition for "delete_element"
// Takes an array of integers and the index of the element to be deleted as arguments
// Deletes the element by shifting the elements to the right of it one column to the left
void delete_element(int *table, int index)
{
    int i;

    // Shift the elements to the right of the element to be deleted one column to the left
    for (i = index; i < COLS - 1; i++)
    {
        table[i] = table[i + 1];
    }
}

// Function declaration for "delete_element"
void delete_element(int *table, int index);

int main()
{
    int table[COLS];
    int col;
    int i;

    // initialize the table with some values
    for (i = 0; i < COLS; i++)
    {
        table[i] = i;
    }

    // print the original table
    printf("Original table:\n");
    for (i = 0; i < COLS; i++)
    {
        printf("%d ", table[i]);
    }
    printf("\n");

    // read the element to be deleted from the user
    printf("Enter the column of the element to be deleted: ");
    scanf("%d", &col);

    // Call the "delete_element" function to delete the element
    delete_element(table, col);

    // print the modified table
    printf("Modified table:\n");
    for (i = 0; i < COLS - 1; i++)
    {
        printf("%d ", table[i]);
    }
    printf("\n");

    return 0;
}
