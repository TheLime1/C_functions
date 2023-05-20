#include "even.h"
#include <stdio.h>
#include <string.h>

employe saisirEmp()
{
    employe e;
    printf("nom: ");
    scanf("%s", e.nom);
    printf("prenom: ");
    scanf("%s", e.prenom);
    printf("nbEnfants: ");
    scanf("%d", &(e.nbEnfants));

    return e;
}

void enregistrer(char* nomFichier, employe* employes, int n)
{
    int i = 0;
    FILE* fp;
    fp = fopen(nomFichier, "a");

    if(!fp)
    {
        printf("Erreur\n");
        return;
    }

    while(i!=n)
    {
        fprintf(fp, "%s %s %d\n", (employes+i)->nom, (employes+i)->prenom, (employes+i)->nbEnfants);
        i++;
    }

    fclose(fp);
}

void chercher(char* nomFichier, char* prenom)
{
    employe e;
    FILE *fp;
    fp = fopen(nomFichier, "r");

    while( (fscanf(fp, "%s %s %d\n", e.nom, e.prenom, &e.nbEnfants) != EOF )
            && (strcmp(e.prenom, prenom) != 0) );

    printf("Employe %s", (strcmp(e.prenom, prenom) == 0) ? "trouve" : "non trouvable" );

    fclose(fp);
}

void afficherNPlus(char* nomFichier, int n)
{
    employe e;
    FILE *fp;
    fp = fopen(nomFichier, "r");

    while( (fscanf(fp, "%s %s %d\n", e.nom, e.prenom, &e.nbEnfants) != EOF) )
    {
        if(e.nbEnfants >= n)
        {
            printf("%s\n", e.nom);
        }
    }

    fclose(fp);
}

void supprimer(char* nomFichier)
{
    employe e;
    FILE *fp, *fp2;
    fp = fopen(nomFichier, "r");
    fp2 = fopen("test.txt", "w");

    while( (fscanf(fp, "%s %s %d\n", e.nom, e.prenom, &e.nbEnfants) != EOF) )
    {
        if(e.nbEnfants != 0)
        {
            fprintf(fp2, "%s %s %d\n", e.nom, e.prenom, e.nbEnfants);
        }
    }
    fclose(fp);
    remove(nomFichier);
    fclose(fp2);
    rename("test.txt", nomFichier);
}

// partie 2
void binEnregsitrer(char* binNomFichier, employe* emp, int n)
{
    int i = 0;
    FILE *fp = NULL;
    fp = fopen(binNomFichier, "wb");

    if(!fp)
    {
        printf("erreur ouverture du fichier binaire\n");
        return;
    }

    fwrite(emp+i, sizeof(employe), n, fp);

    fclose(fp);
}

void binChercher(char* binNomFichier, char* prenom)
{
    FILE *fp = NULL;
    employe emp;
    strcpy(emp.prenom, "");
    fp = fopen(binNomFichier, "rb");

    if(!fp)
    {
        printf("erreur ouverture du fichier binaire2\n");
        return;
    }

    while( fread(&emp, sizeof(employe), 1, fp) && strcmp(emp.prenom, prenom));

    printf("%s", !strcmp(emp.prenom, prenom) ? "employe trouve" : "employe introuvable...");

    fclose(fp);
}



void binAfficherNPlus(char* binNomFichier, int n);
void binSupprimer(char* binNomfichier);
