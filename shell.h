#ifndef SIMPLE_H
#define SIMPLE_H

#define _GNU_SOURCE
#define BUFFSIZE 64
#define DELIM " \n\t"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stddef.h>
#include <signal.h>
#include <string.h>
#include <errno.h>

/* Declare environ */
extern char **environ;

/* Prototypes */
void sig_hand(int);
int prompt(void);
char *read_cmd(void);
char **split_cmd(char *);

#endif
