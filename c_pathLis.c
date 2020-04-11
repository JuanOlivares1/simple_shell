#include "shell.h"

paths *c_pathList(paths **head, char *path)
{
	char *token = strdup(path);

	token = strtok(token, ":");
	while (token != NULL)
	{
		newNode(head, token);
		token = strtok(NULL, ":");
	}

	return (*head);
}
