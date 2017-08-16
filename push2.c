#include "monty.h"

/**
 * m_push2 - push an integer onto the stack
 * @stack: double pointer to the beginning of the stack
 * @n: number to push
 *
 * Return: void
 */
void m_push2(stack_t **stack, int n)
{
	if (var.queue)
	{
		if (!add_node_end(stack, n))
		{
			dprintf(STDOUT_FILENO, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		var.stack_len++;
	}
	else
	{
		if (!add_node_start(stack, n))
		{
			dprintf(STDOUT_FILENO, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		var.stack_len++;
	}
}
