#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define TOKEN_BUFFER 64
#define TOKEN_DELIM  " \n\t\r\a"

typedef struct {
    char *cmd;
    int (*builtin_function) (char **);
} Builtins;

bool sh3ll_exit(char **args);

Builtins builtins[1] = {
    {
        .cmd = "exit",
        .builtin_function = &sh3ll_exit
    }
};
bool status = true;

char *sh3ll_read_line();
char **sh3ll_tokenize(char *line);

void
print_tokens(char **args)
{
    printf("--------------------------------------------------------------\n");
    for (size_t i = 0; i < (sizeof(args) / sizeof(int)); ++i) 
        printf("[INFO] Printing Token %zu: %s\n", i, args[i]);
    printf("--------------------------------------------------------------\n");
}

bool sh3ll_launch_process(char **args);
bool sh3ll_execute(char **args);

int
enumerate_builtins()
{
    return (int) sizeof(builtins) / sizeof(Builtins *);
}

bool
sh3ll_exit(char **args)
{
    (void) args;
    return true;
}

#endif // !_SHELL_H_
