#ifndef GATEAU_H
#define GATEAU_H

typedef struct
{
    int type;
    int nbr_ing;
    float prix;
} gateau;

void saisir_gateau(gateau *g);
void ajouter_gateau_ft(gateau g, char nom_fich[]);
int nbre_gateaux_ft(char nom_fich[]);
void afficher_gateau(char nom_fich[], int num);

#endif
