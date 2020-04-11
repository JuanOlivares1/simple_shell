#include "shell.h"

void myStartupFun(void) __attribute__ ((constructor));
/**
 * myStartupFun - Prints elements
 */
void myStartupFun(void)
{
printf("#cisfun$ \n");
}
/**
 * main - check
 *
 * @ac: n arguments
 * @av: means of arguments
 *
 * Return: always 0
 */

int main(__attribute__((unused)) int argc, char **argv) /* getline and send to selector */
{
	char *buffer;
	int line = 0;
	size_t bufsize = 32;

	buffer = malloc(bufsize * sizeof(char));
	if (buffer == NULL)
	{
		exit (1);
	}
	
	while(getline(&buffer,&bufsize,stdin) != -1)
	{
		selector(buffer, argv[0], line);
		printf("#cisfun$ ");
	}
	return (0);
}
