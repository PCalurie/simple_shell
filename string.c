#include "shell.h"

/**
 * _strlen - function returns the length of a str
 * @s: pointer to the str whose length to check
 * Return: length of string
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _strcmp - function performs lexicogarphic comparison of two str.
 * @s1: pointer to the first str
 * @s2: pointer to the second str
 * Return: negative if str1 < str2, positive if str1 > str2, zero if str1 == str2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - function checks if the needle starts with haystack
 * @haystack: poiter to the string to search for
 * @needle: pointer to the substring to find
 * Return: address to the next char of haystack or NULL on error
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - str concatenates two str
 * @dest: pointer to the destination buffer
 * @src: pointer to the source buffer
 * Return: pointer to dest buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
