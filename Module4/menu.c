#include "menu.h"
#include "actions.h"
#include "donnees.h"
#include <stdio.h>

int a;  // Déclaration des variables.

int AffichageMenu() // Fonction permettant d'afficher un menu dans la console.
{
    int a;
    printf("Bienvenue dans le menu, rentrez 1 pour continuer ou 0 pour quittez le programme.\n"); // Affichage d'une phrase sur la console.
    scanf("%d", &a); //On demande à l'utilisateur de rentrer une valeur et on la stocke à l'adresse de la variable "a".
    if (a == 1) // Début de la boucle conditionnelle "si", si la valeur rentrée est 1 alors on effectue ce qu'il se trouve entre les accolades.
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
        scanf("%d", &a); // On demande à l'utilisateur de rentrer une valeur que l'on stocke à l'adresse de la variable "a".
        printf("\n"); // Retour à la ligne pour aérer la console.
    }
    while (a<0 || a>10) // Tant que la valeur ne fait pas partie d'une de celles proposée on demandera a l'utilisateur de rentrer une valeur correcte.
    {
        printf("Cette option n'existe pas, rentrez une valeur existante.\n");
        scanf("%d", &a);
    }
    return a; // On retourne la valeur de "a".
}

    void nbrchoisi(int a, Battements *tab, int y) // Fonction qui effectue les différents cas en fonction de ce que l'utilisateur avait rentré comme chiffre.
    {
        switch (a)
        {
            case 1: // Si la valeur rentrée est 1 alors...
            AfficherOrdreCSV(tab, y); // ...on exécute cette fonction située dans action.c/h.
            break;
            case 2:  // Si la valeur rentrée est 2 alors...
            AfficherOrdreCroiTemps(tab, y); // ...on exécute cette fonction située dans action.c/h.
            break;
            case 3: // Si la valeur rentrée est 3 alors...
            AfficherOrdreCroiPouls(tab, y); // ...on exécute cette fonction située dans action.c/h.
            break;
            case 4: // Si la valeur rentrée est 4 alors...
            AfficherOrdreDecroiTemps(tab, y); // ...on exécute cette fonction située dans action.c/h.
            break;
            case 5: // Si la valeur rentrée est 5 alors...
            AfficherOrdreDecroiPouls(tab, y); // ...on exécute cette fonction située dans action.c/h.
            break;
            case 6: // Si la valeur rentrée est 6 alors...
            RechercheDonnees(tab, y); // ...on exécute cette fonction située dans action.c/h.
            break;
            case 7: // Si la valeur rentrée est 7 alors...
            AffichageMoyenne(tab, y); // ...on exécute cette fonction située dans action.c/h.
            break;
            case 8: // Si la valeur rentrée est 8 alors...
            AffichageLigneMemoire(y);// ...on exécute cette fonction située dans action.c/h.
            break;
            case 9: // Si la valeur rentrée est 9 alors...
            AffichageMaxPouls(tab, y);// ...on exécute cette fonction située dans action.c/h.
            break;
            case 10: // Si la valeur rentrée est 7 alors...
            AffichageMinPouls(tab, y);// ...on exécute cette fonction située dans action.c/h.
            break;
        }
    }


