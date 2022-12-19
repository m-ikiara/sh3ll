#include "shell.h"

/**
 * sig_hand - Function
 * @sig: Signal
 *
 * Description: Handles the interrupt(Ctrl-C) signal.
 * Return: void.
 * On error, stderr.
 */

void sig_hand(int sig)
{
	if (EOF)
	{
		printf("\nExit\nSession terminated\n");
		exit(EXIT_SUCCESS);
	}
	if (sig == SIGINT)
	{
		printf("\nExit\nSession interrupted\n");
		exit(EXIT_SUCCESS);
	}
	exit(0);
}
