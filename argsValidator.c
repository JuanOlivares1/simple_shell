#include "shell.h"

/**
 * argsValidator - validates if the command typed exists
 * @grind: array of strings of args
 * @path: string, env-variable $PATH
 * @filename: name of executable file
 * @line: line of the command
 *
 * Return: 0 if found, -1 otherwise
 */
int argsValidator(char **grind, char *path, char *filename, int line)
{
	pid_t child_pid;
	int status;
	paths *temp, *head = NULL;
	char *command;
	struct stat stt;

	if (grind[0] == '\0')
		return (0);
	if (stat(grind[0], &stt) == 0)
	{	child_pid = fork();
		if (child_pid == 0)
			if (execve(grind[0], grind, environ) == -1)
				perror("Error:");
		if (child_pid > 0)
		{	wait(&status);
			if (WIFEXITED(status))
				return (WEXITSTATUS(status));		}
		return (0);	}
	temp = head;
	head = c_pathList(&temp, path);
	while (temp != NULL)
	{	command = _strcat(temp->miniPath, grind[0]);
		if (stat(command, &stt) == 0)
		{	child_pid = fork();
			if (child_pid == 0)
				if (execve(command, grind, environ) == -1)
					perror("Error:");
			if (child_pid > 0)
			{	free(command);
				freeList(head);
				wait(&status);
				if (WIFEXITED(status))
					return (WEXITSTATUS(status));	}
			return (0);		}
		free(command);
		temp = temp->next;	}
	if (stat(grind[0], &stt) == -1)
		freeList(head);
		return (errManager(filename, grind[0], line));
	freeList(head);
	return (0);	}
