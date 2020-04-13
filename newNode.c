#include "shell.h"

/**
 * newNode - add a new node to a linked list
 * @head: pointer to list's head
 * @arg: each path from the system
 *
 * Return: void
 */
void newNode(paths **head, const char *arg)
{
	paths *new, *last;

	if (head == NULL)
		return;

	new = malloc(sizeof(paths));
	if (new == NULL)
		return;
	new->miniPath = strdup(arg);
	if (new->miniPath == NULL)
	{
		free(new);
		return;
	}
	new->next = NULL;

	last = last_node(*head);
	if (last == NULL)
		*head = new;
	else
		last->next = new;
}

/**
 * last_node - finds the last node from a list
 * @head: pointer to list's head
 *
 * Return: pointer to last node
 */
paths *last_node(paths *head)
{
	if (!head)
		return (NULL);
	if (head->next == NULL)
		return (head);
	return (last_node(head->next));
}
