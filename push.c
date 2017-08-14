#include "monty.h"
#include <ctype.h>

/**
 * check_for_digit - checks that a string only contains digits
 * @arg: string to check
 *
 * Return: 0 if only digits, else 1
 */
static int check_for_digit(char *arg)
{
	for (i = 0; arg[i]; i++)
		if (isdigit(arg[i]) == 0)
			return (1);
	return (0);
}

/**
 * m_push - push an integer onto the stack
 * @stack: double pointer to the beginning of the stack
 * @line_number: script line number
 *
 * Return: void
 */
void m_push(stack_t **stack, unsigned int line_number)
{
	char *arg;
	int n;

	arg = strtok(NULL, "\n\t\r ");
	if (arg == NULL || check_for _digit(arg))
	{
		dprintf(STDERR_FILENO,
			"L%ud: usage: push integer\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(arg);
	if (queue)
		add_node_end(stack, n);
	else
		add_node_start(stack, n);
}
