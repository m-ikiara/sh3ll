#include "shell.h"

/**
 * _start - Function
 * @args: Argument vector
 *
 * Description: Launches the shell program.
 * Return: EXIT_SUCCESS.
 * On error, 1.
 */

int _start(char **args)
{
	pid_t proc;

	proc = fork();
	/* Edge case: fork() fails */
	if (fork < 0)
		perror("Error");
	else if (proc == 0)
	{
		/* Handle execution and edge case outright */
		if (execve(args[0], args, environ) == -1)
			perror("Error");
		exit(EXIT_FAILURE);
	}
	else
		wait(NULL);

	return (1);
}

/**
 * prompt - Function
 *
 * Description: Displays the prompt, gets the command,
 * parses it and executes it, infinitely.
 * Return: void.
 * On error, stderr.
 */

int prompt(void)
{
	char *cmd, **args;
	int status;

	do {
		printf("abby@brian:-$ ");
		cmd = read_cmd();
		args = split_cmd(cmd);
		status = exe_cmd(args);

		free(cmd);
		free(args);
	} while (status);

	return (0);
}

/**
 * main - Function
 * @ac: Argument count
 * @av: Argument vector
 *
 * Description: The body of the shell hsh program.
 * Return: 0.
 * On error, stderr.
 */

int main(int ac, char **av)
{
	/* Simplified and robust */
	prompt();

	return (EXIT_SUCCESS);
}
