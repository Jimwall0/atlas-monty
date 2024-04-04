#include "main.h"
/**
 * user_input - gets the user input
 * 
*/
int user_input(int num, char **buffer, size_t size)
{
	int character = NULL, loop = 0;
	char **stringpt = NULL, *pt;

	stringpt = malloc(sizeof(char *));
	while (1)
	{
		character = getline(&buffer, &size, stdin);/*gets the input from file until EOF*/
		if (character == -1)
		{
			perror("Error: getline\n");
			exit(1);
		}	
		pt = strtok(buffer);/*token it*/
	}
	return (pt);
}
