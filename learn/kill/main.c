#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>


// Routine du processus fils :
void    routine_fils(void)
{
    printf("\e[36mFils : Coucou! Je suis un fils. Je tourne a l'infini.\e[0m\n");
    while (1) // Tourne a l'infini
        continue;
}

// Routine du processus pere :
void    kill_and_get_children(pid_t *pid)
{
    int	status;
    int	i;

    printf("Pere : Je suis le pere filicide.\n");
    i = 0;
    while (i < 3) // Tue les 3 fils avec un signal
    {
        kill(pid[i], SIGKILL);
        i++;
    }

    i = 0;
    while (i < 3) // Récupère la sortie de chaque fils
    {
        waitpid(pid[i], &status, 0);
        if (WIFEXITED(status))
            printf("Fils [%d] a terminé normalement.\n", pid[i]);
        else if (WIFSIGNALED(status))
        {
            printf("Fils [%d] a ete interrompu.\n", pid[i]);
            if (WTERMSIG(status) == SIGTERM)
                printf("\e[31mFils [%d] a recu le signal %d, SIGTERM\e[0m\n",
                            pid[i], WTERMSIG(status));
            if (WTERMSIG(status) == SIGKILL)
                printf("\e[31mFils [%d] a recu le signal %d, SIGKILL\e[0m\n",
                            pid[i], WTERMSIG(status));
        }
        i++;
    }  printf("Pere : J'ai tue tous mes fils mwahahaaa !\n");
}

int    main(void)
{
    pid_t    pid[3]; // Stocke les retours de fork
    int      i;

    i = 0;
    while (i < 3) // Crée 3 fils
    {
        pid[i] = fork(); // Création d'un processus fils
        if (pid[i] == -1)
            return (EXIT_FAILURE);
        else if (pid[i] == 0)
            routine_fils();
        else if (pid[i] > 0)
            printf("Fils #%d cree avec pid = %d\n", i, pid[i]);
        usleep(1000); // Décaler les fils un peu dans le temps
        i++;
    }
    kill_and_get_children(pid);
    return (EXIT_SUCCESS);
}