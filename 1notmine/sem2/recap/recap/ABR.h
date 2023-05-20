#ifndef ABR_H_INCLUDED
#define ABR_H_INCLUDED

typedef struct etudiant Etudiant;
typedef struct noeud* abr;
typedef struct listeDC LDC;

struct etudiant
{
    int id;
    char nom[10];
    char prenom[10];
    int niveau;     // 1->5
    float moyenne;
};

struct noeud
{
    Etudiant e;
    struct noeud* pL;
    struct noeud* pR;
};

struct listeDC
{
    struct noeud* tete;
    struct noeud* queu;
};

abr initialiser_Etudiant(Etudiant e);
abr inserer(abr a, Etudiant e);
abr construireArbre(abr a, char nomFich[]);
void afficher(abr a);
int calculerNombre(abr a);
void construireListe(abr a, LDC *l, float BI, float BS);

//LDC
LDC init_LDC();
int listeDC_vide(LDC L);
LDC ajouter_fin(LDC L, Etudiant e);
struct noeud* ajouter_fin_Rec(struct noeud* pNode, Etudiant e);
LDC supp_tete_LDC2(LDC L);
void afficher_LDC_Rec(struct noeud* node);

void freeDLL_Rec(struct noeud* pNode);
LDC freeDLL(LDC L);
void freeABR_Rec(abr a);

#endif // ABR_H_INCLUDED
