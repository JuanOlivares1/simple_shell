#include "shell.h"

/**
 * assignValues - assing values to grind (array of strings of args)
 * @grind: allocated memory
 * @str: full string from getline
 * @nargs: number of args
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
	for (i = 0 ; token != NULL; i++)
	{
		for (j = 0; token[j]; ++j)
			grind[i][j] = token[j];
		grind[i][j] = '\0';
		token = strtok(NULL, delim);
	}
	grind[i] = NULL;
	free(temp);
}
