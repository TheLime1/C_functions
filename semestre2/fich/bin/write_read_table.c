#include <stdio.h>
#include <stdlib.h>

void writeTableToFile(const char *filename, const int *table, int size)
{
    FILE *file = fopen(filename, "wb");
    if (file != NULL)
    {
        fwrite(table, sizeof(int), size, file);
        fclose(file);
    }
}

void readTableFromFile(const char *filename, int *table, int size)
{
    FILE *file = fopen(filename, "rb");
    if (file != NULL)
    {
        fread(table, sizeof(int), size, file);
        fclose(file);
    }
}

int main()
{
    int table[] = {1, 2, 3, 4, 5};
    int size = sizeof(table) / sizeof(table[0]);

    writeTableToFile("table.bin", table, size);

    int readTable[size];
    readTableFromFile("table.bin", readTable, size);

    printf("Table read from file:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", readTable[i]);
    }
    printf("\n");

    return 0;
}
