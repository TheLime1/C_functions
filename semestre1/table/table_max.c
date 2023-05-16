#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to find the maximum value in a table
int max_value(int *T, int n)
{
    int i, max = T[0];
    for (i = 1; i < n; i++)
    {
        if (T[i] > max)
            max = T[i];
    }
    return max;
}

// function prototype
int max_value(int *T, int n);

int main()
{
    int T[10] = {1, 5, 2, 8, 9, 3, 6, 7, 4, 0};
    int n = 10;

    // find the maximum value in the table
    int max = max_value(T, n);
    printf("The maximum value in the table is: %d\n", max);

    return 0;
}
