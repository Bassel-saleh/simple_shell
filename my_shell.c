#include "shell.h"

/**
 * c_shell - main shell loop
 * @info: the parameter & return info struct
 * @av: the argument vector from main()
 *
 * Return: 0 on success, 1 on error, or error code
 */
int c_shell(info_t *info, char **av)
{
	ssize_t r = 0;
	int builtin_ret = 0;

	while (r != -1 && builtin_ret != -2)
	{
		c_c_info(info);
		if (interactive(info))
			_puts("$ ");
		e_putchar(BUF_FLUSH);
		r = ginput(info);
		if (r != -1)
		{
			s_c_info(info, av);
			builtin_ret = f_builtin(info);
			if (builtin_ret == -1)
				f_cmd(info);
		}
		else if (interactive(info))
			_putchar('\n');
		f_c_info(info, 0);
	}
	write_a_history(info);
	f_c_info(info, 1);
	if (!interactive(info) && info->status)
		exit(info->status);
	if (builtin_ret == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (builtin_ret);
}

/**
 * f_builtin - finds a builtin command
 * @info: the parameter & return info struct
 *
 * Return: -1 if builtin not found,
 *			0 if builtin executed successfully,
 *			1 if builtin found but not successful,
 *			-2 if builtin signals exit()
 */
int f_builtin(info_t *info)
{
	int i, built_in_ret = -1;
	builtin_table builtintbl[] = {
		{"exit", c_exit},
		{"env", my_c_env},
		{"help", c_help},
		{"history", c_history},
		{"setenv", my_c_setenv},
		{"unsetenv", my_c_unsetenv},
		{"cd", c_cd},
		{"alias", c_alias},
		{NULL, NULL}
	};

	for (i = 0; builtintbl[i].type; i++)
		if (_strcmp(info->argv[0], builtintbl[i].type) == 0)
		{
			info->line_count++;
			built_in_ret = builtintbl[i].func(info);
			break;
		}
	return (built_in_ret);
}

/**
 * f_cmd - finds a command in PATH
 * @info: the parameter & return info struct
 *
 * Return: void
 */
void f_cmd(info_t *info)
{
	char *path = NULL;
	int i, k;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (i = 0, k = 0; info->arg[i]; i++)
		if (!is_delim(info->arg[i], " \t\n"))
			k++;
	if (!k)
		return;
	path = find_dir(info, my_c_genv(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		c_fork(info);
	}
	else
	{
		if ((interactive(info) || my_c_genv(info, "PATH=")
			|| info->argv[0][0] == '/') && c_iscmd(info, info->argv[0]))
			c_fork(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			prnt_err(info, "not found\n");
		}
	}
}

/**
 * c_fork - forks a an exec thread to run cmd
 * @info: the parameter & return info struct
 *
 * Return: void
 */
void c_fork(info_t *info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info->path, info->argv, get_environ(info)) == -1)
		{
			f_c_info(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				prnt_err(info, "Permission denied\n");
		}
	}
}
