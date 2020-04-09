#include "shell.h"

/**
 * exe - print executables
 *
 * @string: space
 *
 * Return: nothing
 */
void exe(char **string) /* execute and print to stdout */
{
	pid_t child_pid;
    	int status;
	struct stat st;

	if(stat(string[0], &st) == -1) /*write falta */
	{
		/*write(2, "%s command no found", 17);*/
		printf("%s\n", string[0]);
		return;
	}
	/* Falta hacer el stat */
	child_pid = fork();

	if (child_pid == 0)
		if (execve(string[0], string, NULL) == -1)
        		perror("Error:");

	if (child_pid > 0)
		wait(&status);
}
