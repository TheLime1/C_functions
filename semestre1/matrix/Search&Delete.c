#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 3
#define COLS 4

int searchAndDelete(int matrix[ROWS][COLS], int element)
{
    int i, j;

    // search for the element in the matrix
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (matrix[i][j] == element)
            {
                // the element was found
                matrix[i][j] = 0; // delete the element by replacing it with 0
                return 0;
            }
        }
    }

    // the element was not found
    return -1;
}

int searchAndDelete(int matrix[ROWS][COLS], int element);

int main()
{
    int matrix[ROWS][COLS] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    int element;
    int result;

    // read the element to be searched from the user
    printf("Enter the element to be searched and deleted: ");
    scanf("%d", &element);

    // search for the element in the matrix and delete it if it is found
    result = searchAndDelete(matrix, element);

    if (result == -1)
    {
        printf("The element was not found in the matrix.\n");
    }
    else
    {
        printf("The element was deleted from the matrix.\n");
    }

    return 0;
}
