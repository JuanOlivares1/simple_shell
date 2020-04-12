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

	for (i = 0; environ[i]; i++)
	{
		if (strtok(environ[i], "=") != NULL)
			if (strcmp(environ[i], name) == 0)
				return(strtok(NULL, "="));
	}
	return (NULL);
}
