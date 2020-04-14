#include "shell.h"


/**
 * errManager - Prints error output
 *
 * @filename: name of the executable file
 * @grindvalue: name of the first value
 * @line: line of the shell
 *
 * Return: 127 as error
 */
int errManager(char *filename, char *grindvalue, int line)
{
	int strlenString = 0;

	strlenString = _strlen(filename);
	write(2, filename, strlenString);
	write(2, ": ", 2);
	lineString(line);
	write(2, ": ", 2);
	strlenString = _strlen(grindvalue);
	write(2, grindvalue, strlenString);
	write(2, ": not found\n", 12);
	return (127);
}
