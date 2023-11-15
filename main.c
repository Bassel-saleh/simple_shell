#include "shell.h"

/**
 * handle_exit - Handle the "exit" command
 */
void handle_exit(void)
{
	_puts("\n");
	exit(EXIT_SUCCESS);
}

/**
 * handle_env - Handle the "env" command
 */
void handle_env(void)
{
	char **env = environ;

	while (*env)
	{
		_puts(*env);
		_puts("\n");
		env++;
	}
}

/**
 * execute_command - Execute a given command
 * @command: The command to execute
 */
void execute_command(char *command)
{
	char *path = "/bin", *full_path, *args[2];
	size_t full_path_size;
	int status;

	if (command[0] == '/')
	{
		args[0] = command;
		args[1] = NULL;
		execve(command, args, NULL);
		perror(command);
		exit(EXIT_FAILURE);
	}
	else
	{
		pid_t pid = fork();

		if (pid < 0)
		{
			_puts("Fork error\n");
		}
		else if (pid == 0)
		{
			full_path_size = _strlen(path) + _strlen(command) + 2;
			full_path = (char *)malloc(full_path_size);
			_strcpy(full_path, path);
			_strcat(full_path, "/");
			_strcat(full_path, command);
			args[0] = command;
			args[1] = NULL;
			execve(full_path, args, NULL);
			free(full_path);
			/*_puts(command);*/
			/*_puts(": command not found\n");*/
			_puts("./shell: No such file or directory\n");
			exit(EXIT_FAILURE);
		}
		else
			waitpid(pid, &status, 0);
	}
}

/**
 * main - Entry point of the shell
 * Return: Always 0
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	int bytesRead;

	while (1)
	{
		_puts("$ ");
		bytesRead = read(STDIN_FILENO, command, sizeof(command));
		if (bytesRead <= 0)
		{
			_putchar('\n');
			break;
		}
		command[bytesRead - 1] = '\0';
		if (_strcmp(command, "exit") == 0)
			handle_exit();
		else if (_strcmp(command, "env") == 0)
			handle_env();
		else
			execute_command(command);
	}
	return (0);
}
