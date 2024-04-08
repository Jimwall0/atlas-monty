#include "monty.h"
/**
 * free_all - frees every malloc
*/
void free_all(stack_t **head)
{
	stack_t *temp = *head;
	while (*head != NULL)
	{
		temp = *head;
		(*head) = (*head)->next;
		free(temp);
	}
}