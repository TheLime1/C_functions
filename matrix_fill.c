#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void matrix_fill(int T[][], int n)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("insert case [%d][%d] data", i, j);
            scanf("%d", &T[i]);
        }
    }
}

void matrix_fill(int T[][], int n);

int main()
{
    int T[99][99], n;
    printf("how many cases are there ?");
    scanf("%d", &n);
    matrix_fill(T[99], n);

    return 0;
}