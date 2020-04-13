#include "shell.h"

paths *c_pathList(paths **head, char *path)
{
	char *token = strdup(path);
	char *temp;

	temp = token;
	token = strtok(token, ":");
	while (token != NULL)
	{
		newNode(head, token);
		token = strtok(NULL, ":");
	}
	free(temp);
	return (*head);
}

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
