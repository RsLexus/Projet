#ifndef ACTIONS_H_INCLUDED
#define ACTIONS_H_INCLUDED
#include "donnees.h"

void AfficherOrdreCSV (Battements *tab, int y); // Prototype.
void AfficherOrdreCroiTemps(Battements *tab, int y); // Prototype.
void AfficherOrdreCroiPouls(Battements *tab, int y); // Prototype.
void AfficherOrdreDecroiTemps(Battements *tab, int y); // Prototype.
void AfficherOrdreDecroiPouls(); // Prototype.
void RechercheDonnees (); // Prototype.
void AffichageMoyenne (); // Prototype.
void AffichageLigneMemoire (int y); // Prototype.
void AffichageMaxPouls (); // Prototype.
void AffichageMinPouls (); // Prototype.

#endif
