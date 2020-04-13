#include "shell.h"

/**
 * _strdup - string duplicator
 * @str: string to duplicate
 *
 * Return: pointer to new mallocated string's copy
 */
char *_strdup(char *str)
{
	int i, size;
	char *vector;

	if (str == NULL)
		return (NULL);
	for (i = 0; str[i]; i++)
		;
	i++;
	size = i;
	vector = malloc(size * sizeof(char));
	if (vector == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		*(vector + i) = *(str + i);
	*(vector + i) = '\0';
	return (vector);
}
