#include "actions.h"
#include "donnees.h"
#include <stdio.h>


void AfficherOrdreCSV (Battements *tab, int y) // Fonction permettant d'afficher les données du tableau dans l'ordre d'entrée.
{
    int i;
    for (i = 0; i < y; i++) // On recommence cette boucle jusqu'a ce que "i" atteigne la valeur de notre nombre de lignes en mémoire
    {                       // (on augmente la valeur de "i" de 1 à chaque boucle)
        printf("Temps(ms): %.2lf; Pouls: %d\n", tab[i].temps, tab[i].pouls); // A chaque boucle on affiche
    }
}


void AfficherOrdreCroiTemps (Battements *tab, int y) // Meme fonction que la précedente, on inverse juste l'affichage des deux colonnes.
{
    int i;
    for (i = 0; i < y; i++)
    {
        printf("Pouls: %d; Temps(ms): %.2lf\n", tab[i].pouls, tab[i].temps);
    }
}

void AfficherOrdreCroiPouls (Battements *tab, int y) // Fonction permettant d'afficher le temps pouls dans l'ordre croissant.
{
    Battements TabPoulsCrois[MAX_LIGNES]; // Initialisation d'un tableau de structure comportant MAX_LIGNES (ici 60 000, voir donnees.h).
    int i; // Déclaration de variable.
    for (i = 0; i < y; i++) // Boucle for permettant de parcourir chaque ligne du tableau.
    {
        TabPoulsCrois[i].pouls = tab[i].pouls; // On rentre notre tableau dans un nouveau tableau permettant ainsi d'effectuer d'autre fonction à la suite
        TabPoulsCrois[i].temps = tab[i].temps; // de celle-ci sans que notre "tab" soit déjà trié.
    }
    TriInsertion(TabPoulsCrois, y); // On tri notre tableau avec la fonction TriInsertion.
    for (i = 0 ; i < y; i++) // On parcourt chaque ligne de notre tableau et...
    {
        printf("Pouls: %d; Temps(ms): %.2lf.\n", TabPoulsCrois[i].pouls, TabPoulsCrois[i].temps); //... on affiche chaque ligne sur la console.
    }
}

void AfficherOrdreDecroiTemps (Battements *tab, int y) // Fonction permettant d'afficher le temps dans l'ordre décroissant.
{
    int i,j=0; // Déclaration de variables.
    Battements TabInverse[MAX_LIGNES]; // Création d'un tableau de structure comportant MAX_LIGNES (ici 60000, voir donnees.h).

    for (i = y-1; i >= 0; i--) // Boucle "for", i prend la valeur du nombre de lignes de notre fichier -1. On effectue ce qu'il se trouve en diminuant la valeur
    {                         // de i de 1 à chaque boucle jusqu'a atteindre la valeur 0. Cela permet de lire notre tableau à l'envers.
        TabInverse[j].temps = tab[i].temps; // Dans la boucle on associe chaque valeur de notre tab dans un autre tableau dont l'indice commence à 0 et augmente.
        TabInverse[j].pouls = tab[i].pouls;
        j++;
    }
    for (i = 0; i < y; i++) // Boucle qui nous permet de parcourir notre tableau ligne par ligne.
    {
        printf("Temps(ms): %.2lf; Pouls: %d\n", TabInverse[i].temps, TabInverse[i].pouls); // On affiche chaque ligne de notre tableau inversé.
    }
}

void AfficherOrdreDecroiPouls (Battements *tab, int y) // Meme principe que la fonction AfficherOrderCroiPouls, on parcourt notre tableau dans l'autre sens.
{
    Battements TabPoulsCrois[MAX_LIGNES];
    int i=0;
    for (i = 0; i < y; i++)
    {
        TabPoulsCrois[i].temps = tab[i].temps;
        TabPoulsCrois[i].pouls = tab[i].pouls;
    }
    TriInsertion(TabPoulsCrois, y);
    for (i = y-1; i >1; i--)
    {
        printf("Pouls: %d; Temps(ms): %.2lf.\n", TabPoulsCrois[i].pouls, TabPoulsCrois[i].temps);
    }
}

void RechercheDonnees (Battements *tab, int y) // Fonction permettant de demander a l'utilisateur de rentrer une valeur de temps pour connaitre le pouls associé.
{
    int i, x = 0; // Initialisation des variables.
    double tps;
    printf("Saisissez une valeur de temps pour connaitre le pouls correspondant : "); // Affichage d'une phrase sur la console.
    scanf("%lf", &tps); // Le nombre que rentre l'utilisateur est stocké à l'adresse de la variable tps.
    for (i = 0; i < y; i++) // Boucle qui permet de parcourir le tableau.
    {
        if (tab[i].temps == tps) // Si la valeur qu'a rentré l'utilisateur correspond à une des valeurs de notre tableau alors...
        {
            printf("Pour un temps de %.2lf ms, le pouls est %d BPM.\n", tps, tab[i].pouls); //...on affiche notre la valeur rentré par l'utilisateur
            x = 1;                                                                          // ainsi que le pouls associé a cette valeur.
        }
    }
    if (x == 0) // Si on ne trouve pas la valeur de l'utilisateur dans le tableau alors on affiche la phrase dans l'accolade.
    {
        printf("%.2lf ms ne correspond pas a une valeur de temps enregistree,\nVeuillez recommencer...\n", tps);
    }
}

void AffichageMoyenne (Battements *tab, int y) // Fonction permettant d'afficher la moyenne du pouls de notre tableau/fichier.
{
    int i, debut, fin, dChange = 0, fChange = 0; // Initialisation des variables.
    float somme = 0.0;
    printf("Saisissez la valeur de temps de votre debut de plage : "); // Affichage d'une phrase dans la console.
    scanf("%i", &debut); // L'utilisateur rentre un chiffre qui est stocké à l'adresse de la variable debut.
    printf("Saisissez la valeur de fin de temps de votre plage : "); // Affichage d'une phrase dans la console.
    scanf("%i", &fin); // L'utilisateur rentre un chiffre qui est stocké à l'adresse de la variable fin.

    for (i = 0; i < y; i++) // Boucle For permettant de parcourir chaque ligne de notre tableau.
    {
        if (dChange == 0 || fChange == 0) // Boucle if qui s'exécute tant que dChange ou fChange est égale à 0.
        {
            if (tab[i].temps == debut) // Boucle if qui s'exécutera tant que la valeur de tab[i].temps sera différent de la valeur rentrer par l'utilisateur.
            {
                debut = i; // Une fois que la valeur est identique debut prend la valeur du numéro de la ligne qui correspond et...
                dChange = 1; // dChange passe à 1 remplissant ainsi une des deux conditions permettant de mettre fin à la boucle for.
            }
            if (tab[i].temps == fin) // Même principe que dessus.
            {
                fin = i;
                fChange = 1;
            }
        }
    }
    if (dChange == 0 && fChange == 0) // Si les deux valeurs ne correspondent à une aucune ligne du tableau cale signifie que la plage de valeur rentré par
    {                                 // par l'utilisateur n'existe pas. On affiche donc une phrase d'erreur.
        printf("La borne inferieur et la borne superieur sont incorrectes, veuillez recommencer...\n");
    }
    else if (dChange == 0) // Si seulement dChange est égale à 0 à la fin de la boucle for, cela signifie qu'il n'existe aucune valeur pour ce temps.
    {
        printf("La borne inferieur est incorrecte, veuillez recommencer...\n");
    }
    else if (fChange == 0) // Si seulement fChange est égale à 0 à la fin de la boucle for, cela signifie qu'il n'existe aucune valeur pour ce temps.
    {
        printf("La borne superieur est incorrecte, veuillez recommencer...\n");
    }
    else
    {
        for (i = debut; i <= fin; i++) // On lit les lignes du tableau situées entre nos bornes.
        {
            somme += tab[i].pouls; // somme prend la valeur sommme + chaque valeur de pouls entre les bornes.
        }
        somme /= fin - debut + 1; // somme prend la valeur de la somme divisé par la valeur de fin - celle du début +1 permettant ainsi de calculer la moyenne.
        printf("\nLa moyenne de la valeur %d a la valeur %d est de %.2f BPM.\n", debut, fin, somme); // On affiche les résultats.
    }
}

void AffichageLigneMemoire (int y) // Fonction permettant d'afficher le nombre de lignes de notre tableau.
{
 printf("Votre nombre de lignes en memoire est de %d\n", y); // Il suffit d'afficher y, c'est le "compteur" de ligne que l'on utilise lorsque l'on rentre
                                                             // les valeurs du fichier CSV dans notre tableau (voir donnees.c).
}

void AffichageMaxPouls (Battements *tab, int y) // Fonction permettant d'afficher le maximum de pouls, algorithme de recherche séquentielle.
{
    int i, m=0; // On initialise nos variables, ici m=0 pour initialiser une valeur qui sera bien inférieur a un pouls normal.

    for (i = 0; i<y ; i++) // Début de la boucle "pour", comme bon nombre de fonctions précedantes cette ligne permet de parcourir le tableau.
    {
        if (tab[i].pouls > m) // On cherche une valeur de pouls plus grande que la variable m, si on la trouve alors...
        {
            m = tab[i].pouls; //... m prend la valeur de ce pouls puis on recommence jusqu'a trouver la valeur la plus faible.
        }
    }
    printf("La valeur maximale du pouls est de %d\n", m); // Une fois la boucle terminé on affiche la valeur c'est a dire la valeur maximale du pouls.
}

void AffichageMinPouls(Battements *tab, int y) // Fonction permettant d'afficher le minimum de pouls, algorithme de recherche séquentielle.
{
    int i, m=2000; // On initialise nos variables, ici m=2000 pour initialiser une valeur qui sera bien supérieur au pouls.

    for (i = 0; i<y ; i++) // Début de la boucle "pour", comme bon nombre de fonctions précedantes cette ligne permet de parcourir le tableau.
    {
        if (tab[i].pouls < m) // On cherche une valeur de pouls plus petite que la variable m, si on la trouve alors...
        {
            m = tab[i].pouls; //... m prend la valeur de ce pouls puis on recommence jusqu'a trouver la valeur la plus faible.
        }
    }
    printf("La valeur minimale du pouls est de %d\n", m); // Une fois la boucle terminé on affiche la valeur c'est a dire la valeur minimale du pouls.
}


void TriInsertion(Battements *tab, int y) // Fonction permettant d'effectuer un tri par insertion.
{
    int i, j, vTemps;
    float vFreq;

    for(i = 0; i < y; ++i)
    {
        vFreq = tab[i].pouls;
        vTemps = tab[i].temps;
        j = i;
        while(j > 0 && tab[j - 1].pouls > vFreq)
        {
            tab[j].pouls = tab[j - 1].pouls;
            tab[j].temps = tab[j - 1].temps;
            j = j - 1;
        }
    tab[j].pouls = vFreq;
    tab[j].temps = vTemps;
    }

}
