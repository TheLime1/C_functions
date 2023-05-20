#include "general.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Exemple_struct saisir()
{
    Exemple_struct ES;

    printf("float_num: ");
    scanf("%f", &ES.float_num);
    printf("int_num: ");
    scanf("%d", &ES.int_num);
    printf("nom: ");
    fflush(stdin);
    gets(ES.nom);
    //scanf("%s", ES.nom);

//    verifier s'il y a des conditions sur la saisie
//    (unicité, dans un intervalle...)
//    do
//    {
//        printf("int_num: ");
//        scanf("%d", &ES.int_num);
//    }
//    while( ES.int_num != 1 && ES.int_num != 2 );
//    while( chercher_Element(LDC, element) || num < 1 );

    return ES;
}

void saisirVoid(Exemple_struct* ES)
{
    printf("\nfloat_num: ");
    scanf("%f", &ES->float_num);
    printf("int_num: ");
    scanf("%d", &ES->int_num);
    printf("nom: ");
    fflush(stdin);
    gets(ES->nom);
    // scanf("%s", ES->nom);
    // verifier s'il y a des conditions sur la saisie
}

void afficherStructure(Exemple_struct structure, int i)
{
    printf("\nInfo structure#%d:\n", i);
    printf("\tstructure.nom: %s\n", structure.nom);
    printf("\tstructure.int_num: %d\n", structure.int_num);
    printf("\tstructure.float_num: %2.f\n", structure.float_num);
}


void afficher_tableau(Exemple_struct* tab, int n)
{
    if(n == 0)
    {
        printf("Le tableau Vgr[] est vide.\n");
    }
    else
    {
        printf("Tableau:\n");
        for(int i=0; i<n; i++)
        {
            printf("Voyageur[%d]:\n", i);
            printf("\tvoyageur[%d].ID: %s\n", i, (tab+i)->nom);
            printf("\tvoyageur[%d].nom: %d\n", i, (tab+i)->int_num);
            printf("\tvoyageur[%d].adresse: %.2f\n", i, (tab+i)->float_num);
            printf("\n");
        }
    }
}


int chercher_chaine_dans_tableau(Exemple_struct* tab, char id[], int n)
{
    for(int i=0; i<n; i++)
        if( strcmp( (tab+i)->nom, id ) == 0 )
            return i;

    return -1;
}


void printArray(int* arr, int n)
{
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
