#include "fichiersBinaires.h"
#include "general.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void enregistrer_dans_fichier_binaire(char* nomFichier)
{
    FILE* fp;
    int nbEmployes;
    Exemple_struct strucutre;

    fp = fopen(nomFichier, "wb"); //wb, rb, ab, wb+, rb+, ab+

    if(fp == NULL)
    {
        printf("\nErreur pendant la creation du fichier: \"%s\"\n", nomFichier);
        return;
    }

    printf("Donner le nombre des employes: ");
    scanf("%d", &nbEmployes);
    printf("\n");

    Exemple_struct *structures_array = (Exemple_struct*)malloc(nbEmployes*sizeof(Exemple_struct));

    for(int i=0; i<nbEmployes; i++)
    {
        printf("Donner le nom de l employe #%d: ", i+1);
        scanf("%s", strucutre.nom);
        printf("Donner le prenom de l employe #%d: ", i+1);
        scanf("%d", &strucutre.int_num);
        printf("Donner le nombre d enfants de l employe #%d: ", i+1);
        scanf("%f", &strucutre.float_num);
        printf("\n");
        structures_array[i] = strucutre;
        // enregistrer dans le fichier binaire un par un
        //fwrite(structures_array, sizeof(Exemple_struct), 1, fp);
    }

    // enregistrer l'array entier dans le fichier binaire
    fwrite(structures_array, sizeof(Exemple_struct), nbEmployes, fp);

    free(structures_array);
    fclose(fp);
}

void chercher_chaine_dans_fich_binaire(char* nomFichier, char* nom)
{
    FILE* fp;
    Exemple_struct strucutre;
    int nbLigne = 0;

    fp = fopen(nomFichier, "rb");

    if(fp == NULL)
    {
        printf("\nErreur pendant l'ouverture du fichier: \"%s\"\n", nomFichier);
        return;
    }

    while( fread(&strucutre, sizeof(Exemple_struct), 1, fp) )
    {

        nbLigne++;
        if( strcmp(strucutre.nom, nom) == 0 )
        {
            printf("Un employe avec le nom \"%s\" est inscrit dans la ligne %d\n", nom, nbLigne);
            return;
        }
    }

    printf("aucun employe avec le nom \"%s\" n est inscrit dans le fichier %s", nom, nomFichier);

    fclose(fp);
}

void afficher_tous_avec_NPlus_bin(char* nomFichier, int n)
{
    FILE* fp;
    Exemple_struct strucutre;
    int nbLigne = 0;

    fp = fopen(nomFichier, "rb");

    if(fp == NULL)
    {
        printf("\nErreur pendant l'ouverture du fichier: \"%s\"\n", nomFichier);
        return;
    }

    while( fread(&strucutre, sizeof(Exemple_struct), 1, fp) )
    {
        nbLigne++;
        if(strucutre.int_num >= n)
            printf("L employe dans la ligne %d a %d enfants\n", nbLigne, strucutre.int_num);
    }

    fclose(fp);
}

void afficher_contenu_fichier_binaire(char* nomFichier)
{
    FILE* fp;
    Exemple_struct strucutre;
    int nbLignes = 0;

    fp = fopen(nomFichier, "rb"); //a, w, r, w+, r+, a+
    if(fp == NULL)
    {
        printf("\nErreur pendant l'ouverture du fichier: \"%s\"\n", nomFichier);
        return;
    }

    if( !fread(&strucutre, sizeof(Exemple_struct), 1, fp) )
    {
        printf("\nLe fichier \"%s\" est vide.\n", nomFichier);
    }
    else
    {
        // if the file wasn't empty,
        // the previous fread in the if statement
        // would've advanced the file pointer by one
        rewind(fp);
        printf("Contenu du fichier \"%s\": \n", nomFichier);
        while( fread(&strucutre, sizeof(Exemple_struct), 1, fp) )
        {
            nbLignes++;
            printf("%s %d %f\n", strucutre.nom, strucutre.int_num, strucutre.float_num);
        }

        printf("\n");
    }

    fclose(fp);
}

int nbLignes(char nomFichier[])
{
    int nbLignes = 0;
    Exemple_struct strucutre;
    FILE* fp;

    fp = fopen(nomFichier, "rb");

    if( fp == NULL )
    {
        printf("\nErreur pendant l'ouverture du fichier: \"%s\"\n", nomFichier);
        return -1;
    }

    while( fread(&strucutre, sizeof(Exemple_struct), 1, fp) )
        nbLignes++;

    fclose(fp);
    return nbLignes;
}

void supprimer_element_avec_0_enfants_bin(char* nomFichier)
{
    Exemple_struct strucutre;
    FILE *fp, *fp2;
    fp = fopen(nomFichier, "rb");
    fp2 = fopen("temp.txt", "wb");

    if( fp == NULL || fp2 == NULL )
    {
        printf("\nErreur pendant l'ouverture des fichiers\n");
        return;
    }

    while( fread(&strucutre, sizeof(Exemple_struct), 1, fp) )
    {
        if(strucutre.int_num != 0)
            fwrite(&strucutre, sizeof(Exemple_struct), 1, fp2);
    }

    fclose(fp);
    remove(nomFichier);
    fclose(fp2);
    rename("temp.txt", nomFichier);
}


void copierFichierBIN(char* nomFichier, char* nomFichier2)
{
    FILE *fp, *fp2;
    Exemple_struct strucutre;

    fp = fopen(nomFichier, "rb");
    fp2 = fopen(nomFichier2, "wb");

    if(fp == NULL || fp2 == NULL)
    {
        printf("\nErreur\n");
        return;
    }

    while( fread(&strucutre, sizeof(Exemple_struct), 1, fp) )
    {
        fwrite(&strucutre, sizeof(Exemple_struct), 1, fp2);
    }

    fclose(fp2);
    fclose(fp);
    return;

//    fclose(fp);
//    remove(nomFichier);
//    fclose(fp2);
//    rename("nomFichier2", nomFichier);
//    return;
}

// lire les données d'un fichier binaire
// et les enregistrer dans un tableau
// retourner le tableau
Exemple_struct* charger_donnees_et_compter_nbLignes(char nomFich[], int* n)
{
    int nbLignes = 0;
    Exemple_struct* tab;
    Exemple_struct strucutre;
    FILE* fp;

    fp = fopen(nomFich, "rb");
    if(fp == NULL)
    {
        printf("\nErreur pendant l'ouverture du fichier: \"%s\"\n", nomFich);
        return NULL;
    }

    while( fread(&strucutre, sizeof(Exemple_struct), 1, fp) )
        nbLignes++;
    rewind(fp);

    *n = nbLignes;
    tab = (Exemple_struct*)malloc((*n) * sizeof(Exemple_struct));

    fread(tab, sizeof(Exemple_struct), *n, fp);

    fclose(fp);
    return tab; // free(tab) in main
}

void sauvegarder_tableau_dans_fich_binaire(char nomFich[], Exemple_struct* tab, int n)
{
    FILE* fp;

    fp = fopen(nomFich, "wb");
    if(fp == NULL)
    {
        printf("\nErreur pendant l'ouverture du fichier: \"%s\"\n", nomFich);
        return;
    }

    if( !(fwrite(tab, sizeof(Exemple_struct), n, fp) == n) )
        printf("\nErreur de sauvegarde.\n");

    fclose(fp);
}
