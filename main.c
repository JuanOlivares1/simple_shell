#include "shell.h"

/**
 * main - check
 *
 * @ac: n arguments
 * @av: means of arguments
 *
 * Return: always 0
 */

int main(void) /* getline and send to selector */
{
	char *buffer;
	size_t bufsize = 32;

	buffer = malloc(bufsize * sizeof(char));
	if (buffer == NULL)
	{
		exit (1);
	}
	printf("#cisfun$ ");
	while(getline(&buffer,&bufsize,stdin) != -1)
	{
		selector(buffer);
		printf("#cisfun$ ");
	}
	return (0);
}
