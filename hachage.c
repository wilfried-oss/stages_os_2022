#include <stdio.h>
#include <stdlib.h>

int hachage(char *chaine)
{
    int i = 0, nombreHache = 0;
    for (i = 0; chaine[i] != '\0'; i++)
    {
        nombreHache += chaine[i];
    }
    nombreHache %= 100;
    return nombreHache;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage : %s 'string'\n", argv[0]);
        return 1;
    }
    printf("Hachage de %s donne %2.2x \n", argv[1], hachage(argv[1]));
    return 0;
}