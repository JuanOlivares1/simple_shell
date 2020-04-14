#include "shell.h"

/**
 * lineString - Concatenates 2 strings
 *
 * @n: int to add
 *
 * Return: new malloc with concatenated string
 */
void lineString(int n)
{
	char temp[2];

	while (n / 10)
	{
		lineString(n / 10);
		break;
	}
	temp[0] = ((n % 10) + '0');
	temp[1] = '\0';
	write(2, temp, 1);
}

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

/**
 * _strcmp - Compares 2 strings
 * @s1: string to be compared
 * @s2: string to be compared
 *
 * Return: int
 */
int _strcmp(char *s1, char *s2)
{
	int i, rtn = 0;

	for (i = 0; s1[i] || s2[i]; i++)
	{
		if (s1[i] != s2[i])
		{
			rtn = s1[i] - s2[i];
			break;
		}
	}
	return (rtn);
}

/**
 * _strdup - string duplicator
 * @str: string to duplicate
 *
 * Return: pointer to new mallocated string's copy
 */
char *_strdup(const char *str)
{
	int i, size = 0;
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
	for (i = 0; i < (size - 1); i++)
		vector[i] = str[i];
	vector[i] = '\0';
	return (vector);
}

/**
 * _strlen - finds the length of a string.
 * @s: pointer to a string.
 *
 * Return: int.
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
		;
	return (i);
}
