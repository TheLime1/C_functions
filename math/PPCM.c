#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function definition for "ppcm"
// Takes two integers as arguments and returns their least common multiple (LCM)
int ppcm(int nbr1, int nbr2)
{
    // Initialize a variable to store the LCM and a variable to track the current iteration
    int ppcm, b = 1;

    // Prompt the user to enter two integers
    printf("Entrez deux entiers: ");
    scanf("%d %d", &nbr1, &nbr2);

    // Set the initial value of "ppcm" to the greater of "nbr1" and "nbr2"
    ppcm = (nbr1 > nbr2) ? nbr1 : nbr2;

    // Loop indefinitely (since "b" is always set to 1)
    while (b == 1)
    {
        // If "ppcm" is a multiple of both "nbr1" and "nbr2", return it as the LCM
        if (ppcm % nbr1 == 0 && ppcm % nbr2 == 0)
        {
            return ppcm;
        }
        // Otherwise, increment "ppcm" and continue the loop
        ++ppcm;
    }
}

// Function declaration for "ppcm"
int ppcm(int nbr1, int nbr2);

int main()
{
    // Call the "ppcm" function with the arguments 777 and 554
    ppcm(777, 554);
}
