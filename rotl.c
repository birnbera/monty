#include "monty.h"

/**
 * rotl - rotates the stack to the top.
 * @stack:double pointer tot he begining of the linked list
 * @line_number: script line number
 *
 * Return: void
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *end = *stack;

	(void)line_number;
	if (var.stack_len > 1)
	{
		while (end->next != NULL)
			end = end->next;
		end->next = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		(end->next)->prev = end;
		(end->next)->next = NULL;
	}
}
