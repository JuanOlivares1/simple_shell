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
        char *rtrn;
	int i, j, k, l = 0;

        for (i = 0; dest[i] != '\0'; ++i)
                ;

        for (j = 0; src[j] != '\0'; ++j)
                ;

	k = i + j + 2;

	rtrn = malloc(sizeof(char) * k);
	if (rtrn == NULL)
		return (NULL);

	for (i = 0; dest[i] != '\0'; ++i)
	{
		rtrn[l] = dest[i];
		l++;
	}

	 rtrn[l] = '/';
	 l++;

	for (j = 0; src[j] != '\0'; ++j)
	{
		rtrn[l] = src[j];
                l++;
	}

	rtrn[l] = '\0';

        return (rtrn);
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
