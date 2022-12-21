#include "shell.h"

/**
 * h_start - Function
 * @argv: Argument vector
 *
 * Description: Launches the shell program.
 * Return: EXIT_SUCCESS.
 * On error, EXIT_FAILURE.
 */

int h_start(char **argv)
{
	pid_t proc;

	signal(SIGINT, sig_hand);
	proc = fork();
	/* Edge case: fork() fails */
	if (proc < 0)
		perror("Error");
	else if (proc == 0)
	{
		/* Handle execution and edge case outright */
		if (execve(argv[0], argv, environ) == -1)
			perror("Error");
		exit(EXIT_FAILURE);
	} else
		wait(NULL);

	return (1);
}

/**
 * exe_cmd - Function
 * @argv: Argument vector
 *
 * Description: Executes the commands given.
 * Return: h_start(argv).
 * On error, stderr.
 */

int exe_cmd(char **argv)
{
	if (argv[0] == NULL)
		return (1);

	return (h_start(argv));
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
	char *cmd, **argv;
	int status;

	do {
		if (isatty(STDIN_FILENO))
			printf("abby@brian:-$ ");
		cmd = read_cmd();
		argv = split_cmd(cmd);
		status = exe_cmd(argv);

		free(cmd);
		free(argv);
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
	(void)ac, (void)av;
	prompt();

	return (EXIT_SUCCESS);
}
