#ifndef DONNEES_H_INCLUDED
#define DONNEES_H_INCLUDED

#define MAX_LIGNES 60000

typedef struct  // Cr�ation d'une structure ad�quate pour lire notre fichier .csv.
{
    double temps;
    int pouls;
}Battements;

int LectureFichier (Battements *tab); // Prototype.
#endif

