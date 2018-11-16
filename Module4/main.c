#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "donnees.h"
#include "actions.h"
#include "menu.h"

int main()
{
    Battements tab[MAX_LIGNES]; // On d�finit ici un tableau de structure permettant de stocker les informations de notre fichier .csv.
    int y = LectureFichier(tab); // On effectue la fonction LectureFichier et y prends la valeur renvoy� par cette fonction (le nombre de ligne de notre tableau).
    int a = AffichageMenu(); // On effectue la fonction AffichageMenu et a prend la valeur de cette fonction c'est � dire le chiffre rentr�e par l'utilisateur.
    while (a != 0) // Tant que la valeur retourn� par la fonction AffichageMenu est diff�rent de 0...
    {
        nbrchoisi(a, tab, y); //...on effectue notre fonction nbrchoisi c'est � dire nos diff�rents cas selon la demande de l'utilisateur.
        a = AffichageMenu(); // On effectue encore la fonction AffichageMenu pour laisser le choix � l'utilisateur d'effectuer une autre t�che.
    }
    printf("Vous sortez du programme.\n"); // Si l'utilisateur rentre la valeur 0 on sort de la boucle while et on quitte le programme.
    return 0;
}
