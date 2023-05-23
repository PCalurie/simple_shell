#include "shell.h"

/**
 * processSubCommand - process multiple cmds
 * @subCommand: sub commands
 */

void processSubCommand(char *subCommand)
{
	char *andToken;
	char *orToken;
	int result = 1;
	int exitStatus = 0;

	andToken = strtok(subCommand, "&&");

	while (andToken != NULL)
	{
		orToken = strtok(andToken, "||");

		while (orToken != NULL)
		{
			execute_command(orToken);

			if (result && exitStatus != 0)
			{
				result = 0;
			}

			orToken = strtok(NULL, "||");
		}

		if (!result)
		{
			break;
		}

		andToken = strtok(NULL, "&&");
	}
}
