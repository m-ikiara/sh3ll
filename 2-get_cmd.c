#include "shell.h"

/**
 * read_cmd - Function
 *
 * Description: Gets the command after the prompt.
 * Return: cmd, the command.
 * On error, stderr.
 */

char *read_cmd(void)
{
	char *cmd = NULL;
	size_t n = 0;
	int len = getline(&cmd, &n, stdin);

	/* Handle edge case and getline in one fell swoop */
	if (len == -1)
	{
		/* Handle EOF and error while getting command */
		if (feof(stdin))
		{
			printf("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("read_cmd");
			exit(EXIT_FAILURE);
		}
		free(cmd);
	}
	if (cmd[len - 1] == '\n')
		cmd[len - 1] = '\0';

	return (cmd);
}

/**
 * split_cmd - Function
 * @cmd: Command
 *
 * Description: Tokenizes the string and prepares it for
 * execution. In short, it parses it.
 * Return: cmd_tok, the tokenized command.
 * On error, stderr.
 */

char **split_cmd(char *cmd)
{
	int n = BUFFSIZE, i = 0;
	char *tok = strtok(cmd, DELIM), **cmd_tok = malloc(sizeof(char) * n);

	/* Edge case: cmd_tok is NULL */
	if (!cmd_tok)
	{
		perror("hsh");
		exit(EXIT_FAILURE);
	}
	/* Traverse tok */
	while (tok != NULL)
	{
		cmd_tok[i] = tok;
		tok = strtok(NULL, DELIM);
		i++;
	}
	/* Change value at end of cmd_tok to NULL */
	cmd_tok[i] = NULL;

	return (cmd_tok);
}
