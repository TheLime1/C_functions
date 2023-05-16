#include <stdio.h>
#include <stdlib.h>

void printTable(int *table, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", table[i]);
    }
    printf("\n");
}

int main()
{
    int *table = NULL;
    int size = 0;

    // Allocate memory for the table using malloc
    size = 5;
    table = (int *)malloc(size * sizeof(int));
    if (table == NULL)
    {
        printf("Failed to allocate memory for the table.\n");
        return 1;
    }

    // Initialize the table
    for (int i = 0; i < size; i++)
    {
        table[i] = i + 1;
    }

    // Print the table
    printf("Table after malloc:\n");
    printTable(table, size);

    // Reallocate memory for the table using realloc
    size = 8;
    int *newTable = (int *)realloc(table, size * sizeof(int));
    if (newTable != NULL)
    {
        table = newTable;
        // Initialize the additional elements
        for (int i = size - 3; i < size; i++)
        {
            table[i] = i + 1;
        }
    }

    // Print the table after reallocation
    printf("Table after realloc:\n");
    printTable(table, size);

    // Deallocate memory for the table using free
    free(table);

    return 0;
}
