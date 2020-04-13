#include "shell.h"

/**
 * _strcat - Concatenates 2 strings
 * @src: string to add
 * @dest: final string
 *
 * Return: new malloc with concatenated string
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
