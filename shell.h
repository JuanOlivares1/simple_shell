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

/* environment variables */
extern char **environ;

/* structs */
/**
 * struct paths - singly linked list
 * @miniPath: string - (malloc'ed string)
 * @next: points to the next node
 *
 * Description: list of all paths from the system.
 */
typedef struct paths
{
	char *miniPath;
	struct paths *next;
} paths;

/* main prototypes */
void cisfun(void) __attribute__ ((constructor));
int argsCount(char *s, char *delim);
char **c_buffer(int nargs, char *s);
void assignValues(char **grind, char *str);
void freeGrind(char **grind, int nargs);
char *_getenv(char *name);
char *_getpath(void);
int argsValidator(char **grind, char *path, char *filename, int line);

/* string manipulation prototypes */
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strdup(const char *str);
void lineString(int n);

/* list manipulation prototypes */
paths *c_pathList(paths **head, char *path);
void newNode(paths **head, const char *arg);
paths *last_node(paths *head);
void freeList(paths *head);
int errManager(char *filename, char *grindvalue, int line);
int errManager2(char *filename, char *grindvalue, int line, int free,
		paths **head);

#endif /* SHELL_H */
