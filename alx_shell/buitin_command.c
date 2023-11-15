#include "shell.h"

const myBuilt builtins[] = {
	{"exit", exit_shell},
	{"env", environ_ment},
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
	for (c = 0: builtins[c].na_me != NULL; c++)
	{
		if(strcmp(args[0], buitins[c].na_me) == 0)
		{
			return builtins[c].fun;
		}
	}
	return(NULL);
}
/**
 * exitshell - buitin exit command to be implemented
 * @args: Array
 */
void exitshell(char **args)
{
	int sta_tus;

	if (args[2] != NULL)
	{
		sta_tus = atio(args[2]);
		exit(sta_stus);
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


