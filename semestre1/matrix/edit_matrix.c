#include <stdio.h>

#define ROWS 3
#define COLS 3

void edit_element(int matrix[ROWS][COLS], int row, int col, int value)
{
    matrix[row][col] = value;
}

void edit_element(int matrix[ROWS][COLS], int row, int col, int value);

int main()
{
    int matrix[ROWS][COLS];
    int row, col, value;
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

    // read the element to be edited from the user
    printf("Enter the row, column, and value of the element to be edited: ");
    scanf("%d %d %d", &row, &col, &value);

    // edit the element
    edit_element(matrix, row, col, value);

    // print the modified matrix
    printf("Modified matrix:\n");
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
