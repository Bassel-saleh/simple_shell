#include "shell.h"
/**
 * main - Entry point
 * Explanation
 * Return: 0
 */

int main(void)
{
	char len[MAX_COMMAND_LENGTH];
	char *ar_gv[MAX_AR_GS];
	int ar_gc;

	len[0] = 'J';
	ar_gv[0] = "Our";
while (1)
{
	write(STDOUT_FILENO, "$", 3);
	if  (fgets(len, sizeof(len), stdin) == NULL)
		break;

	len[strspn(len, "\n")] = '\0';

	ar_gc = 0;

	ar_gv[ar_gc] = strtok(len, " ");
while (ar_gv[ar_gc] != NULL && ar_gc < MAX_AR_GS - 2)
{

	ar_gc++;

	ar_gv[ar_gc] = strtok(NULL, " ");
}
ar_gv[ar_gc] = NULL;

if (ar_gc > 0)
{
	pid_t p_i_d = fork();

if (p_i_d < 0)
{
	perror("./hsh");

	exit(EXIT_FAILURE);
}

if (p_i_d == 0)
{

	execvp(ar_gv[0], ar_gv);

	perror(ar_gv[0]);

	exit(EXIT_FAILURE);
}
else
{

	int pro;

	waitpid(p_i_d, &pro, 0);
}
}
}
write(STDOUT_FILENO, "\n", 2);
return (0);
}

