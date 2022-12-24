#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

void add_to_ctable(int ctable[SIZE], int value, int index)
{
    // shift the elements to the right of the index one position to the right
    int i;
    for (i = SIZE - 1; i > index; i--)
    {
        ctable[i] = ctable[i - 1];
    }

    // insert the value at the specified index
    ctable[index] = value;
}

void add_to_ctable(int ctable[SIZE], int value, int index);

int main()
{
    int ctable[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int value, index;

    // read the value and index from the user
    printf("Enter the value to be added: ");
    scanf("%d", &value);
    printf("Enter the index at which to add the value: ");
    scanf("%d", &index);

    // add the value to the ctable
    add_to_ctable(ctable, value, index);

    // print the modified ctable
    printf("Modified ctable:\n");
    int i;
    for (i = 0; i < SIZE; i++)
    {
        printf("%d ", ctable[i]);
    }
    printf("\n");

    return 0;
}
