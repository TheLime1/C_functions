#include <stdio.h>

#define ROWS 3
#define COLS 3

void bubble_sort_matrix(int matrix[ROWS][COLS])
{
    int i, j;
    int temp;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (matrix[i][j] > matrix[i][j + 1])
            {
                // swap the elements
                temp = matrix[i][j];
                matrix[i][j] = matrix[i][j + 1];
                matrix[i][j + 1] = temp;
            }
        }
    }
}

void bubble_sort_matrix(int matrix[ROWS][COLS]);

int main()
{
    int matrix[ROWS][COLS] = {
        {4, 2, 3},
        {7, 5, 6},
        {1, 8, 9}};

    bubble_sort_matrix(matrix);

    // print the sorted matrix
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
