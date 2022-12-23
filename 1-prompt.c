#include "shell.h"

/**
 * h_start - Function
 * @argv: Argument vector
 * @env: Environment vector
 *
 * Description: Launches the shell program.
 * Return: EXIT_SUCCESS.
 * On error, EXIT_FAILURE.
 */

int h_start(char **argv, char **env)
{
	int status;
	pid_t proc;

	env = environ;
	signal(SIGINT, sig_hand);
	proc = fork();
	/* Edge case: fork() fails */
	if (proc < 0)
		perror("Error");
	else if (proc == 0)
	{
		/* Handle execution and edge case outright */
		if (execve(argv[0], argv, env) == -1)
			perror("Error");
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
 * exe_cmd - Function
 * @argv: Argument vector
 * @env: Environment vector
 *
 * Description: Executes the commands given.
 * Return: h_start(argv).
 * On error, stderr.
 */

int exe_cmd(char **argv, char **env)
{
	if (argv[0] == NULL)
		return (1);

	return (h_start(argv, env));
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
	char *cmd, **argv, **cp_av, **env;
	int status;

	env = environ;
	do {
		if (isatty(STDIN_FILENO))
			printf("abby@brian:-$ ");
		cmd = read_cmd();
		argv = split_cmd(cmd);
		status = exe_cmd(argv, env);
		cp_av = argv;

		while (*argv)
		{
			if (strcmp(*argv, "exit") == 0)
				exit(EXIT_SUCCESS);
			argv++;
		}
		argv = cp_av;

		free(cmd);
		free(argv);

		if (h_start(argv, env) == 0)
			status = 1;
		else
			status = 0;
	} while (status);

	return (0);
}

/**
 * main - Function
 * @ac: Argument count
 * @av: Argument vector
 * @env: Environment vector
 *
 * Description: The body of the shell hsh program.
 * Return: 0.
 * On error, stderr.
 */

int main(int ac, char **av, char **env)
{
	/* Simplified and robust */
	(void)ac, (void)av, (void)env;
	prompt();

	return (EXIT_SUCCESS);
}
