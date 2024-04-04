#include "main.h"
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
