#include "shell.h"

/**
 * printenv - env function
 */
void printenv(void)
{
	unsigned int i = 0;

	while (environ[i] != NULL)
	{
		write(1, environ[i], _strlen(environ[i]));
		write(1, "\n", 1);
		i++;
	}
}
