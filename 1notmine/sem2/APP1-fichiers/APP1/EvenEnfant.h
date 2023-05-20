#ifndef EVENENFANT_H_INCLUDED
#define EVENENFANT_H_INCLUDED

typedef struct
{
    char nom[20];
    char prenom[20];
    int nbEnfant;
} employe;

int enregistrerInfo(char* fichier);
void chercherEmploye(char* fichier, char* prenom);
void afficherEmployeNPlus(char* fichier, int n);
void supprimerEmploye0enfants(char* fichier);
int copierFichier(char* fichier, char* fichier2, int LignesASupprimer[]);

int enregistrerInfoBIN(char* fichier);
void chercherEmployeBIN(char* fichier, char* prenom);
void afficherEmployeNPlusBIN(char* nomFichier, int n);
void supprimerEmploye0enfantsBIN(char* nomFichier);
int copierFichierBIN(char* nomFichier, char* nomFichier2, int* LignesASupprimer);



#endif // EVENENFANT_H_INCLUDED
