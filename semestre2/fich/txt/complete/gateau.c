#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int type;
    int nbr_ing;
    float prix;
} gateau;

void saisir_gateau(gateau *g)
{
    printf("Entrez le type de gâteau : ");
    scanf("%d", &(g->type));

    printf("Entrez le nombre d'ingrédients : ");
    scanf("%d", &(g->nbr_ing));

    printf("Entrez le prix : ");
    scanf("%f", &(g->prix));
}

void ajouter_gateau_ft(gateau g, char nom_fich[])
{
    FILE *fichier;

    fichier = fopen(nom_fich, "a");

    if (fichier == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier !\n");
        exit(1);
    }

    fprintf(fichier, "%d %d %f\n", g.type, g.nbr_ing, g.prix);

    fclose(fichier);
}

int nbre_gateaux_ft(char nom_fich[])
{
    FILE *fichier;
    int nbre_gateaux = 0;
    gateau g;

    fichier = fopen(nom_fich, "r");

    if (fichier == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier !\n");
        exit(1);
    }

    while (fscanf(fichier, "%d %d %f", &(g.type), &(g.nbr_ing), &(g.prix)) != EOF)
    {
        nbre_gateaux++;
    }

    // Fermeture du fichier
    fclose(fichier);

    return nbre_gateaux;
}

void afficher_gateau(char nom_fich[], int num)
{
    FILE *fichier = fopen(nom_fich, "r");
    gateau g;
    int i;
    if (f != NULL)
    {
        for (i = 0; i < num; i++)
        {
            fscanf(f, "%d %d %f", &g.type, &g.nbr_ing, &g.prix);
        }
        printf("Type: %d\nNombre d'ingrédients: %d\nPrix: %.2f\n", g.type, g.nbr_ing, g.prix);
        fclose(f);
    }
    else
    {
        printf("Impossible d'ouvrir le fichier %s", nom_fich);
    }
}
