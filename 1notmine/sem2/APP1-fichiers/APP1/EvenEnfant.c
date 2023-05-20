#include "EvenEnfant.h"
#include <errno.h>
#include <stdio.h>
#include <string.h>

int enregistrerInfo(char* nomFichier)
{
    FILE* fp;
    int nbEmployes;
    employe emp;

    fp = fopen(nomFichier, "w+"); //w+, ligne 36 affichage du contenu du fichier pour verifier... sinon w

    if(fp == NULL)
    {
        printf("Erreur pendant la creation du nomFichier: %d\n", errno);
        return 1;
    }

    printf("Donner le nombre des employes: ");
    scanf("%d", &nbEmployes);
    printf("\n");

    for(int i=0; i<nbEmployes; i++)
    {
        printf("Donner le nom de l employe #%d: ", i+1);
        scanf("%s", emp.nom);
        printf("Donner le prenom de l employe #%d: ", i+1);
        scanf("%s", emp.prenom);
        printf("Donner le nombre d enfants de l employe #%d: ", i+1);
        scanf("%d", &emp.nbEnfant);
        printf("\n");
        fprintf(fp, "%s %s %d\n", emp.nom, emp.prenom, emp.nbEnfant);
    }

    // afficher le contenu du fichier pour verifier
    rewind(fp);
    printf("Contenu du fichier \"%s\": \n", nomFichier);
    while(fscanf(fp, "%s %s %d\n", emp.nom, emp.prenom, &emp.nbEnfant) != EOF)
        printf("%s %s %d\n", emp.nom, emp.prenom, emp.nbEnfant);

    fclose(fp);
    return 0;
}


void chercherEmploye(char* nomFichier, char* prenom)
{
    FILE* fp;
    employe emp;
    int nbLigne = 0;
    int existe = 0;

    fp = fopen(nomFichier, "r");

    if(fp == NULL)
    {
        printf("Erreur pendant l ouverture du nomFichier: %d\n", errno);
        return;
    }

    while( fscanf(fp, "%s %s %d\n", emp.nom, emp.prenom, &emp.nbEnfant) != EOF )
    {
        nbLigne++;
        if( strcmp(emp.prenom, prenom) == 0 )
        {
            printf("Un employe avec le prenom \"%s\" est inscrit dans la ligne %d\n", prenom, nbLigne);
            existe = 1;
        }
    }
    if( existe == 0 )
        printf("aucun employe avec le prenom \"%s\" n est inscrit dans le fichier %s", prenom, nomFichier);

    fclose(fp);
}


void afficherEmployeNPlus(char* nomFichier, int n)
{
    FILE* fp;
    employe emp;
    int nbLigne = 0;

    fp = fopen(nomFichier, "r");

    if(fp == NULL)
    {
        printf("Erreur pendant l ouverture du nomFichier: %d\n", errno);
        return;
    }

    while( fscanf(fp, "%s %s %d\n", emp.nom, emp.prenom, &emp.nbEnfant) != EOF )
    {
        nbLigne++;
        if(emp.nbEnfant >= n)
            printf("L employe dans la ligne %d a %d enfants\n", nbLigne, emp.nbEnfant);
    }

    fclose(fp);
}

void supprimerEmploye0enfants(char* nomFichier)
{
    FILE* fp;
    employe emp;
    int nbLigne = 0;
    int i = 0;
    int LignesASupprimer[10] = {[0 ... 9] = -1};

    fp = fopen(nomFichier, "r");

    if(fp == NULL)
    {
        printf("Erreur pendant l ouverture du nomFichier: %d\n", errno);
        return;
    }

    while( fscanf(fp, "%s %s %d\n", emp.nom, emp.prenom, &emp.nbEnfant) != EOF )
    {
        if(emp.nbEnfant == 0)
        {
            LignesASupprimer[i] = nbLigne;
            i++;
        }
        nbLigne++;
    }
    fclose(fp);

    copierFichier(nomFichier, "NvnomFichier.txt", LignesASupprimer);
    remove(nomFichier);
    rename("NvnomFichier.txt", nomFichier);
}

int copierFichier(char* nomFichier, char* nomFichier2, int* LignesASupprimer)
{
    FILE *fp, *fp2;
    employe emp;
    int nbLigne = 0;

    fp = fopen(nomFichier, "r");
    fp2 = fopen(nomFichier2, "w");

    if(fp == NULL || fp2 == NULL)
    {
        printf("Erreur: %d\n", errno);
        return 1;
    }

    while( fscanf(fp, "%s %s %d\n", emp.nom, emp.prenom, &emp.nbEnfant) != EOF )
    {
        for(int i=0; i<10; i++)
            if(LignesASupprimer[i] == nbLigne)
                goto fromhere;

        fprintf(fp2, "%s %s %d\n", emp.nom, emp.prenom, emp.nbEnfant);
        fromhere:;
        nbLigne++;
    }

    fclose(fp2);
    fclose(fp);
    return 0;
}

///////////////////////////////////////
////////////   binaire   //////////////
///////////////////////////////////////

int enregistrerInfoBIN(char* nomFichier)
{
    FILE* fp;
    int nbEmployes;
    employe emp;

    fp = fopen(nomFichier, "wb+"); //wb+, ligne 199 affichage du contenu du fichier pour verifier... sinon wb

    if(fp == NULL)
    {
        printf("Erreur pendant la creation du nomFichier: %d\n", errno);
        return 1;
    }

    printf("Donner le nombre des employes: ");
    scanf("%d", &nbEmployes);
    printf("\n");

    for(int i=0; i<nbEmployes; i++)
    {
        printf("Donner le nom de l employe #%d: ", i+1);
        scanf("%s", emp.nom);
        printf("Donner le prenom de l employe #%d: ", i+1);
        scanf("%s", emp.prenom);
        printf("Donner le nombre d enfants de l employe #%d: ", i+1);
        scanf("%d", &emp.nbEnfant);
        printf("\n");
        fwrite(&emp, sizeof(employe), 1, fp);
    }

    // afficher le contenu du fichier pour verifier
    rewind(fp);
    printf("Contenu du fichier \"%s\" (texte): \n", nomFichier);
    while( fread(&emp, sizeof(employe), 1, fp) )
        printf("%s %s %d\n", emp.nom, emp.prenom, emp.nbEnfant);
    printf("\n");

    fclose(fp);
    return 0;
}


void chercherEmployeBIN(char* nomFichier, char* prenom)
{
    FILE* fp;
    employe emp;
    int nbLigne = 0;
    int existe = 0;

    fp = fopen(nomFichier, "rb");

    if(fp == NULL)
    {
        printf("Erreur pendant l ouverture du nomFichier: %d\n", errno);
        return;
    }

    while( fread(&emp, sizeof(employe), 1, fp) )
    {

        nbLigne++;
        if( strcmp(emp.prenom, prenom) == 0 )
        {
            printf("Un employe avec le prenom \"%s\" est inscrit dans la ligne %d\n", prenom, nbLigne);
            existe = 1;
        }
    }
    if( existe == 0 )
        printf("aucun employe avec le prenom \"%s\" n est inscrit dans le fichier %s", prenom, nomFichier);

    fclose(fp);
}

void afficherEmployeNPlusBIN(char* nomFichier, int n)
{
    FILE* fp;
    employe emp;
    int nbLigne = 0;

    fp = fopen(nomFichier, "rb");

    if(fp == NULL)
    {
        printf("Erreur pendant l ouverture du nomFichier: %d\n", errno);
        return;
    }

    while( fread(&emp, sizeof(employe), 1, fp) )
    {
        nbLigne++;
        if(emp.nbEnfant >= n)
            printf("L employe dans la ligne %d a %d enfants\n", nbLigne, emp.nbEnfant);
    }

    fclose(fp);
}

void supprimerEmploye0enfantsBIN(char* nomFichier)
{
    FILE* fp;
    employe emp;
    int nbLigne = 0;
    int i = 0;
    int LignesASupprimer[10] = {[0 ... 9] = -1};

    fp = fopen(nomFichier, "rb");

    if(fp == NULL)
    {
        printf("Erreur pendant l ouverture du nomFichier: %d\n", errno);
        return;
    }

    while( fread(&emp, sizeof(employe), 1, fp) )
    {
        if(emp.nbEnfant == 0)
        {
            LignesASupprimer[i] = nbLigne;
            i++;
        }
        nbLigne++;
    }
    fclose(fp);

    copierFichierBIN(nomFichier, "NvnomFichier.bin", LignesASupprimer);
    remove(nomFichier);
    rename("NvnomFichier.bin", nomFichier);
}

int copierFichierBIN(char* nomFichier, char* nomFichier2, int* LignesASupprimer)
{
    FILE *fp, *fp2;
    employe emp;
    int nbLigne = 0;

    fp = fopen(nomFichier, "rb");
    fp2 = fopen(nomFichier2, "wb");

    if(fp == NULL || fp2 == NULL)
    {
        printf("Erreur: %d\n", errno);
        return 1;
    }

    while( fread(&emp, sizeof(employe), 1, fp) )
    {
        for(int i=0; i<10; i++)
            if(LignesASupprimer[i] == nbLigne)
                goto fromhere;

        fwrite(&emp, sizeof(emp), 1, fp2);
        fromhere:;
        nbLigne++;
    }

    fclose(fp2);
    fclose(fp);
    return 0;
}
