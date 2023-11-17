#include "shell.h"

/**
 * c_exit - exits the shell
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: exits with a given exit status
 *         (0) if info.argv[0] != "exit"
 */
int c_exit(info_t *info)
{
	int exitcheck;

	if (info->argv[1])
	{
		exitcheck = c_err_atoi(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			prnt_err(info, "Illegal number: ");
			e_put(info->argv[1]);
			e_putchar('\n');
			return (1);
		}
		info->err_num = c_err_atoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * c_cd - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int c_cd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = my_c_genv(info, "HOME=");
		if (!dir)
			chdir_ret =
				chdir((dir = my_c_genv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!my_c_genv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(my_c_genv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret =
			chdir((dir = my_c_genv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		prnt_err(info, "can't cd to ");
		e_put(info->argv[1]), e_putchar('\n');
	}
	else
	{
		_senv(info, "OLDPWD", my_c_genv(info, "PWD="));
		_senv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * c_help - changes current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype
 *  Return: NULL
 */
int c_help(info_t *info)
{
	char **arg_arr;

	arg_arr = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_arr);
	return (0);
}
