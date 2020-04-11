#include "shell.h"

/**
 *
 *
 *
 * Return: 0 if found, -1 otherwise
 */
void freeList(paths *head)
{
	if (head == NULL)
		return;

	freeList(head->next);
	free(head->miniPath);
	free(head);
}
