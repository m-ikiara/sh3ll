#include "shell.h"

/**
 * main - Function
 * @ac: Argument count
 * @av: Argument vector
 *
 * Description: The body of the shell hsh program.
 * Return: 0.
 * On error, stderr.
 */

int main(int ac, char *av[])
{
	while (1)
	{
		char *cmd;
		int stat;
		size_t n = 100;
		pid_t process = fork();

		(void)ac;
		(void)av;
		cmd = malloc(sizeof(char) * n);

		if (process == -1)
		{
			perror("fork()");
			return (1);
		}
		if (process == 0)
		{
			printf("($) ");
			getline(&cmd, &n, stdin);
			cmd = strtok(cmd, "\n");
			if (execve(cmd, av, environ) == -1)
			{
				perror("Error");
				return (1);
			}
			sleep(1);
		}
		wait(&stat);
	}
	return (0);
}
