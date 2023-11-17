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
 * execute_external_command - Execute an external command
 * @command: The command to execute
 */
void execute_external_command(char *command)
{
	char *args[2];
	int status;
	pid_t pid = fork();

	args[0] = command;
	args[1] = NULL;
	if (pid < 0)
		_puts("Fork error\n");
	else if (pid == 0)
	{
		execve(command, args, NULL);
		perror(command);
		exit(EXIT_FAILURE);
	}
	else
		waitpid(pid, &status, 0);
}

/**
 * execute_command - Execute a given command
 * @command: The command to execute
 */
void execute_command(char *command)
{
	char *path = "/bin", *full_path;
	size_t full_path_size;
	pid_t pid;

	(void)pid;
	if (command[0] == '/')
		execute_external_command(command);
	else
	{
		full_path_size = _strlen(path) + _strlen(command) + 2;
		full_path = (char *)malloc(full_path_size);
		if (full_path == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		_strcpy(full_path, path);
		_strcat(full_path, "/");
		_strcat(full_path, command);
		execute_external_command(full_path);
		free(full_path);
	}
}

/**
 * main - Entry point of the shell
 * Return: Always 0
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH], *token;
	int bytesRead;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			_puts("$ ");
		bytesRead = read(STDIN_FILENO, command, sizeof(command));
		if (bytesRead < 0)
		{
			perror("read");
			exit(EXIT_FAILURE);
		}
		if (bytesRead == 0)
		{
			_putchar('\n');
			break;
		}
		command[bytesRead] = '\0';
		token = strtok(command, "\n");
		while (token != NULL)
		{
			if (_strcmp(token, "exit") == 0)
				handle_exit();
			else if (_strcmp(token, "env") == 0)
				handle_env();
			else
				execute_command(token);
			token = strtok(NULL, "\n");
		}
	}
	return (0);
}

