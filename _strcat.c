#include "shell.h"

/**
 * _strcat - Concatenates 2 strings
 * @src: string to add
 * @dest: final string
 *
 * Return: char *
 */
char *_strcat(char *dest, char *src)
{
        int i, j, k;

        for (i = 0; dest[i] != '\0'; ++i)
                ;

        for (j = 0; src[j] != '\0'; ++j)
                ;

	dest[i] = '/';
	i++;

        for (k = 0; k <= j; k++)
        {
                dest[i] = src[k];
                i++;
        }
        return (dest);
}

char *_strdup(char *str)
{
	int ite; /*iterator*/
	char *vector;
	int size = 0;

	if (str == NULL)
	{
		return (NULL);
	}
	for (ite = 0; str[ite]; ite++)
	{
		size++;
	}
	size += 1;
	vector = malloc(size * sizeof(char));
	if (vector == NULL)
	{
		return (NULL);
	}
	for (ite = 0; ite < size; ite++)
	{
		*(vector + ite) = *(str + ite);
	}
	*(vector + ite) = '\0';
	return (vector);
}
