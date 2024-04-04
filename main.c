#include "monty.h"
/**
 * main - runs the programs
 * Return: true
*/
int main(int ac, char **ac)
{
	int number = 0, loop;
	char *buffer = NULL, *pt = NULL, **array;
	size_t size = 1024;
	void (*f)(stack_t **stack, unsigned int line_number);

	(void)ac;
	(void)av;
	buffer = malloc(sizeof(char) * size);
	if (buffer == NULL)
	{
		perror("Error: malloc\n");
		free(buffer);
		exit(EXIT_FAILURE);
	}
	array = malloc(sizeof(char *));
	while (1)/*loops getting the input*/
	{
		number = getline(&buffer, &size, stdin);/*gets input from buffer*/
		if (number == EOF)
		{
			free(array);
			free(buffer);
			exit(0);
		}
		pt = strtok(buffer, "$ \n");/*splits of whitespace*/
		for (loop = 0; loop < 2; loop++)/*stores strtok into an array*/
		{
			array[loop] = pt;
			pt = strtok(NULL, "$ \n");
			find_function(array[0]);
		}
	}
	return (0);
}

/**
 * find_function - finds a function based of input
 * Return: pointer function
*/
void *find_function(char *string)
{
	int number = 0;
	instruction_t fab = {
		{"push", push};
		{"pull", pull};
	};

	while (number < 2)/*loops through the struct to match strings*/
	{
		if (strcmp(string, fab[number].opcode) == 0)
			return (fab[number].f);
		number++;
	}
	return(NULL);
}
