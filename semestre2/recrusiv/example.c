#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void recursiveFunction(int n);

void recursiveFunction(int n)
{
    // Base case
    if (n <= 0)
        return;

    // Recursive call
    recursiveFunction(n - 1);

    // Print the current value
    printf("%d ", n);
}

int main()
{
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    recursiveFunction(num);

    return 0;
}
