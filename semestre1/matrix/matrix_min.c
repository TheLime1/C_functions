#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_min(int cmatrix[][10], int rows, int cols)
{
    int i, j, min = cmatrix[0][0];
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            if (cmatrix[i][j] < min)
            {
                min = cmatrix[i][j];
            }
        }
    }
    return min;
}

int main()
{
    int cmatrix[5][10] = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
                          {11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
                          {21, 22, 23, 24, 25, 26, 27, 28, 29, 30},
                          {31, 32, 33, 34, 35, 36, 37, 38, 39, 40},
                          {41, 42, 43, 44, 45, 46, 47, 48, 49, 50}};
    int min = get_min(cmatrix, 5, 10);
    printf("Minimum value: %d\n", min);

    return 0;
}
