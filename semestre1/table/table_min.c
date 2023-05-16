#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_min(int *T, int n)
{
    int i;
    int min = T[0];

    for (i = 1; i < n; i++)
    {
        if (T[i] < min)
        {
            min = T[i];
        }
    }

    return min;
}

int get_min(int *T, int n);

int main()
{
    int T[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 10;
    int min;

    min = get_min(T, n);

    printf("The minimum value in the table is: %d\n", min);

    return 0;
}
