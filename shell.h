#ifndef SHELL_H
#define SHELL_H

#define _GNU_SOURCE
#define BUFFSIZE 1024
#define DELIM " \n\t"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stddef.h>
#include <signal.h>
#include <string.h>
#include <errno.h>

/* Declare environ */
extern char **environ;

/* For the signal */
void sig_hand(int);

/* For the strings */
int _strlen(char *);
char *_strcat(char *, char *);
int _strcmp(char *, char *);
int _strncmp(char *, char *, int);

/* For the commands */
char *read_cmd(void);
char **split_cmd(char *);
int exe_cmd(char **);

/* To handle matters of path */
char *_path(char *);
char *_getenv(char *);
char **path_tok(char *);
void _printenv(void);

#endif
