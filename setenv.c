#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "shell.h"

/**
 * setenvShell - set env var
 * @variable: var to set
 * @value: value to set
 * Return: result
 */

int setenvShell(char *variable, char *value)
{
	int result = setenv(variable, value, 1);

	if (result == -1)
	{
		fprintf(stderr, "Failed to set env var.\n");
	}
	else
	{
		printf("Env var '%s' set to '%s'.\n", variable, value);
	}

	return (result);
}
