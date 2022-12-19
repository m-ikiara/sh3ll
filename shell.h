#ifndef SIMPLE_H
#define SIMPLE_H

#define _GNU_SOURCE

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

/* Declare the environ variable */
extern char **environ;

/* Prototypes */
void sig_hand(int);

#endif
