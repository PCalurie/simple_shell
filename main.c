#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"
#define MAX_INPUT_LENGTH 80
/**
 * main - the main function
 * @argc: number of arguments
 * @argv: arguments
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	char input[MAX_INPUT_LENGTH];

	if (argc > 1)
	{
/* File mode - read commands from a file */
		FILE *file = fopen(argv[1], "r");

		if (file == NULL)
		{
			fprintf(stderr, "Error opening file: %s\n", argv[1]);
			return (EXIT_FAILURE);
		}

		while (fgets(input, sizeof(input), file))
		{
			/* Remove newline character from input */
			input[strcspn(input, "\n")] = '\0';

			/* Execute the command */
			execute_command(input);
		}

		fclose(file);
	}
	else
	{
		/* Interactive mode - read commands from the user */
		while (1)
		{
			printf("simple_shell> ");

			if (fgets(input, sizeof(input), stdin) == NULL)
				break;

			/* Remove newline character from input */
			input[strcspn(input, "\n")] = '\0';

			/* Execute the command */
			execute_command(input);
		}
	}

	return (EXIT_SUCCESS);
}
