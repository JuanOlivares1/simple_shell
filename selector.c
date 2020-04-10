#include "shell.h"

/**
 * selector - check
 *
 * @s: n arguments
 *
 * Return: always 0
 */

void selector(char *s, char *argb, int line) /*Count how many arguments are in getline and send to mallocshell.c */
{
	char delim[] = " ";
	int arg_count = 0;
	char *token;
	char *rep;

	line++;
	rep = _strdup(s);
	token = strtok(s, delim);
	while (token != NULL)
	{
		token = strtok(NULL, delim);
		arg_count++;
	}
	c_buffer(arg_count, rep, argb, line);
	free(rep);
}
