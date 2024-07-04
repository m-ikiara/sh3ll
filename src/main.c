#include "shell.h"

char *
sh3ll_readline()
{
    char *line = NULL;
    ssize_t buffer_size = 0;

    if (getline(&line, &buffer_size, stdin) == -1) {
        if (feof(stdin)) exit(EXIT_SUCCESS);
        else {
            fprintf(stderr, "[ERROR] Failed to read the line\n");
            exit(EXIT_FAILURE);
        }
    }    

    return line;
}

char **
sh3ll_tokenize(char *line)
{
    int buffer_size = TOKEN_BUFFER, position = 0;
    char **tokens = malloc(TOKEN_BUFFER * sizeof(char *)), *token = NULL;

    token = strtok(line, TOKEN_DELIM);
    for (position = 0; token; ++position) {
        tokens[position] = token;

        if (position >= TOKEN_BUFFER) {
            buffer_size += TOKEN_BUFFER;
            
            tokens = realloc(tokens, buffer_size * sizeof(char *));
            if (!tokens) {
                fprintf(stderr,
                        "[ERROR] Failed to reallocate memory to tokenizer\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, TOKEN_DELIM);
    }

    tokens[position] = NULL;

    return tokens;
}

bool
sh3ll_launch_process(char **args)
{
    pid_t pid = fork();

    if (pid == 0) {
        if (execvp(args[0], args) == -1)
            fprintf(stderr, "[ERROR] Failed to create a Child process\n");
        exit(EXIT_FAILURE);
    }
    if (pid < 0) fprintf(stderr, "[ERROR] Failed to link to sh3ll\n");
    
    return false;
}

bool
sh3ll_execute(char **args)
{

    if (!args) return false;

    for (int i = 0; i < enumerate_builtins(); ++i)
        if (strcmp(args[0], builtins[i].cmd) == 0)
            return builtins[i].builtin_function(args);

    return sh3ll_launch_process(args);
}

int
main(int argc, char **argv)
{
    (void) argc;

    if (argv) {
        do {
            printf("bigboy@sh3ll:~ $ ");
            
            char *line = sh3ll_readline();
            char **args = sh3ll_tokenize(line);
            print_tokens(args);

            status = sh3ll_execute(args);

            free(line);
            free(args);
        } while(status);
    }

    return 0;
}
