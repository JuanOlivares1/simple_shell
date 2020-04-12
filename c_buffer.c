#include "shell.h"

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
	int i, j, arglen = 0;
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
