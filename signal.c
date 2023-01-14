#include "shell.h"

/**
  * sig_handler -  Handles signal when user types ctrl + c
  * @signal: The signal
  *
  */

void sig_handler(int signal)
{
	(void)signal;
	printf("\n");
	write(STDOUT_FILENO, "abby@brian:-$ ", 15);
	fflush(stdout);
}
