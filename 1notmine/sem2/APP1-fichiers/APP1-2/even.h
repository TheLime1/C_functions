#ifndef EVEN_H_INCLUDED
#define EVEN_H_INCLUDED

typedef struct
{
    char nom[10];
    char prenom[10];
    int nbEnfants;
} employe;

employe saisirEmp();
void enregistrer(char* nomFichier, employe* employes, int n);
void chercher(char* nomFichier, char* prenom);
void afficherNPlus(char* nomFichier, int n);
void supprimer(char* nomFichier);

void binEnregsitrer(char* binNomFichier, employe* emp, int n);
void binChercher(char* binNomFichier, char* prenom);
void binAfficherNPlus(char* binNomFichier, int n);
void binSupprimer(char* binNomfichier);


#endif // EVEN_H_INCLUDED
