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
