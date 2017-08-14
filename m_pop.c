#include "monty.h"

/**
 * m_pop - pop top element off of `stack'
 * @stack: double pointer to head of stack
 * @line_number: line number of current operation
 *
 * Return: void
 */
void m_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *pop = *stack;

	if (pop == NULL)
	{
		dprintf(STDERR_FILENO,
			"L%ud: can't pop an empty stack\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next != NULL)
		(*stack)->next->prev = NULL;
	(*stack) = (*stack)->next;
	free(pop);
}
