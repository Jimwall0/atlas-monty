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
		for (loop = 0; loop < 2; loop++)
		{
			array[loop] = pt;
			pt = strtok(NULL, "$ \n");
			printf("%s\n", array[loop]);
		}
	}
	return (0);
}
