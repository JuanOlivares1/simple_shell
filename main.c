#include "shell.h"

/**
 * main - main function
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
	int nargs, status = 0, line = 0, flag = 0, f = 0;

	buffer = malloc(bufsize * sizeof(char));
	if (buffer == NULL)
		exit(1);
	if (isatty(0) == 1)
		write(1, "#cisfun$ ", 9);
	while (getline(&buffer, &bufsize, stdin) != -1)
	{	path = _getenv("PATH");
		if (path == NULL)
		{
			path = ".";
			f = 1;	}
		line++;
		nargs = argsCount(buffer, " \t\n");
		grind = c_buffer(nargs, buffer);
		assignValues(grind, buffer);
		if (grind[0] != '\0')
			if (_strcmp(grind[0], "exit") == 0)
			{	freeGrind(grind, nargs);
				flag = 1;
				break;	}
		if (_strcmp(grind[0], "env") == 0)
			printenv();
		else
			status = argsValidator(grind, path, av[0], line);
		freeGrind(grind, nargs);
		if (f == 0)
			free(path);
		if (isatty(0) == 1)
			write(1, "#cisfun$ ", 9);
	}
	if (isatty(0) == 1 && flag == 0)
		write(1, "\n", 1);
	if (flag == 1 && f == 0)
		free(path);
	free(buffer);
	return (status);	}
