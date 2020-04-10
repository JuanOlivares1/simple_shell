#include "shell.h"

/**
* _strcmp - return char
*
* @s1: value
* @s2: value
*
*
* Return: Always 0 (Success)
*/

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (i >= 0)
	{
		if (s1[i] - s2[i] == 0 && s1[i] != '\0' && s2[i] != '\0')
		{
			i++;
		}
		else
		{
			break;
		}
	}
	return (s1[i] - s2[i]);
}

/**
 * _strdup - copy a string to string
 *
 * @str: string to copy
 *
 * Return: vector
 */

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
