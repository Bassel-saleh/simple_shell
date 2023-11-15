#include <stdio.h>

/**
 * myAtoi - Convert a string to an integer.
 * @str: The input string.
 *
 * Return: The converted integer.
 */
int _atoi(const char *str)
{
	int result = 0;
	int sign = 1;

	while (*str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		sign = (*str == '-') ? -1 : 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (sign * result);
}
