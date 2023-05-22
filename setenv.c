#include "shell.h"
/**
 * execute_setenv - handles the setenv command
 * @num_args: number of arguments
 * @args: array of arguments
 */
void execute_setenv(int num_args, char **args)
{
	const char *name = args[1];
	const char *value;

	if (num_args < 2)
	{
		fprintf(stderr, "setenv: Too few arguments\n");
	}
	else if (num_args > 3)
	{
		fprintf(stderr, "setenv: Too many arguments\n");
	}
	else
	{
		value = (num_args == 3) ? args[2] : "";

		if (setenv(name, value, 1) != 0)
		{
			fprintf(stderr, "setenv: Failed to set environment variable\n");
		}
	}
}
