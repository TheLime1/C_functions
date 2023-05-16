#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void openFile(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Failed to open the file.\n");
        return;
    }

    // File operations

    fclose(file);
}

int main()
{
    const char *filename = "example.txt";
    openFile(filename);
    return 0;
}
