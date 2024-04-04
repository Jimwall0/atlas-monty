#include "main.h"
/**
 * main - runs the programs
 * Return: true
*/
int main(void)
{
	int number = 0, loop;
	char *buffer = NULL, *pt = NULL;
	size_t size = 1024;

	buffer = malloc(sizeof(char) * size);
	if (buffer == NULL)
	{
		perror("Error: malloc\n");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		number = getline(&buffer, &size, stdin);
		if (number == EOF)
			exit(0);
		pt = strtok(buffer, " \n");
		for (loop = 0; pt; loop++)
		{
			printf("%s\n", pt);
			pt = strtok(NULL, " \n");
		}
	}
	return (0);
}
