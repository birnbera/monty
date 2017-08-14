#include "monty.h"

/**
 * free_lineptr - free line pointer returned by getline
 * @status: exit status
 * @arg: pointer to line
 *
 * Return: void
 */
void free_lineptr(int status, void *arg)
{
	(void)status;
	if (arg != NULL)
		free(arg);
}
