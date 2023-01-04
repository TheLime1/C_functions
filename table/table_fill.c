#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void table_fill(int *T, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("insert case %d data", i);
        scanf("%d", &T[i]);
    }
}

void table_fill(int *T, int n);

int main()
{
    int T[99], n;
    printf("how many cases are there ?");
    scanf("%d", &n);
    table_fill(T, n);

    return 0;
}
