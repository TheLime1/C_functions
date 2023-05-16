#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readDetailsFromFile()
{
    FILE *fichier = fopen("fichier.txt", "r");
    if (fichier != NULL)
    {
        char line[100];
        while (fgets(line, sizeof(line), fichier) != NULL)
        {
            printf("%s", line);
        }
    }
    fclose(fichier);
}

int main()
{
    readDetailsFromFile();

    return 0;
}
