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
	if (sig == SIGINT)
	{
		printf("\n");
		write(STDOUT_FILENO, "abby@brian:-$ ", 15);
		fflush(stdout);
	}
}
