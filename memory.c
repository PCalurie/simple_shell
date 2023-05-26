#include "shell.h"

/**
 * bfree - freesa pointer
 * @ptr: address of the pointer to be freed
 * Return: 1 if freed and 0 otherwise.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
