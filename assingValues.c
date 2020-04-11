#include "shell.h"

/**
 * assignValues - assing values to grind (array of strings of args)
 * @grind: allocated memory
 * @str: full string from getline
 * @nargs: number of args
 *
 * Return: void
 */
void assignValues(char **grind, char *str, int nargs)
{
	char *token = strdup(str);
	char *temp = token;
	int i, j;
	char delim[] = " ";

	token = strtok(str, delim);
	for (i = 0; i < nargs || token != NULL; i++)
	{
		for (j = 0; token[j]; j++)
			grind[i][j] = token[j];
		token = strtok(NULL, delim);
	}
	grind[i - 1][j - 1] = '\0';
	grind[i] = NULL;
	free(temp);
}
