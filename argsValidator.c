#include "shell.h"

/**
 * argsValidator - validates if the command typed exists
 * @grind: array of strings of args
 *
 * Return: 0 if found, -1 otherwise
 */
int argsValidator(char **grind)
{
	pid_t child_pid;
	int status;
	paths *head = NULL;
	paths *temp;
	char *command;
	struct stat stt;

	if (stat(grind[0], &stt) == 0)
        {
                child_pid = fork();

                if (child_pid == 0)
                        if (execve(grind[0], grind, environ) == -1)
                                perror("Error:");
                if (child_pid > 0)
                        wait(&status);
                return (0);
        }

	head = c_pathList(&temp, _getenv("PATH"));
	temp = head;

	while (temp != NULL)
	{
		command = _strcat(temp->miniPath, grind[0]);
		if (stat(command, &stt) == 0)
		{
			grind[0] = command;

			child_pid = fork();

			if (child_pid == 0)
				if (execve(command, grind, environ) == -1)
					perror("Error:");
			if (child_pid > 0)
				wait(&status);
			//freeList(head);
			return (0);
		}
		temp = temp->next;
	}

	if (stat(grind[0], &stt) == -1)
	{
		printf("%s\n", grind[0]);
		return(0);
	}
	//freeList();
	return (-1);
}
