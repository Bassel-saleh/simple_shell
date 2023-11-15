#include "shell.h"

const myBuilt builtins[] = {
	{"exit", exitshell},
	{"env", environment},
	{NULL, NULL}
};
/**
 * check_build - Check function
 * @args: Array
 * Return: 0
 */
builtin_function check_buid(char **args)
{
	int c;
	const char *l;

	for (c = 0; builtins[c].na_me != NULL; c++)
	{
		l = builtins[c].na_me;
		if (_strcmp(args[0], (char *)l) == 0)
		{
			return (builtins[c].fun);
		}
	}
	return (NULL);
}
/**
 * exitshell - buitin exit command to be implemented
 * @args: Array
 */
void exitshell(char **args)
{
	char stat;

	if (args[1] != NULL)
	{
		stat = atoi(args[1]);
		exit(stat);
	}
	exit(0);
}
/**
 * environment - builtin env command to be implemented
 * @args: Array
 */
void environment(char **args)
{
	char **env;
	size_t numlen;

	(void)args;

	for (env = environ; *env != NULL; env++)
	{
		numlen = strlen(*env);
		write(STDOUT_FILENO, *env, numlen);
		write(STDOUT_FILENO, "\n", 1);
	}
}


