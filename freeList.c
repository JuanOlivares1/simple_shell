#include "shell.h"

/**
 * freeList - frees all memory allocated ofr linked list
 * @head: pointer to list's head
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
