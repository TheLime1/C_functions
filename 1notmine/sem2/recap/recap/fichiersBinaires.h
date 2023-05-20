#ifndef FICHIERSBINAIRES_H_INCLUDED
#define FICHIERSBINAIRES_H_INCLUDED
#include "general.h"

void enregistrer_dans_fichier_binaire(char* nomFichier);

void chercher_chaine_dans_fich_binaire(char* nomFichier, char* prenom);

void afficher_contenu_fichier_binaire(char* nomFichier);

int nbLignes(char nomFichier[]);

void afficher_tous_avec_NPlus_bin(char* nomFichier, int n);

void supprimer_element_avec_0_enfants_bin(char* nomFichier);

void copierFichierBIN(char* nomFichier, char* nomFichier2);

Exemple_struct* charger_donnees_et_compter_nbLignes(char nomFich[], int* n);

void sauvegarder_tableau_dans_fich_binaire(char nomFich[], Exemple_struct* tab, int n);

#endif // FICHIERSBINAIRES_H_INCLUDED
