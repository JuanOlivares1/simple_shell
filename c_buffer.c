#include "shell.h"

/**
 * argsCount - Counts the number of args from getline
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

/**
 * c_buffer - allocates the memory where the args will be stored
 * @s: full string from getline
 * @nargs: number of args
 *
 * Return: pointer to memory allocated
 */
char **c_buffer(int nargs, char *s)
{
	char **space;
	int i, j, arglen;
	char *token = strdup(s), delim[] = " \n";
	char *temp = token;

	space = malloc(sizeof(char *) * (nargs + 1));
	if (space == NULL)
		return (NULL);
	token = strtok(token, delim);
	for (i = 0; token != NULL; i++)
	{
		arglen = _strlen(token);
		arglen++;
		space[i] = malloc(sizeof(char) * arglen);
		if (space[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(space[j]);
			free(space);
			return (NULL);
		}
		token = strtok(NULL, delim);
	}
	free(temp);
	return (space);
}

/**
 * assignValues - assing values to grind (array of strings of args)
 * @grind: allocated memory
 * @str: full string from getline
 *
 * Return: void
 */
void assignValues(char **grind, char *str)
{
	char *token = strdup(str);
	char *temp = token;
	int i, j;
	char delim[] = " \n";

	token = strtok(str, delim);
	for (i = 0; token != NULL; i++)
	{
		for (j = 0; token[j]; ++j)
			grind[i][j] = token[j];
		grind[i][j] = '\0';
		token = strtok(NULL, delim);
	}
	grind[i] = NULL;
	free(temp);
}
