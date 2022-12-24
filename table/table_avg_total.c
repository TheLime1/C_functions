#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int avg(int T[], int n)
{
    int i, total = 0, avg;

    for (i = 0; i < n; i++)
    {
        total = total + T[i];
    }
    avg = total / n;
    // hint: you can use <total> for total func
    return avg;
}

int avg(int T[], int n);

int main()
{
    avg(T[], n);

    return 0;
}