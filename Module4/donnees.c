#include "donnees.h"
#include <stdio.h>

int LectureFichier (Battements *tab) //Programme de lecture du fichier.
{
    char chaine[20]; // Initialisation d'un tableau de caractères de 5 lignes.
    int y=0;
    FILE* fichier = NULL; // Creation d'un pointeur sur fichier.

    fichier = fopen("Classeur2.csv", "r"); // Ouvertutre du fichier.
    if (fichier != NULL) // Si le pointeur ne pointe pas sur NULL cela signifie qu'on a bien réussi a ouvrir notre document.
    {
        while(fgets(chaine, MAX_LIGNES, fichier)!=NULL)                // Tant que l'on peut lire une ligne du fichier qui ne soit pas vide ou que l'on ai
        {                                                              // atteint le maximum de ligne, la fonction fgets lit la ligne du fichier et la stocke
            sscanf(chaine, "%lf;%d", &tab[y].temps, &tab[y].pouls);     // dans un tableau de caractère puis, directement, elle est traitée avec la fonction
            y++;                                                       // sscanf qui permet de la lire et d'extraire les valeurs dans notre tableau structuré.
        }
        return y; // On retourne notre valeur y, c'est à dire le nombre de fois que nous avons effectué la boucle "tant que" (notre nombre de lignes de notre tableau donc).
        fclose(fichier); // On ferme le fichier qui a été ouvert pour éviter les fuites mémoires.
    }
    else
    {
        printf("Impossible d'ouvrir le fichier csv.\n"); //Si le pointeur pointe encore sur NULL cela signifie que le fichier n'a pas été trouvé.
    }
}
