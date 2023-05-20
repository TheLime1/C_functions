#ifndef FICHIERSTEXTE_H_INCLUDED
#define FICHIERSTEXTE_H_INCLUDED

void enregistrer_dans_fichier_texte(char* nomFichier);

void chercher_chaine_dans_fich_texte(char* nomFichier, char* prenom);

void afficher_tous_avec_NPlus_txt(char* nomFichier, int n);

void afficher_contenu_fichier_texte(char* nomFichier);

void supprimer_element_avec_0_enfants(char* nomFichier);

void copierFichier_Texte(char* nomFichier, char* nomFichier2);

void ajouter_evenement_dans_journal(char* fileName, char* evenement);

void afficherJournal(char* fileName);


#endif // FICHIERSTEXTE_H_INCLUDED
