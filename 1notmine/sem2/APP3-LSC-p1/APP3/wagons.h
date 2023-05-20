#ifndef WAGONS_H_INCLUDED
#define WAGONS_H_INCLUDED

enum wagonInfo{typeLocomotive, EnPanne=0};

typedef struct
{
    int num;
    int type;   // locomotive ou wagon
    int etat;   // en panne ou ok
} Wagon;

struct Cellule
{
    Wagon wagon;
    struct Cellule* suivant;
};
typedef struct Cellule* Train;

Train ajouterLocomotive(Train train, Wagon locomotive);
Train ajouterFin(Train tain, Wagon wagon);
int rechercherWagon(Train train, int num);
void afficherTrain(Train train, int* nbWagons);

// Helper functions
Wagon saisirWagon(Wagon wagon);
void afficherWagon(Wagon wagon, int i);


#endif // WAGONS_H_INCLUDED
