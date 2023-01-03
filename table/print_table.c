#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_array(int array[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void print_array(int array[], int size);

int main()
{
    int array[5] = {1, 2, 3, 4, 5};
    print_array(array, 5);
    return 0;
}
