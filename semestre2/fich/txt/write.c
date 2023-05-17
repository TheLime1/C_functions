#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void writeDetailsToFile(const char *nom, const char *prenom)
{
    FILE *fichier = fopen("fichier.txt", "w");
    if (fichier != NULL)
    {
        fprintf(fichier, "voici les details;\n");
        fprintf(fichier, "nom: %s prenom: %s\n", nom, prenom);
    }
    fclose(fichier);
}

int main()
{
    const char *nom = "Doe";
    const char *prenom = "John";
    writeDetailsToFile(nom, prenom);

    remove("fichier.txt"); // supprimer le fichier
    return 0;
}
