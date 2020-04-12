#include "shell.h"

paths *c_pathList(paths **head, char *path)
{
	char *tmp = strdup(path);
	char *token;

	token = strtok(tmp, ":");
	while (token != NULL)
	{
		newNode(head, token);
		token = strtok(NULL, ":");
	}
	free(tmp);
	return (*head);
}
