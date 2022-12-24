#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 3
#define COLS 3

void add_to_matrix(int matrix[ROWS][COLS], int row, int col, int element)
{
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS)
    {
        printf("Invalid matrix position (%d, %d)\n", row, col);
        return;
    }

    matrix[row][col] = element;
}

void add_to_matrix(int matrix[ROWS][COLS], int row, int col, int element);

int main()
{
    int matrix[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}; // initialize the matrix
    int row, col, element;

    // read the position and element to be added from the user
    printf("Enter the row, column, and element to be added: ");
    scanf("%d %d %d", &row, &col, &element);

    add_to_matrix(matrix, row, col, element); // add the element to the matrix

    // print the modified matrix
    printf("Modified matrix:\n");
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
