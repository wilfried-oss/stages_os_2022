#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    /*
        Declaration de tableau des éléments du pipe, une entree fd[1] et une sortie fd0]
        ret est le nom du tunnel
    */
    int fd[2], ret;

    // le buffer de stockage
    char buffer[BUFSIZ + 1];
    // Creation du tunnel(pipe)
    ret = pipe(fd);
    if (ret < 0)
    {
        /* Une erreur s'est produite lors de la création du pipe*/
        fprintf(stderr, "Erreur de création du pipe (%d)\n", errno);
        return 1;
    }
    char chaine[] = "UP/IUT/IG2/2022/systemProgramming\n";

    // Ecriture de la chaine dans l'extremite 1 du tunnel
    write(fd[1], chaine, strlen(chaine));

    // Lecture de la chaine dans le buffer depuis l'extrrémité 0
    read(fd[0], buffer, BUFSIZ);

    // Affichage du buffer
    printf("%s", buffer);
    return 0;
}