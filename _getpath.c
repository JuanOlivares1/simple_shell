#include "shell.h"

/**
 * _getpath - finds the values of a env-variable
 *
 * Return: value of env-variable. NULL if couldn't find
 */

char *_getpath(void)
{
	char buffer[1024];
	char *path, *token;
	char delim[] = {"\"="};
	int fd, readLine, closeF;

	fd = open("/etc/environment", O_RDONLY);
	if (fd == -1)
	{
		perror("Error:");
		return (NULL);
	}
	for (readLine = 1024; readLine == 1024; )
	{
		readLine = read(fd, buffer, 1024);
		if (readLine == -1)
		{
			perror("Error: ");
			return (NULL);
		}
	}
	token = strtok(buffer, delim);
	if (token != NULL)
	{
		token = strtok(NULL, delim);
		path = _strdup(token);
	}
	closeF = close(fd);
	if (closeF == -1)
	{
		perror("Error: ");
		return (NULL);
	}
	return (path);
}


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
				return (temp2);
			}
		free(temp);
	}
	return (NULL);
}
