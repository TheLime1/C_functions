#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 3
#define COLS 3

int search_cmatrix(int cmatrix[ROWS][COLS], int value)
{
    int i, j;

    // search the cmatrix for the value
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (cmatrix[i][j] == value)
            {
                // value found, return the index
                return i * COLS + j;
            }
        }
    }

    // value not found, return -1
    return -1;
}

void search_cmatrix(int cmatrix[ROWS][COLS], int value);

int main()
{
    int cmatrix[ROWS][COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    int value;
    int index;

    // read the value to be searched from the user
    printf("Enter the value to be searched: ");
    scanf("%d", &value);

    // search the cmatrix for the value
    index = search_cmatrix(cmatrix, value);

    if (index == -1)
    {
        printf("Value not found.\n");
    }
    else
    {
        printf("Value found at index %d.\n", index);
    }

    return 0;
}
