#include "monty.h"
/**
 * main - runs the programs
 * @ac: number of arguement
 * @av: string storing buffer
 * Return: true
*/
int main(int ac, char **av)
{
	char *buffer;
	int characters = 0;
	size_t size = 1024;
	stack_t *head = NULL;
	void (*find_function(char *string))(stack_t **stack, unsigned int line_number);

	if (ac != 2)
	{
		perror("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	buffer = malloc(sizeof(char) * size);
	if (buffer == NULL)
	{
		free(buffer);
		perror("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (access(av[1], R_OK & X_OK))
	{
		while (1)
		{
			characters = getline(&buffer, &size, stdin);
			if (characters == EOF)
				return (0);
			strtok(buffer, " $]n");
			if (atoi(strtok(NULL, " $\n")) == 0)
			{

			}
			(find_function(strtok(buffer, " $\n")))(&head, atoi(strtok(NULL, " $\n")));
		}
	}
	else
	{
		perror("Error: file access\n");
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
		{"shrug", napp}
	};

	while (number < 2)/*loops through the struct to match strings*/
	{
		if (strcmp(string, fab[number].opcode) == 0)
			return (fab[number].f);
		number++;
	}
	return (fab[number].f);
}
