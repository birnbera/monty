#include "monty.h"

/**
 * rotr - rotates the stack to the bottom.
 * @stack: double pointer to the begining of the linked list
 * @line_number: script line number
 *
 * Return: void
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *end = *stack;

	(void)line_number;
	if (var.stack_len > 1)
	{
		while (end->next != NULL)
			end = end->next;
		end->next = *stack;
		(*stack)->prev = end;
		(end->prev)->next = NULL;
		end->prev = NULL;
		*stack = end;
	}
}
