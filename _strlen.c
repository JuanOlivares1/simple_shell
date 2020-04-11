#include "shell.h"

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
