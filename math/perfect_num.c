#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function definition for "perfect_number"
// Takes an integer as an argument and determines if it is a perfect number
void perfect_number(int nbr)
{
    // Initialize variables to store the sum of the factors of "nbr" and the current iteration
    int somme = 0, i;

    // Iterate over the numbers from 1 to "nbr"
    for (i = 1; i < nbr; ++i)
    {
        // If "i" is a factor of "nbr", add it to the sum
        if (nbr % i == 0)
        {
            somme = somme + i;
        }
    }

    // If the sum of the factors of "nbr" equals "nbr", it is a perfect number
    if (somme == nbr)
    {
        printf(" Nombre parfait");
    }
    // Otherwise, it is not a perfect number
    else
    {
        printf(" n'est pas un Nombre parfait");
    }
}

// Function declaration for "perfect_number"
void perfect_number(int nbr);

int main()
{
    // Call the "perfect_number" function with the argument 555
    perfect_number(555);
    return 0;
}
