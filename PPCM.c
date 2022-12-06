#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ppcm(int nbr1, int nbr2)
{
    int ppcm, b = 1;

    printf("Entrez deux entiers: ");
    scanf("%d %d", &nbr1, &nbr2);

    ppcm = (nbr1 > nbr2) ? nbr1 : nbr2;

    // Toujours vrai
    while (b == 1)
    {
        if (ppcm % nbr1 == 0 && ppcm % nbr2 == 0)
        {
            return ppcm;
        }
        ++ppcm;
    }
}
int ppcm(int nbr1, int nbr2);

int main()
{
    ppcm(777, 554)
}
