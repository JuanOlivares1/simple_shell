#include "shell.h"

/**
 * _getenv - finds the values of a env-variable
 * @name: name of variable to look for
 *
 * Return: value of env-variable. NULL if couldn't find
 */
char *_getenv(const char *name)
{
	int i;
	char *temp, *temp2;

	for (i = 0; environ[i]; i++)
	{
		temp = strdup(environ[i]);
		if (strtok(temp, "=") != NULL)
			if (strcmp(temp, name) == 0)
			{
				temp2 = strdup(strtok(NULL, "="));
				free(temp);
				return(temp2);
			}
		free(temp);
	}
	return (NULL);
}
