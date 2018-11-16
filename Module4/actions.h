#ifndef ACTIONS_H_INCLUDED
#define ACTIONS_H_INCLUDED
#include "donnees.h"

void AfficherOrdreCSV (Battements *tab, int y); // Prototype.
void AfficherOrdreCroiTemps(Battements *tab, int y); // Prototype.
void AfficherOrdreCroiPouls(Battements *tab, int y); // Prototype.
void AfficherOrdreDecroiTemps(Battements *tab, int y); // Prototype.
void AfficherOrdreDecroiPouls(Battements *tab, int y); // Prototype.
void RechercheDonnees (Battements *tab, int y); // Prototype.
void AffichageMoyenne (Battements *tab, int y); // Prototype.
void AffichageLigneMemoire (int y); // Prototype.
void AffichageMaxPouls (Battements *tab, int y); // Prototype.
void AffichageMinPouls (Battements *tab, int y); // Prototype.
void TriInsertion(Battements *tab, int y); // Prototype.

#endif
