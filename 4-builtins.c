#include "shell.h"



/**
 * h_cd - Function
 * @argv: Argument vector
 *
 * Description: Implements the shell builtin cd.
 * Return: EXIT_SUCCESS.
 * On error, 1 & stderr.
 */

int h_cd(char **argv)
{
	/* Edge case: No args for cd */
	if (argv[1] == NULL)
		printf("Error");
	else
	{
		/* Handles error and changes the directory using the chdir() syscall */
		if (chdir(argv[1]) != 0)
			perror("Error");
	}

	return (1);
}

/**
 * h_exit - Function
 * @argv: Argument vector
 *
 * Description: Implements the shell builtin exit.
 * Return: 0.
 * On error, stderr.
 */

int h_exit(char **argv)
{
	return (0);
}
