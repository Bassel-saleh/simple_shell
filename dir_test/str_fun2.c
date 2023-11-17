#include "shell.h"
/**
 * _strncpy - copying characters from one string to another
 * @dest: is the destination
 * @src: is the string to be copied
 * @n: is the maximum number of bytes to be copied
 * Return: void
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, h;

	h = 0;
	while (dest[h] != '\0')
	{
		h++;
	}
	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}

	return (dest);
}

/**
 * _strncat - append src string to dest string
 * @src: is the string to be appended onto dest
 * @dest: is the string appended on
 * @n: is the number of characters to be appended
 * Return: void
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, h;

	h = 0;
	i = 0;
	while (dest[i] != '\0')
	{
		i++;
		h++;
	}
	for (i = 0; src[i] != '\0' && i < n; i++)
	{
		dest[i + h] = src[i];
	}
	dest[i + h] = '\0';
	return (dest);
}

/**
 * _strchr - locates a character in a string
 * @s: the string to be checked
 * @c: the character being located
 * Return: if c is located return c else return null
 */
char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		s++;
		if (*s == c)
		{
			return (s);
		}
	}
	return (0);
}

/**
 * _putchar - print char
 * @c: the character to be printed
 * Return: the character
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - prints any string
 * @s: the string to be printed
 * Return: VOID
 */
void _puts(char *s)
{
	int i = 0;

	if (!s)
		return;
	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}
}
