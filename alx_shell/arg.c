#include "shell.h"
/**
 * main - Entry point
 * @argc: Argument
 * @argv: it is also an an argument
 *Return: 0
 */

int main(int argc, char *argv[])
{
	char buff[1024];
	int len = sprintf(buff, "Num of args:%d\n", argc);
	int c = 0;

	write(STDOUT_FILENO, buff, len);
	while (c < argc)
	{
		len = sprintf(buff, "Args %d: %s\n", c, argv[c]);
		write(STDOUT_FILENO, buff, len);
		c++;

}
return(0);
}
