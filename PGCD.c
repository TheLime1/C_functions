#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int PGCD(int nbr1, int nbr2)
{
    int pgcd, i;

    for (i = 1; i <= nbr1 && i <= nbr2; ++i)
    {
        if (nbr1 % i == 0 && nbr2 % i == 0)
        {
            pgcd = i;
        }
    }

    return pgcd;
}

void PGCD(int nbr1, int nbr2);

int main()
{
    PGCD(int nbr1, int nbr2);
    return 0;
}