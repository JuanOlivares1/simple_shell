#include "shell.h"

/**
 * main - main function
 *
 * @av: argument
 * @ac: n argument
 *
 * Return: always 0
 */

int main(__attribute__((unused)) int ac, char **av)
{
	char **grind;
	char *buffer, *path;
	size_t bufsize = 320;
	int nargs, i, status = 0, line = 0;

	buffer = malloc(bufsize * sizeof(char));
	if (buffer == NULL)
		exit(1);
	path = _getenv("PATH");
	if (isatty(0) == 1)
		write(1, "#cisfun$ ", 9);
	while (getline(&buffer, &bufsize, stdin) != -1)
	{
		line++;
		nargs = argsCount(buffer, "\t\n ");
		grind = c_buffer(nargs, buffer);
		assignValues(grind, buffer);
		status = argsValidator(grind, path, av[0], line);
		for (i = 0; i < nargs; i++)
			free(grind[i]);
		free(grind);
		if (isatty(0) == 1)
			write(1, "#cisfun$ ", 9);
	}
	if (isatty(0) == 1)
		write(1, "\n", 1);
	free(path);
	free(buffer);
	return (status);	}
