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

/* prototypes */
void selector(char *s);
void assignValues (char **ptr, char *s, int cont);
int st_contador (char *string);
void exe(char **string);
void c_buffer (int count, char *st);

#endif /* SHELL_H */
