#include "shell.h"

/**
 * _path - Function
 * @cmd: Command
 *
 * Description: Gets full path of command.
 * Return: fp, the full path; NULL, otherwise.
 * On error, stderr.
 */

char *_path(char *cmd)
{
	struct stat st;
	char *p = _getenv("PATH"), *cmod = cmd;
	char **dir = path_tok(p), *fp = malloc(sizeof(char) * BUFFSIZE);
	int i;

	if (!fp)
		return (NULL);
	for (i = 0; dir[i]; i++)
	{
		fp[0] = 0;
		_strcat(fp, dir[i]);
		_strcat(fp, "/");
		_strcat(fp, cmod);
		if (stat(fp, &st) == 0)
			return (fp);
	}
	free(fp);

	return (NULL);
}

/**
 * _getenv - Function
 * @env: Environment variable
 *
 * Description: Fetches the environment variable requested
 * by user.
 * Return: environ[i] + len[i], the value of environment variable.
 * On error, stderr.
 */

char *_getenv(char *env)
{
	int i, len = _strlen(env);

	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(environ[i], env, len) == 0)
			return (environ[i] + len + 1);
	}

	return (NULL);
}

/**
 * path_tok - Function
 * @p: Path
 *
 * Description: Tokenizes the full path.
 * Return: dir, directory array.
 * On error, stderr.
 */

char **path_tok(char *p)
{
	char *cp = p, *tok;
	int i = 0;
	static char *dir[BUFFSIZE] = {NULL};

	if (p == NULL)
		return (NULL);
	tok = strtok(cp, ":");
	while (tok != NULL)
	{
		dir[i++] = tok;
		tok = strtok(NULL, ":");
	}

	return (dir);
}

/**
 * _printenv - Function
 *
 * Description: Implements printenv; prints all environment
 * variables.
 * Return: void.
 * On error, stderr.
 */

void _printenv(void)
{
	int i;

	for (i = 0; environ[i]; i++)
		printf("%s\n", environ[i]);
}
