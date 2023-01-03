#include "shell.h"

/**
 * _strlen - Function
 * @s: String
 *
 * Description: Returns length of a string.
 * Return: len, length of string.
 * On error, stderr.
 */

int _strlen(char *s)
{
	int len;

	/* Edge case: s is NULL */
	if (s == NULL)
		exit(EXIT_FAILURE);
	/* Traverse the string incrementing len with each iteration */
	for (len = 0; *s != '\0'; len++)
		s++;

	return (len);
}

/**
 * _strcat - Function
 * @dest: Destination
 * @src: Source
 *
 * Description: Concatenates 2 strings; adds the string src
 * to string dest.
 * Return: dest, the concatenated string.
 * On error, stderr.
 */

char *_strcat(char *dest, char *src)
{
	int i, len = 0;

	/* Edge case: Either src or dest is NULL */
	if (dest == NULL || src == NULL)
		exit(EXIT_FAILURE);
	/* Traverses dest until it reaches the NUL character */
	while (dest[len] != '\0')
		len++;
	/* Does the concatenation (i and len incremented in one line) */
	for (i = 0; src[i] != '\0'; i++, len++)
		dest[len] = src[i];
	/* Set the string terminator */
	dest[len] = '\0';

	return (dest);
}

/**
 * _strcmp - Function
 * @s1: First string
 * @s2: Second string
 *
 * Description: Compares 2 strings; returns the ASCII
 * difference of 2 strings.
 * Return: 0, if equal; cmp, the ASCII difference.
 * On error, stderr.
 */

int _strcmp(char *s1, char *s2)
{
	int i, cmp = 0;

	/* Traverse both strings */
	for (i = 0; s1[i] && s2[i]; i++)
	{
		/* Edge case: The characters match */
		if (s1[i] == s2[i])
			continue;
		else
			break;
	}
	/* Loop breaks and the ASCII difference is returned */
	cmp = s1[i] - s2[i];

	return (cmp);
}

/**
 * _strncmp - Function
 * @s1: First string
 * @s2: Second string
 * @n: Number of bytes
 *
 * Description: Compares 2 strings; returns the ASCII difference
 * of a certain number of bytes contained in both strings.
 * Return: 0, if equal; the ASCII difference, otherwise.
 * On error, stderr.
 */

int _strncmp(char *s1, char *s2, int n)
{
	/**
	 * Edge case: Both are equal
	 *
	 * Description: A ternary recursive call to _strncmp that
	 * traverses both strings, decrementing the number of bytes
	 * with each call and returning the ASCII difference of
	 * the characters in each call
	 */
	if (*s1 == *s2)
		return (*s1 ? _strncmp(s1 + 1, s2 + 1, n - 1) : 0);
	/* Edge case: s2 is NULL */
	if (*s1)
		return (1);
	/* Edge case: s1 is NULL */
	if (*s2)
		return (-1);

	/* The ASCII difference recursively returned */
	return (*s1 - *s2);
}
