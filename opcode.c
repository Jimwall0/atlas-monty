#include "main.h"
/**
 * push - pushes onto the stack
 * @stack: stack
 * @line_number: integer data
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *node = NULL;

	node = malloc(sizeof(stack_t));/*mallocs size*/
	if (node == NULL)
	{
		free(node);
		perror("Error: push\n");
		exit(1);
	}
	node->n = line_number;/*sets the n variable*/
	if (*stack == NULL)/*if empty set to head*/
	{
		*stack = node;
	}
	else/*stack ontop*/
	{
		node->next = *stack;
		(*stack)->prev = node;
		*stack = node;
	}
}