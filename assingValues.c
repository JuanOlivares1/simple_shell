#include "shell.h"

/**
 * assingValues - check
 *
 * @string: space
 *
 * Return: nothing
 */
void assignValues(char **ptr, char *s, int cont)
{
	char *token;
	char delim[] = " ";
	int i = 0, j = 0;

	token = strtok(s, delim);
	for (i = 0; i < cont || token != NULL; i++)
	{
		for(j = 0; token[j] != '\0'; j++)
			ptr[i][j] = token[j];
		token = strtok(NULL, delim);
	}
	ptr[i - 1][j - 1] = '\0';
	ptr[i] = NULL;
	exe(ptr);
	for (i = 0; i < cont; i++)
	{
		free(ptr[i]);
	}
	free(ptr);
}
