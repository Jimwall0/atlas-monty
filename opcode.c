#include "monty.h"
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
		perror("Error: node malloc\n");
		exit(EXIT_FAILURE);
	}
	node->n = line_number;
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
/**
 * pall - prints all nodes
 * @stack: the stack of nodes
 * @line_number: the n data
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
 * napp - not a code
 * @stack: stack data
 * @line_number: the line number
*/
void napp(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
	perror("Error: unkown instruction\n");
}