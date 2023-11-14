#include "shell.h"
/**
 * _executeCommand - handles arguments
 * @command: a command
 * @args: arguments
 * @envp: explanation
 *
 * Return: 0 successful or -1 if it fail.
 */ 

void _executeCommand(char *command, char *args[], char *envp[])
		{
		pid_t _pid = fork;
		if (_pid == -1)
		{
		perror("fork");
		return (1);
		}
		else if(pid == 0)
		{
		execve(command, args, envp);
		perror("execve");
		return (1);
		}
		else
		{
		wait(NULL);
		}

		int main()
		{
		char *command = comma;
		char *args[] = _args;
		char *envp[] = _envp;

		comma = "/bin/ls";
	       _args = {comma, "-l", NULL};
       _envp = {NULL};

return (0);
		}
