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
	char *cmd = argv[0];
	int status;
	pid_t proc;

	signal(SIGINT, sig_hand);
	proc = fork();
	/* Edge case: fork() fails */
	if (proc < 0)
		perror("hsh");
	if (proc == 0)
	{
		/* Eliminate the long path */
		if (cmd[0] == '/' || cmd[0] == '.')
			cmd = argv[0];
		else
			cmd = _path(cmd);
		/* Edge case: cmd is NULL */
		if (!cmd)
		{
			perror("hsh");
			exit(EXIT_FAILURE);
		}
		/* Handle execution and edge case outright */
		if (execve(argv[0], argv, NULL) == -1)
			perror("hsh");
		exit(EXIT_FAILURE);
	}
	else
	{
		do {
			waitpid(proc, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (0);
}

/**
 * main - Function
 *
 * Description: Displays the prompt, gets the command,
 * parses it and executes it, infinitely.
 * Return: void.
 * On error, stderr.
 */

int main(void)
{
	char *cmd, **argv;
	int status;

	do {
		if (isatty(STDIN_FILENO))
			printf("abby@brian:-$ ");
		cmd = read_cmd();
		argv = split_cmd(cmd);
		status = h_start(argv);

		if (_strcmp(cmd, "exit") == 0)
			exit(EXIT_SUCCESS);
		if (_strcmp(cmd, "env") == 0)
		{
			_printenv();
			continue;
		}

		if (argv == NULL)
		{
			free(cmd);
			continue;
		}
		free(cmd);
		free(argv);
		if (h_start(argv) == 0)
			status = 1;
		else
			status = 0;
	} while (status);

	return (0);
}
