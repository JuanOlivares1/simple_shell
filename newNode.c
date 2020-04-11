#include "shell.h"

paths *newNode(paths **head, const char *arg)
{
        paths *new, *last;

        if (head == NULL)
                return (NULL);

        new = malloc(sizeof(paths));
        if (new == NULL)
                return (NULL);

        new->miniPath = strdup(arg);
        if (new->miniPath == NULL)
        {
                free(new);
                return (NULL);
        }

        new->next = NULL;

        last = last_node(*head);
        if (last == NULL)
                *head = new;
        else
                last->next = new;

        return (new);
}

paths *last_node(paths *head)
{
        if (head == NULL)
                return (NULL);

        if (head->next == NULL)
                return (head);

        return (last_node(head->next));
}
