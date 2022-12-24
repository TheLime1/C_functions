#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int search(int *ctable, int size, int value)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (ctable[i] == value)
        {
            return i;
        }
    }
    return -1;
}

void search(int *ctable, int size, int value);

int main()
{
    int ctable[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int value = 5;
    int result = search(ctable, SIZE, value);
    if (result == -1)
    {
        printf("Value %d not found\n", value);
    }
    else
    {
        printf("Value %d found at index %d\n", value, result);
    }
    return 0;
}
