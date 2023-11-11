#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

extern char **environ;
extern int _argc;
extern char **_argv;

#define MAX_COMMAND_LENGTH 128
#define BUFFER 1024
#define FLUSH -1
#define MAX_AR_GS 120
int main(void);
char *_strncpy(char *dest, char *src, int n);
char *_strncat(char *dest, char *src, int n);
char *_strchr(char *s, char c);
int _putchar(char c);
void _puts(char *s);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
void handle_exit(void);
void handle_env(void);
void execute_command(char *command);
int main(void);

#endif
