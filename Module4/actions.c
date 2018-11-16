#include "actions.h"
#include "donnees.h"
#include <stdio.h>


void AfficherOrdreCSV (Battements *tab, int y) // Fonction permettant d'afficher les données du tableau dans l'ordre d'entrée.
{
    int i;
    for (i = 0; i < y; i++) // On recommence cette boucle jusqu'a ce que "i" atteigne la valeur de notre nombre de lignes en mémoire
    {                       // (on augmente la valeur de "i" de 1 à chaque boucle)
        printf("Temps: %.2lf; Pouls: %d\n", tab[i].temps, tab[i].pouls); // A chaque boucle on affiche
    }
}


void AfficherOrdreCroiTemps (Battements *tab, int y)
{
    int i;
    for (i = 0; i < y; i++)
    {
        printf("%d;%.2lf\n", tab[i].pouls, tab[i].temps);
    }
}

void AfficherOrdreCroiPouls (Battements *tab, int y)
{

}

void AfficherOrdreDecroiTemps (Battements *tab, int y)
{
    int i,j=0;
    Battements reversedTab[MAX_LIGNES];

    for (i = y-1; i > 0; i--)
    {
        reversedTab[j].temps = tab[i].temps;
        reversedTab[j].pouls = tab[i].pouls;
        j++;
    }
    for (i = 0; i < y-1; i++)
    {
        printf("Temps: %.2lf; Pouls: %d\n", reversedTab[i].temps, reversedTab[i].pouls);
    }
}

void AfficherOrdreDecroiPouls ()
{

}

void RechercheDonnees ()
{

}

void AffichageMoyenne ()
{

}

void AffichageLigneMemoire (int y)
{
 printf("Votre nombre de lignes en memoire est de %d%\n", y);
}

void AffichageMaxPouls ()
{


}

void AffichageMinPouls()
{

}
