#include "shell.h"

/**
 * main - main function
 *
 * Return: always 0
 */

int main(void)
{
	char **grind;
	char *buffer;
	size_t bufsize = 320;
	int nargs, i;
	char *path;

	buffer = malloc(bufsize * sizeof(char));
	if (buffer == NULL)
		exit(1);

	path = _getenv("PATH");

	if (isatty(0) == 1)
		printf("#cisfun$ ");
	while (getline(&buffer, &bufsize, stdin) != -1)
	{
		nargs = argsCount(buffer, " \t\n");
		grind = c_buffer(nargs, buffer);
		assignValues(grind, buffer);
		argsValidator(grind, path);
		for (i = 0; i < nargs; i++)
		{
			free(grind[i]);
		}
		free(grind);
		if (isatty(0) == 1)
			printf("#cisfun$ ");
	}
	free(path);
	free(buffer);
	return (0);
}
