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
        Declaration de tableau des éléments du pipe, une entree fd[0] et une sortie fd[1]
        ret est le nom du tunnel
    */
    int fd[2], ret;
    // Creation du tunnel(pipe)
    ret = pipe(fd);
    if (ret < 0)
    { /* Une erreur s'est produite lors de la création du pipe*/
        fprintf(stderr, "Erreur de création du pipe (%d)\n", errno);
        return 1;
    }

    /*On cree le processus fils*/
    int pid = fork();
    if (pid < 0)
    {
        printf("Fork sans succes\n");
        return 1;
    }
    if (pid == 0)
    {
        /*Nous sommes dans le fils*/
        char buffer[BUFSIZ + 1];

        close(fd[1]); // on ferme l'extrémité d'écriture
        while (read(fd[0], buffer, BUFSIZ) != 0)
            printf("Child read %s", buffer);
        close(fd[0]);
    }
    else
    {
        /*Nous sommes dans le pere*/
        char buffer[BUFSIZ + 1];

        close(fd[0]); // on ferme l'extrémité de lecture
        strcpy(buffer, "Message\n");
        write(fd[1], buffer, strlen(buffer) + 1);
        close(fd[1]);
    }
}