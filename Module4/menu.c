#include "menu.h"
#include "actions.h"
#include "donnees.h"
#include <stdio.h>

int a;  // D�claration des variables.

int AffichageMenu() // Fonction permettant d'afficher un menu dans la console.
{
    int a;
    printf("Bienvenue dans le menu, rentrez 1 pour continuer ou 0 pour quittez le programme.\n"); // Affichage d'une phrase sur la console.
    scanf("%d", &a); //On demande � l'utilisateur de rentrer une valeur et on la stocke � l'adresse de la variable "a".
    if (a == 1) // D�but de la boucle conditionnelle "si", si la valeur rentr�e est 1 alors on effectue ce qu'il se trouve entre les accolades.
    {
        printf("[1] Afficher les donnees dans l'ordre du fichier.csv.\n"); // Affichage d'une phrase sur la console.
        printf("[2] Afficher les donnees en ordre croissant en fonction du temps.\n"); // Affichage d'une phrase sur la console.
        printf("[3] Afficher les donnees en ordre croissant en fonction du pouls.\n"); // Affichage d'une phrase sur la console.
        printf("[4] Afficher les donnees en ordre decroissant en fonction du temps.\n"); // Affichage d'une phrase sur la console.
        printf("[5] Afficher les donnees en ordre decroissant en fonction du pouls.\n"); // Affichage d'une phrase sur la console.
        printf("[6] Afficher les donnees pour un temps particulier.\n"); // Affichage d'une phrase sur la console.
        printf("[7] Afficher la moyenne de pouls dans une plage de temps donnee.\n"); // Affichage d'une phrase sur la console.
        printf("[8] Afficher le nombre de lignes de donnees actuellement en memoire.\n"); // Affichage d'une phrase sur la console.
        printf("[9] Afficher le maximum de pouls.\n"); // Affichage d'une phrase sur la console.
        printf("[10] Afficher le minimum de pouls.\n"); // Affichage d'une phrase sur la console.
        printf("[0] Quitter l'application.\n"); // Affichage d'une phrase sur la console.
        printf("\n");
        scanf("%d", &a); // On demande � l'utilisateur de rentrer une valeur que l'on stocke � l'adresse de la variable "a".
        printf("\n"); // Retour � la ligne pour a�rer la console.
    }
    while (a<0 || a>10) // Tant que la valeur ne fait pas partie d'une de celles propos�e on demandera a l'utilisateur de rentrer une valeur correcte.
    {
        printf("Cette option n'existe pas, rentrez une valeur existante.\n");
        scanf("%d", &a);
    }
    return a; // On retourne la valeur de "a".
}

    void nbrchoisi(int a, Battements *tab, int y) // Fonction qui effectue les diff�rents cas en fonction de ce que l'utilisateur avait rentr� comme chiffre.
    {
        switch (a)
        {
            case 1: // Si la valeur rentr�e est 1 alors...
            AfficherOrdreCSV(tab, y); // ...on ex�cute cette fonction situ�e dans action.c/h.
            break;
            case 2:  // Si la valeur rentr�e est 2 alors...
            AfficherOrdreCroiTemps(tab, y); // ...on ex�cute cette fonction situ�e dans action.c/h.
            break;
            case 3: // Si la valeur rentr�e est 3 alors...
            AfficherOrdreCroiPouls(tab, y); // ...on ex�cute cette fonction situ�e dans action.c/h.
            break;
            case 4: // Si la valeur rentr�e est 4 alors...
            AfficherOrdreDecroiTemps(tab, y); // ...on ex�cute cette fonction situ�e dans action.c/h.
            break;
            case 5: // Si la valeur rentr�e est 5 alors...
            AfficherOrdreDecroiPouls(tab, y); // ...on ex�cute cette fonction situ�e dans action.c/h.
            break;
            case 6: // Si la valeur rentr�e est 6 alors...
            RechercheDonnees(tab, y); // ...on ex�cute cette fonction situ�e dans action.c/h.
            break;
            case 7: // Si la valeur rentr�e est 7 alors...
            AffichageMoyenne(tab, y); // ...on ex�cute cette fonction situ�e dans action.c/h.
            break;
            case 8: // Si la valeur rentr�e est 8 alors...
            AffichageLigneMemoire(y);// ...on ex�cute cette fonction situ�e dans action.c/h.
            break;
            case 9: // Si la valeur rentr�e est 9 alors...
            AffichageMaxPouls(tab, y);// ...on ex�cute cette fonction situ�e dans action.c/h.
            break;
            case 10: // Si la valeur rentr�e est 7 alors...
            AffichageMinPouls(tab, y);// ...on ex�cute cette fonction situ�e dans action.c/h.
            break;
        }
    }


