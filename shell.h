#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;

/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 *struct passinfo - contains pseudo-arguements to pass into a function,
 *					allowing uniform prototype for function pointer struct
 *@arg: string generated from getline containing arguements
 *@argv: array of strings generated from arg
 *@path: string path for the current command
 *@argc: argument count
 *@line_count: error count
 *@err_num: error code for exit()s
 *@linecount_flag: if on count line of input
 *@fname: program filename
 *@env: linked list local copy of environ
 *@environ: custom modified copy of environ from LL env
 *@history: the history node
 *@alias: alias node
 *@env_changed: on if environ was changed
 *@status: the return status of the last exec'd command
 *@cmd_buf: address of pointer to cmd_buf, on if chaining
 *@cmd_buf_type: CMD_type ||, &&, ;
 *@readfd: fd from which to read line input
 *@histcount: history line number count
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct builtin - contains a builtin string and related function
 *@type: the builtin command flag
 *@func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;


int c_shell(info_t *, char **);
int f_builtin(info_t *);
void f_cmd(info_t *);
void c_fork(info_t *);
int c_iscmd(info_t *, char *);
char *c_dupchars(char *, int, int);
char *find_dir(info_t *, char *, char *);
void e_put(char *);
int e_putchar(char);
int put_fd(char c, int fd);
int puts_fd(char *str, int fd);
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);
char **strtow(char *, char *);
char **strtow2(char *, char);
char *_mem_set(char *, char, unsigned int);
void f_free(char **);
void *_re_alloc(void *, unsigned int, unsigned int);
int be_free(void **);
int interactive(info_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);
int c_err_atoi(char *);
void prnt_err(info_t *, char *);
int c_prnt_d(int, int);
char *con_num(long int, int, int);
void rmv_cmnts(char *);
int c_exit(info_t *);
int c_cd(info_t *);
int c_help(info_t *);
int c_history(info_t *);
int c_alias(info_t *);
ssize_t ginput(info_t *);
int g_line(info_t *, char **, size_t *);
void sign_Handler(int);
void c_c_info(info_t *);
void s_c_info(info_t *, char **);
void f_c_info(info_t *, int);
char *my_c_genv(info_t *, const char *);
int my_c_env(info_t *);
int my_c_setenv(info_t *);
int my_c_unsetenv(info_t *);
int popenvl(info_t *);
char **get_environ(info_t *);
int _uenv(info_t *, char *);
int _senv(info_t *, char *, char *);
char *get_history_of_files(info_t *info);
int write_a_history(info_t *info);
int read_any_history(info_t *info);
int build_your_history_list(info_t *info, char *buf, int linecount);
int renumber_any_history(info_t *info);
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);
size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);
int ischain(info_t *, char *, size_t *);
void checkchain(info_t *, char *, size_t *, size_t, size_t);
int replacealias(info_t *);
int replacevar(info_t *);
int replace_str(char **, char *);

#endif
