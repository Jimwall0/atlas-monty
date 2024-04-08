#include "monty.h"
/**
 * main - runs the programs
 * @ac: number of arguement
 * @av: string storing buffer
 * Return: true
*/
int main(int ac, char **av)
{
	char *buffer, *pt;
	int characters = 0;
	size_t size = 1024;
	stack_t *head = NULL;

	if (ac != 2)
	{
		perror("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	buffer = malloc(sizeof(char *));
	if (buffer == NULL)
	{
		free(buffer);
		perror("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (stat(stdin))
	{
		while (1)
		{
			characters = getline(&buffer, &size, stdin);
			if (characters == EOF)
				return (0);
			pt = strtok(buffer, " $\n");
			(getfunction())(&head, strtok(NULL, " $\n"));
		}
	}
	else
	{
		perror("Error: Can't open file\n");
		exit(EXIT_FAILURE);
	}
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
		{"pall", pall},
		{"", napp}
	};

	while (number < 2)/*loops through the struct to match strings*/
	{
		if (strcmp(string, fab[number].opcode) == 0)
			return (fab[number].f);
		number++;
	}
	return (fab[number].f);
}
