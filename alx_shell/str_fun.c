#include "shell.h"
/**
 * _strcmp - compares two strings
 * @s1: is the first string
 * @s2: is the second string
 * Return: void
 */
int _strcmp(char *s1, char *s2)
{
	int i, r;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0'))
	{
		i++;
	}
	r = s1[i] - s2[i];
	return (r);
}

/**
 * _strlen - calculates the length of a string
 * @s: is the character to be checked
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int a = 0;

	while (s[a] != '\0')
	{
		a++;
	}
	return (a);
}

/**
 * _strcat - append src string to dest string
 * @src: is the string to be appended onto dest
 * @dest: is the string appended on
 * Return: void
 */
char *_strcat(char *dest, char *src)
{
	int i, h;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	h = 0;
	while (src[h] != '\0')
	{
		dest[i] = src[h];
		h++;
		i++;
	}
	return (dest);
}

/**
 * *_strcpy - hat copies the string pointed to by src
 * @dest: is a pointer to the destination buffer
 * @src: is a pointer to the source string that you want to copy
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	int a = 0;

	while (src[a] != '\0')
	{
		dest[a] = src[a];
		a++;
	}
	dest[a] = '\0';
	return (dest);
}

/**
 * _strdup - returns a pointer to a newly allocated space in memory
 * @str: string
 * Return: pointer or NULL if insufficient memory
 */
char *_strdup(char *str)
{
	int len, i;
	char *strc;

	if (str == 0)
		return (0);
	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	strc = malloc((len + 1) * sizeof(char));
	if (strc == 0)
		return (0);
	for (i = 0; i <= len; i++)
	{
		strc[i] = str[i];
	}
	return (strc);
}
