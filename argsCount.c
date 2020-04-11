#include "shell.h"

/**
 * arg_count - Counts the number of args from getline
 * @s: full string of args separeted by delim
 * @delim: delimiter
 *
 * Return: number of args
 */
int argsCount(char *s, char *delim)
{
	int arg_count = 0;
	char *token = strdup(s);
	char *temp = token;

	token = strtok(token, delim);
	while (token != NULL)
	{
		token = strtok(NULL, delim);
		arg_count++;
	}
	free(temp);
	return (arg_count);
}
