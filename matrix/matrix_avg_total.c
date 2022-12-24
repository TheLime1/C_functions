#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 3
#define COLS 3

// Function definition for "calculate_total_and_average"
// Takes a 3x3 integer matrix as an argument and calculates the total and average of its elements
void calculate_total_and_average(int matrix[ROWS][COLS])
{
    // Initialize variables to store the total and average
    int total = 0;
    float average;

    // Iterate over the elements of the matrix and add them to the total
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            total += matrix[i][j];
        }
    }

    // Calculate the average by dividing the total by the number of elements in the matrix
    average = (float)total / (ROWS * COLS);

    // Print the total and average
    printf("Total: %d\n", total);
    printf("Average: %.2f\n", average);
}

// Function declaration for "calculate_total_and_average"
void calculate_total_and_average(int matrix[ROWS][COLS]);

int main()
{
    int matrix[ROWS][COLS];
    int i, j;

    // initialize the matrix with some values
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            matrix[i][j] = i + j;
        }
    }

    // call the "calculate_total_and_average" function
    calculate_total_and_average(matrix);

    return 0;
}
