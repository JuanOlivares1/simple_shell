#include "shell.h"

/**
 * main - main function
 *
 * Return: always 0
 */

int main(void) /* getline */
{
	char **grind;
	char *buffer;
	size_t bufsize = 320;
	int nargs, i;
	char *save;

	buffer = malloc(bufsize * sizeof(char));
	if (buffer == NULL)
		exit(1);
	save = _getenv("PATH");
	printf("#cisfun$ ");
	while(getline(&buffer,&bufsize,stdin) != -1)
	{
		nargs = argsCount(buffer, " \n");
		grind = c_buffer(nargs, buffer);
		assignValues(grind, buffer);
		argsValidator(grind, save);
		for (i = 0; i < nargs; i++)
			free(grind[i]);
		free(grind); 
		printf("#cisfun$ ");
	}
	free(buffer);
	return (0);
}
