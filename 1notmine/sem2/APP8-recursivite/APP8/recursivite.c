#include "recursivite.h"

// inverser un tableau d'entier
void inverserRec(int* tabEnt, int n)
{
    if( tabEnt >= tabEnt+n-1 )
        return;

    permuter(tabEnt, tabEnt+n-1);
    inverserRec(tabEnt+1, n-2);
}


void palindromeRec(char* mot, int n)
{
    // si mot est composé d'une seule lettre
    if( n == 1 )
    {
        printf("\nLe mot est palindrome.\n");
        return;
    }

    if( mot >= mot+n-1 )
    {
        printf("\nLe mot est palindrome.\n");
        return;
    }

    if( *mot != *(mot+n-1) )
    {
        printf("\nLe mot n'est pas palindrome.\n");
        return;
    }

    palindromeRec(mot+1, n-2);
}


int pgcdRec(int a, int b)
{
    return (b == 0)? a : pgcdRec(b, a%b);
}


int getLength(char* mot)
{
    int i=0;
    while(mot[i] != '\0')
        i++;

    return i;
}


void permuter(int *x, int *y)
{
    int temp;
    if( x!=y )
    {
        temp = *x;
        *x = *y;
        *y = temp;
    }
}

//////////////////////////////////////
//////////////////////////////////////

void afficher_liste(liste l)
{
    if( !l )
        return;

    printf("\nnom: %s", l->et.nom);
    printf("\nmoyenne: %.2f\n", l->et.moyenne);
    afficher_liste(l->suiv);
}


void afficher_liste_inverse(liste l)
{
    if( !l )
        return;

    afficher_liste_inverse(l->suiv);
    printf("\nnom: %s", l->et.nom);
    printf("\nmoyenne: %.2f\n", l->et.moyenne);
}

liste ajouter_etudiant(liste l, Etudiant E)
{
    if( !l )
        l = newNode(E);
    else
        l->suiv = ajouter_etudiant(l->suiv, E);

    return l;
}

struct cellule* newNode(Etudiant E)
{
    struct cellule* nouv;
    nouv = (struct cellule*)malloc(sizeof(struct cellule));
    nouv->et = E;
    nouv->suiv = NULL;

    return nouv;
}

liste supprimer_etudiant(liste l, char *nom)
{
    if( !l )
    {
        printf("\nAucun Etudiant avec le nom \"%s\"", nom);
        return l;
    }

    if( strcmp( l->et.nom, nom) == 0 )
    {
        struct cellule* temp = l->suiv;
        free(l);
        printf("\nSuppression de l'etudiant/e \"%s\"...\n", nom);
        return temp;
    }

    l->suiv = supprimer_etudiant(l->suiv, nom);

    return l;
}

void freeLC(liste l)
{
    if ( l == NULL )
        return;

    freeLC(l->suiv);
    free(l);
}

//////////////////////////////////////
//////////////////////////////////////

void interclasser(int tab[], int n, int deb, int milieu, int fin)
{
    int n1 = milieu - deb + 1;
    int n2 = fin - milieu;

    int L[n1], R[n2];

    for (int i=0; i<n1; i++)
        L[i] = tab[deb + i];
    for (int j=0; j<n2; j++)
        R[j] = tab[milieu +1 + j];

    int i = 0;
    int j = 0;
    int k = deb;

    while ( i<n1 && j<n2 ) {
        if (L[i] <= R[j]) {
            tab[k] = L[i];
            i++;
        }
        else {
            tab[k] = R[j];
            j++;
        }
        k++;
    }

    while ( i<n1 ) {
        tab[k] = L[i];
        i++;
        k++;
    }

    while ( j<n2 ) {
        tab[k] = R[j];
        j++;
        k++;
    }
}

void TriFusion(int tab[], int n, int deb, int fin)
{
    if( deb >= fin )
        return;

    int m = (fin+deb)/2;
    TriFusion(tab, n, deb, m);
    TriFusion(tab, n, m+1, fin);

    interclasser(tab, n, deb, m, fin);
}

