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

	/* Handle edge case and getline in one fell swoop */
	if (getline(&cmd, &n, stdin) == -1)
	{
		/* Handle EOF and error while getting command */
		if (feof(stdin))
			exit(EXIT_SUCCESS);
		else
		{
			perror("read_cmd");
			exit(EXIT_FAILURE);
		}
	}

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
	char *tok, **cmd_tok = malloc(sizeof(char *) * n);

	/* Edge case I */
	if (cmd_tok == NULL)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	tok = strtok(cmd, DELIM);
	/* loop through cmd returning each token */
	while (tok)
	{
		cmd_tok[i] = tok;
		tok = strtok(NULL, DELIM);
		i++;
	}
	cmd_tok[i] = NULL;

	/* The parsed command is ready for execution */
	return (cmd_tok);
}
