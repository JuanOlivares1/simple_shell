#include "shell.h"

/**
 * c_buffer - malloc create
 *
 * @st: getline
 * @contador: lines contador
 *
 * Return: n characters per word
 */
void c_buffer(int contador, char *st, char *argb, int line) /*creation of malloc and send to exe*/
{
	char **space;
	int i, j, ite = 0, letters = 0;
	char *token;
	char *ptr1;
	char delim[] = " ";

	space = malloc(sizeof(char*) * contador + 1);
	if (space == NULL)
	{
		return;
	}
	ptr1 = _strdup(st);
	token = strtok(st, delim);

	for (i = 0; i < contador || token != NULL; i++) /*contador = 1*/
	{
		letters = st_contador(token);
		token = strtok(NULL, delim);
		space[i] = malloc(sizeof(char) * letters);
		if (space[i] == NULL)
		{
			for (ite = 0; ite < contador; ite++)
			{
				free(space[ite]);
			}
			free(space);
			return;
		}
		for (j = 0; j < letters; j++)
	      	{
			space[i][j] = 0;
		}
	}
	assignValues(space, ptr1, contador, argb, line);
	free(ptr1);
}
