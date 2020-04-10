#include "shell.h"

/**
 * assingValues - check
 *
 * @string: space
 *
 * Return: nothing
 */
void assignValues(char **ptr, char *s, int cont, char *argb, int line)
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
	if (_strcmp(ptr[0], "exit") == 0)
	{
		for (i = 0; i < cont; i++)
		{
			free(ptr[i]);
		}
		free(ptr);
		_exit(0);
	}
	else if ((_strcmp(ptr[0], "exit") == 0) && ptr[1] != NULL)
	{
		managment(ptr, argb, line);
	}
	else if ((_strcmp(ptr[0], "env") == 0 && ptr[1] == NULL))
	{
		i = 0;
		while(environ[i] != NULL)
		{
			printf("%s", environ[i]);
			i++;
		}
	}
	else
		exe(ptr, argb, line);
	for (i = 0; i < cont; i++)
	{
		free(ptr[i]);
	}
	free(ptr);
}
