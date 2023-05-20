#include "alloc_dyn.h"
#include "fichiersBinaires.h"
#include <stdio.h>
#include <stdlib.h>

Exemple_struct* ajouter_elem_tableau(Exemple_struct v, Exemple_struct* tab, int* n)
{
    int index = -2;
    if( (index = chercher_chaine_dans_tableau(tab, v.nom, *n)) != -1 )
    {
        ((tab+index)->int_num)++;
    }
    else
    {
        tab = (Exemple_struct*)realloc(tab, ((*n)+1)*sizeof(Exemple_struct));
        *(tab + *n) = v;
        (*n)++;
    }

    return tab;
}


void supprimer_elem_tableau(Exemple_struct* tab ,char id[], int* n)
{
    int index = -2;
    Exemple_struct* temp = NULL;

    if( (index = chercher_chaine_dans_tableau(tab, id, *n)) == -1 )
    {
        printf("\nLe voyageur n existe pas dans tab\n");
    }
    else
    {
        (*n)--;
        for(int i=index; i<(*n); i++)
            *(tab+i) = *((tab+i)+1);

        printf("\nVoyageur supprime de tabVgr[%d]\n", index);

        temp = realloc(tab, (*n)*sizeof(Exemple_struct));
        if(temp == NULL && (*n)>1)
        {
            printf("Erreur de reallocation\n");
            return;
        }
        tab = temp;
    }
}

void liberer_tableau(Exemple_struct* tab)
{
    if(tab == NULL)
    {
        printf("NULL pointer.\n");
    }
    free(tab);
}


/*

// dynamic allocation of a 2D Array
int nrows = 2;
int ncols = 5;
int i, j;

// Allocate memory for nrows pointers
char **pvowels = (char **) malloc(nrows * sizeof(char *));

// For each row, allocate memory for ncols elements
pvowels[0] = (char *) malloc(ncols * sizeof(char));
pvowels[1] = (char *) malloc(ncols * sizeof(char));

pvowels[0][0] = 'A';
pvowels[0][1] = 'E';
pvowels[0][2] = 'I';
pvowels[0][3] = 'O';
pvowels[0][4] = 'U';

pvowels[1][0] = 'a';
pvowels[1][1] = 'e';
pvowels[1][2] = 'i';
pvowels[1][3] = 'o';
pvowels[1][4] = 'u';

for (i = 0; i < nrows; i++) {
    for(j = 0; j < ncols; j++) {
        printf("%c ", pvowels[i][j]);
    }

    printf("\n");
}

// Free individual rows
free(pvowels[0]);
free(pvowels[1]);

// Free the top-level pointer
free(pvowels);

// or for all raw in a loop then
// free the top level pointer
for (int i=0; i<nrows; i++) {
    free(pvowels[i]);
}
free(pvowels);

*/
