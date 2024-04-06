#include "monty.h"
/**
 * main - runs the programs
 * @ac: number of arguement
 * @av: string storing buffer
 * Return: true
*/
int main(int ac, char **av)
{
	char *buffer = NULL;
	size_t size = 1024;
	int characters = 0;
	stack_t *head = NULL, *temp;
	void (*find_function(char *string))(stack_t **stack, unsigned int line_number);

	(void)av;
	if (ac < 2)/*if there is less then two arguements don't run*/
	{
		buffer = malloc(sizeof(char) * size);/*malloc here so it's easier to keep track of*/
		if (buffer == NULL)
		{
			free(buffer);
			return (0);
		}
		while (1)/*infinite loop*/
		{
			characters = getline(&buffer, &size, stdin);
			if (characters == EOF)/*exit when EOF reached*/
			{
				while (head != NULL)
				{
					temp = head;
					head = head->next;
					free(temp);
				}
				free(buffer);
				return (0);
			}
			(find_function(strtok(buffer, " $\n")))(&head, atoi(strtok(NULL, " $\n")));/*plugs in function*/
		}
	}
	return (0);
}

/**
 * find_function - finds a function based of input
 * @string: matches this string
 * Return: pointer function
*/
void (*find_function(char *string))(stack_t **stack, unsigned int line_number)
{
	int number = 0;
	instruction_t fab[] = {
		{"push", push},
		{"pall", pall}
	};

	while (number < 2)/*loops through the struct to match strings*/
	{
		if (strcmp(string, fab[number].opcode) == 0)
			return (fab[number].f);
		number++;
	}
	return (NULL);
}
