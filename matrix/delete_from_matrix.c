#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 3
#define COLS 3

void delete_element(int matrix[ROWS][COLS], int row, int col)
{
    int i, j;

    // delete the element by shifting the elements above it down one row
    for (i = row; i < ROWS - 1; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            matrix[i][j] = matrix[i + 1][j];
        }
    }
}

void delete_element(int matrix[ROWS][COLS], int row, int col);

int main()
{
    int matrix[ROWS][COLS];
    int row, col;
    int i, j;

    // initialize the matrix with some values
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            matrix[i][j] = i + j;
        }
    }

    // print the original matrix
    printf("Original matrix:\n");
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // read the element to be deleted from the user
    printf("Enter the row and column of the element to be deleted: ");
    scanf("%d %d", &row, &col);

    // call the "delete_element" function
    delete_element(matrix, row, col);

    // print the modified matrix
    printf("Modified matrix:\n");
    for (i = 0; i < ROWS - 1; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}