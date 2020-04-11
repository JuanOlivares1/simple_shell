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
