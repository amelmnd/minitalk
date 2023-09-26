// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <unistd.h>
// #include <sys/wait.h>

// int main(void) {

// 	int waiting = 1000000*10;
//     pid_t c_pid = fork();
//     if (c_pid == -1) {
//         perror("fork");
//         exit(EXIT_FAILURE);
//     }

//     if (c_pid == 0) {
//         printf("printed from child process - %d\n", getpid());
//         exit(EXIT_SUCCESS);
//     } else {
//         printf("printed from parent process - %d\n", getpid());
//         wait(&waiting);
//     }

//     exit(EXIT_SUCCESS);
// }

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t pid;

	printf("Fork ici.\n");
	pid = fork();
	if (pid == -1)
	{
		// Si fork renvoie -1, il y a eu une erreur !
		return (1);
	}
	printf("\nFork reussi !\n");
	sleep(10);
	printf("sleep\n");
	if (pid == 0)
	{
		// La valeur de retour de fork est 0, ce qui veut dire qu'on est
		// dans le processus fils
		printf("Fils : Je suis le fils, mon pid interne est %d.\n", pid);
	}
	usleep(1000000);
	printf("usleep\n");
	if (pid > 0)
	{
		// La valeur de retour de fork
		// est différente de 0, ce qui veut dire
		// qu'on est dans le processus père
		printf("Pere : Je suis le pere, le pid de mon fils est %d.\n", pid);
	}
	return (0);
}