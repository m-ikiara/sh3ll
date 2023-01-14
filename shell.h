#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

/* Environ global variable */
extern char **environ;
/* Function Prototypes */
char *readline(void);
char **splitline(char *);
int execute(char **);
char *get_path(char *);
char *_strcat(char *, char *);
char **tokenize_env(char *);
int _strcmp(char *, char *);
void sig_handler(int);
int _putchar(char);
char *_getenv(char *);
void _printenv(void);
int _strlen(char *);
int _strncmp(char *, char *, int n);

#endif /* SHELL_H */
