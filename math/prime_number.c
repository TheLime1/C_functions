#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function prototype
int is_prime(int n);

// function definition
int is_prime(int n)
{
    int i;
    // check if n is divisible by any integer from 2 to n-1
    for (i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            // n is divisible by i, so it is not prime
            return 0;
        }
    }
    // n is not divisible by any integer from 2 to n-1, so it is prime
    return 1;
}

int is_prime(int n);

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    if (is_prime(n))
    {
        printf("%d is a prime number.\n", n);
    }
    else
    {
        printf("%d is not a prime number.\n", n);
    }
    return 0;
}
