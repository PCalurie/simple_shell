#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * unset_env_variable - remove set env var
 * @command: argument
 */

void unset_env_variable(char *command)
{
	char *trimmed_command = strdup(command);
	char *end = trimmed_command + strlen(trimmed_command) - 1;
	char *space_pos = strchr(trimmed_command, ' ');

	while (end > trimmed_command && (*end == ' ' || *end == '\t'))
		trimmed_command++;

	if (space_pos != NULL)
	{
		*space_pos = '\0';

		if (*trimmed_command != '\0')
		{
			if (unsetenv(trimmed_command) == -1)
			{
				fprintf(stderr, "Failed to unset env var: %s\n", trimmed_command);
			}
		}
		else
		{
			fprintf(stderr, "Invalid command format: unsetenv\n");
		}
	}
	else
	{
		fprintf(stderr, "Invalid command format: unsetenv\n");
	}

	free(trimmed_command);

}
