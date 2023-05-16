#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function definition for "PGCD"
// Takes two integers as arguments and returns their greatest common divisor (GCD)
int PGCD(int nbr1, int nbr2)
{
    // Initialize a variable to store the GCD and a variable to track the current iteration
    int pgcd, i;

    // Iterate over the numbers from 1 to the smaller of "nbr1" and "nbr2"
    for (i = 1; i <= nbr1 && i <= nbr2; ++i)
    {
        // If "i" is a divisor of both "nbr1" and "nbr2", set it as the GCD
        if (nbr1 % i == 0 && nbr2 % i == 0)
        {
            pgcd = i;
        }
    }

    // Return the GCD
    return pgcd;
}

// Function declaration for "PGCD"
void PGCD(int nbr1, int nbr2);

int main()
{
    // Call the "PGCD" function with the arguments "nbr1" and "nbr2"
    PGCD(int nbr1, int nbr2);
    return 0;
}
