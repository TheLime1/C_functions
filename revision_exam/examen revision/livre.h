#ifndef LIVRE_H_INCLUDED
#define LIVRE_H_INCLUDED
typedef struct
{
    int code;
    int nb_exemp;
}Livre;
typedef struct
{
    int numero;
    int code_livre;
    char id_abonne[20];
    int etat;
}Emprunt;
Emprunt p_emprunt;
void saisir_livre(Livre* p_livre);
void chercher_livre(Livre t_livres[], int nl, int code_l, int* pos);
void ajouter_livre(Livre t_livres[], int* nl,Livre p_livre) ;
void afficher_livres(Livre t_livres[], int nl) ;
void saisir_emprunt(Emprunt* p_emprunt);
void ajouter_emprunt(Emprunt t_emprunts[], int* ne, Livre t_livres[], int nl);
void chercher_emprunt(int num, Emprunt t_emprunts[], int ne, int* pos) ;
void retourner_emprunt(int num, Emprunt t_emprunts[], int ne, Livre t_livres[],  int nl);
void afficher_emprunts_retournes(Emprunt t_emprunts[], int ne);

#endif // LIVRE_H_INCLUDED
