#include <stdio.h>

#define SIZE 10

void edit_element(int ctable[], int index, int new_value)
{
    ctable[index] = new_value;
}

void edit_element(int ctable[], int index, int new_value);

int main()
{
    int i, index, new_value;
    int ctable[SIZE];

    // initialize the ctable with some values
    for (i = 0; i < SIZE; i++)
    {
        ctable[i] = i;
    }

    // print the original ctable
    printf("Original ctable:\n");
    for (i = 0; i < SIZE; i++)
    {
        printf("%d ", ctable[i]);
    }
    printf("\n");

    // read the index and new value from the user
    printf("Enter the index of the element to be edited: ");
    scanf("%d", &index);
    printf("Enter the new value for the element: ");
    scanf("%d", &new_value);

    // edit the element in the ctable
    edit_element(ctable, index, new_value);

    // print the modified ctable
    printf("Modified ctable:\n");
    for (i = 0; i < SIZE; i++)
    {
        printf("%d ", ctable[i]);
    }
    printf("\n");

    return 0;
}
