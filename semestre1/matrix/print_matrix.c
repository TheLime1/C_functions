#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printMatrix(int matrix[][], int rows, int cols)
{
    int i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void printMatrix(int matrix[][], int rows, int cols);

int main()
{
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    printMatrix(matrix, 3, 3);
    return 0;
}