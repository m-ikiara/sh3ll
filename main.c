#include "shell.h"

/**
  * main - The function that starts the shell
  *
  * Return: 1 on success
  */

int main(void)
{
	int status = 1;
	char *line;
	char **args;

	signal(SIGINT, sig_handler);
	while (status)
	{
		status = isatty(STDIN_FILENO);

		if (status == 1)
			write(STDOUT_FILENO, "$ ", 2);

		line = readline();
		if (!line)
		{
			return (0);
		}
		if (_strcmp(line, "exit") == 0)
		{
			free(line);
			return (0);
		}
		if (_strcmp(line, "env") == 0)
		{
			_printenv();
			free(line);
			continue;
		}
		args = splitline(line);
		if (args == NULL)
		{
			free(line);
			free(args);
			continue;
		}
		status = execute(args);
		free(line);
		free(args);
	}
	return (0);
}
