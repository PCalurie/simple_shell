#include "shell.h"

/**
 **_memset - the function fills mem with a const byte
 *@s: pointer to the mem
 *@b: bytes to fill *s
 *@n: amnt of bytes to use
 *Return: *s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * ffree - the function frees a str of strings
 * @pp: the address to the poiter strg of strings
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc - function that reallocates a block of mem
 * @ptr: pointer to the prev mallocated block
 * @old_size: byte size of the prev block
 * @new_size: byte size of the new block
 * Return: a pointer to the old block name.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
