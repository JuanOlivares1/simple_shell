#ifndef SHELL_H
#define SHELL_H

/* libraries */
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* main prototypes */
void cisfun (void) __attribute__ ((constructor));
int argsCount(char *s, char *delim);
char **c_buffer(int nargs, char *s);
void assignValues(char **grind, char *str, int nargs);
char *_getenv(const char *name);
int argsValidator(char **grind);
void exe(char **string);

/* string manipulation prototypes */
int _strlen (char *s);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);

/* structs */
typedef struct paths
{
        char *miniPath;
        struct paths *next;
} paths;

/* list manipulation prototypes */
paths *c_pathList(paths **head,char *path);
paths *newNode(paths **head, const char *arg);
paths *last_node(paths *head);
void freeList(paths *head);

/* environment variables */
extern char **environ;

#endif /* SHELL_H */
