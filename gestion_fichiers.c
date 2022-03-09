#include <stdio.h>
#include <stdlib.h>
int main()
{
    /*
    Ecriture
    We'll use 4 functions:
        fopen
        fputs (1 character)/ fputs(string) / fprintf(format text)
    */

    FILE *fichier = NULL;             // Pointeur vers fichier
    fichier = fopen("test.txt", "w"); // ouverture
    if (fichier != NULL)
    {
        fputs("Operating system IUT/ IG / 2022\nComment allez-vous ?", fichier);
        fclose(fichier); // fermeture
    }

    int caractereActuel = 0;
    fichier = fopen("test.txt", "r");
    if (fichier != NULL)
    {
        // Boucle de lecture des caractères un à un
        do
        {
            caractereActuel = fgetc(fichier); // On lit le caractère
            printf("%c", caractereActuel);    // On l'affiche
        } while (caractereActuel != EOF);     // On continue tant que fgetc n'a pas retourné EOF (fin de fichier)
    }

    printf("\n");

    fclose(fichier);

    int *memoireAllouee = NULL;
    memoireAllouee = malloc(sizeof(int)); // Allocation de la mémoire
    if (memoireAllouee == NULL)
    {
        exit(0);
    }
    // Utilisation de la mémoire
    printf("Quel age avez-vous ? ");
    scanf("%d", memoireAllouee);
    printf("Vous avez %d ans\n", *memoireAllouee);
    free(memoireAllouee); // Libération de mémoire

    return 0;
}
