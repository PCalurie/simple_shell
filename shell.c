#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

#define MAX_INPUT_LENGTH 80
/**
 * display_prompt - displays prompt on shell
 */
void display_prompt(void)
{
	printf("simple_shell> ");
}
/**
 * remove_newline - removes new lines
 * @str: pointer to the string
 */
void remove_newline(char *str)
{
	str[strcspn(str, "\n")] = '\0';
}
/**
 * exitShell - exit the shell
 * @exitStatus: status when exiting shell
 */
void exitShell(int exitStatus)
{
	printf("exiting...%d\n", exitStatus);
	exit(exitStatus);
}
/**
 * processCommand - process command
 * @command: command to process
 */
void processCommand(char *command)
{
	char *token;

	token = strtok(command, ";");

	while (token != NULL)
	{
		execute_command(token);
		token = strtok(NULL, ";");
	}

}

/**
 * main - main function
 * @argc: argument count
 * @argv: number of arguments
 * Return: 0 for success
 */

int main(int argc, char *argv[])
{
	char input[MAX_INPUT_LENGTH];
	int exitStatus;

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
			remove_newline(input);
			execute_command(input);
		}


		fclose(file);
	}
	else
	{
		/* Interactive mode - read commands from the user */
		while (1)
		{
			display_prompt();

			if (fgets(input, sizeof(input), stdin) == NULL)
				break;
			
			handle_comments(input);

			remove_newline(input);

			if (strcmp(input, "exit") == 0)
			{
				printf("Exiting the shell...\n");
				exitShell(0);
			} else if (strncmp(input, "exit ", 5) == 0)
			{
				exitStatus = atoi(input + 5);
				printf("Exiting, status: %d\n", exitStatus);
				exit(exitStatus);
			}
			else
			{
				processCommand(input);
			}
		}
	}

	return (EXIT_SUCCESS);
}
