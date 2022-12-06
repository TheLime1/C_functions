#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void perfect_number(int nbr)
{
    int somme = 0, i;

    for (i = 1; i < nbr; ++i)
    {
        if (nbr % i == 0)
        {
            somme = somme + i;
        }
    }
    if (somme == nbr)
    {
        printf(" Nombre parfait");
    }
    else
    {
        printf(" n'est pas un Nombre parfait");
    }
}

void perfect_number(int nbr);

int main()
{
    perfect_number(555);
    return 0;
}