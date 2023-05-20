#include "fichiersTexte.h"
#include "general.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void enregistrer_dans_fichier_texte(char* nomFichier)
{
    FILE* fp;
    int nbEmployes;
    Exemple_struct strucutre;

    fp = fopen(nomFichier, "w"); //a, w, r, w+, r+, a+
    if(fp == NULL)
    {
        printf("\nErreur pendant la creation du fichier: \"%s\"\n", nomFichier);
        return;
    }

    printf("Donner le nombre des employes: ");
    scanf("%d", &nbEmployes);
    printf("\n");

    for(int i=0; i<nbEmployes; i++)
    {
        printf("Donner le nom de l employe #%d: ", i+1);
        scanf("%s", strucutre.nom);
        printf("Donner float_num #%d: ", i+1);
        scanf("%f", &strucutre.float_num);
        printf("Donner int_num #%d: ", i+1);
        scanf("%d", &strucutre.int_num);
        printf("\n");
        fprintf(fp, "%s %d %f\n", strucutre.nom, strucutre.int_num, strucutre.float_num);
    }

    fclose(fp);
}


void chercher_chaine_dans_fich_texte(char* nomFichier, char* nom)
{
    FILE* fp;
    Exemple_struct strucutre;
    int nbLigne = 0;

    fp = fopen(nomFichier, "r");

    if(fp == NULL)
    {
        printf("\nErreur lors de l'ouverture du fichier \"%s\"\n", nomFichier);
        return;
    }

    while( fscanf(fp, "%s %d %f\n", strucutre.nom, &strucutre.int_num, &strucutre.float_num) != EOF )
    {
        nbLigne++;
        if( strcmp(strucutre.nom, nom) == 0 )
        {
            printf("\nUn employe avec le prenom \"%s\" est inscrit dans la ligne %d\n", nom, nbLigne);
            return;
        }
    }

    printf("\nAucun employe avec le prenom \"%s\" n'est inscrit dans le fichier %s", nom, nomFichier);

    fclose(fp);
}

void afficher_tous_avec_NPlus_txt(char* nomFichier, int n)
{
    FILE* fp;
    Exemple_struct strucutre;
    int nbLigne = 0;

    fp = fopen(nomFichier, "r");

    if(fp == NULL)
    {
        printf("\nErreur lors de l'ouverture du fichier \"%s\"\n", nomFichier);
        return;
    }

    while( fscanf(fp, "%s %d %f\n", strucutre.nom, &strucutre.int_num, &strucutre.float_num) != EOF )
    {
        nbLigne++;
        if(strucutre.int_num >= n)
            printf("\nL'employe dans la ligne %d a %d enfants\n", nbLigne, strucutre.int_num);
    }

    fclose(fp);
}

void supprimer_element_avec_0_enfants(char* nomFichier)
{
    Exemple_struct strucutre;
    FILE *fp, *fp2;
    fp = fopen(nomFichier, "r");
    fp2 = fopen("temp.txt", "w");

    if( fp == NULL || fp2 == NULL )
    {
        printf("\nErreur pendant l'ouverture des fichiers\n");
        return;
    }

    while( (fscanf(fp, "%s %d %f\n", strucutre.nom, &strucutre.int_num, &strucutre.float_num) != EOF) )
    {
        if(strucutre.int_num != 0)
            fprintf(fp2, "%s %d %f\n", strucutre.nom, strucutre.int_num, strucutre.float_num);
    }

    fclose(fp);
    remove(nomFichier);
    fclose(fp2);
    rename("temp.txt", nomFichier);
}

void afficher_contenu_fichier_texte(char* nomFichier)
{
    FILE* fp;
    Exemple_struct strucutre;

    fp = fopen(nomFichier, "r"); //a, w, r, w+, r+, a+
    if(fp == NULL)
    {
        printf("\nErreur pendant l'ouverture du fichier: \"%s\"\n", nomFichier);
        return;
    }

    if( fscanf(fp, "%s %d %f\n", strucutre.nom, &strucutre.int_num, &strucutre.float_num) == EOF )
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
        while( fscanf(fp, "%s %d %f\n", strucutre.nom, &strucutre.int_num, &strucutre.float_num) != EOF )
        {
            printf("%s %d %f\n", strucutre.nom, strucutre.int_num, strucutre.float_num);
        }
    }

    fclose(fp);
}

void copierFichier_Texte(char* nomFichier, char* nomFichier2)
{
    FILE *fp, *fp2;
    Exemple_struct strucutre;

    fp = fopen(nomFichier, "r");
    fp2 = fopen(nomFichier2, "w");

    if(fp == NULL || fp2 == NULL)
    {
        printf("Erreur pendant l'ouverture des fichiers\n");
        return;
    }

    while( fscanf(fp, "%s %d %f\n", strucutre.nom, &strucutre.int_num, &strucutre.float_num) != EOF )
    {
        fprintf(fp2, "%s %d %f\n", strucutre.nom, strucutre.int_num, strucutre.float_num);
    }

    fclose(fp2);
    fclose(fp);
    return;

//    fclose(fp);
//    remove(nomFichier);
//    fclose(fp2);
//    rename(nomFichier2, nomFichier);
//    return;
}

void ajouter_evenement_dans_journal(char* fileName, char* evenement)
{
    FILE* fp;
    fp = fopen(fileName, "a");

    if( fp == NULL )
    {
        printf("\nErreur pendant l'ouverture du fichier: \"%s\"\n", fileName);
        return;
    }

    fprintf(fp, "%s\n", evenement);
    fclose(fp);
}

void afficherJournal(char* fileName)
{
    FILE* fp;
    int c;

    fp = fopen(fileName, "r");
    if( fp == NULL )
    {
        printf("\nErreur pendant l'ouverture du fichier: \"%s\"\n", fileName);
        return;
    }

    c = fgetc(fp);
    while ( c != EOF )
    {
        printf("%c", c);
        c = fgetc(fp);
    }

    fclose(fp);
}
