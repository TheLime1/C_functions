#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_max(int matrix[][99], int n, int m)
{
    // Initialize the maximum value to the first element in the matrix
    int max = matrix[0][0];
    // Iterate through the rows and columns of the matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // If the current element is greater than the maximum value, update the maximum value
            if (matrix[i][j] > max)
            {
                max = matrix[i][j];
            }
        }
    }
    // Return the maximum value
    return max;
}

int find_max(int matrix[][99], int n, int m);

int main()
{
    int matrix[99][99], n, m;
    // Read the dimensions of the matrix from the user
    printf("Enter the number of rows in the matrix: ");
    scanf("%d", &n);
    printf("Enter the number of columns in the matrix: ");
    scanf("%d", &m);
    // Fill the matrix with values
    printf("Enter the values for the matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    // Find the maximum value in the matrix
    int max = find_max(matrix, n, m);
    // Print the maximum value
    printf("The maximum value in the matrix is: %d\n", max);
    return 0;
}