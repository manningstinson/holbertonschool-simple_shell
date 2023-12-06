#pragma once
#ifndef SHELL_H
#define SHELL_H

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <dirent.h>

/* Macros */
#define BUF_FLUSH (int)(0)
#define INFO_INIT {NULL, NULL, NULL, -1, NULL, NULL, NULL, 0, {0}, 0, NULL} // Updated
#define LIST_T_DEFINED
#define WRITE_BUF_SIZE 1024

/* Definition for environmental variables */
extern char **environ;

/* Definition for the history node */
typedef struct HistoryNode {
    char *command;
    struct HistoryNode *next;
} HistoryNode;

/* Definition for the alias node */
typedef struct AliasNode {
    char *alias;
    char *value;
    struct AliasNode *next;
} AliasNode;

/* Global variables for history and alias lists */
extern HistoryNode *history_list;
extern AliasNode *alias_list;

/* Struct for shell information */
typedef struct {
    char **env;
    char **history;
    const char *history_file;
    int readfd;
    char *fname;
    char *line;
    char **argv;
    int line_count;
    char cwd[1024];
    int argument_count; // Added
    char **argument_vector; // Added
} info_t;

/* Definition for the list node (linked list) */
typedef struct list_s {
    char *str;
    struct list_s *next;
} list_t;

/* Function prototypes */

/* Main shell functions */
char **get_history(info_t *info);
void add_to_history(info_t *info, char *line);
void _strcpy(char *dest, const char *src);
void _putchar(char c);
char **arrdup(char **argv);
void shell_loop(info_t *info);
void write_history(void);
void read_history(void);
int find_builtin(void);
char *find_command_path(void);
void *custom_realloc(void *ptr, size_t size);
void custom_free_strings(char **str_arr);
void custom_memset(void *ptr, int value, size_t size);
int check_executable(const char *command, const char *path);
char *duplicate_chars(const char *str);
char *find_command_in_path(const char *command, const char *path);
int bfree(void **ptr);
void populate_env_list(info_t *info);
void _eputs(const char *str);
void _eputchar(int c);

/* Shell utility functions */
void display_prompt(void);
void free_memory(char *command, char **args);
char **split_line(char *line);
char *read_line(void);
int launch_process(char **args);
void simple_shell(void);
int shell_exit(void);
int shell_cd(char **args);
int shell_help(void);
int handle_cd_error(char *path);
int my_enviro(char **args);
char *get_enviro(char *name);
int set_enviro(char *name, char *value);
int unset_enviro(char *name);
void populate_enviro(char **envp);
int history(char **args);
int unset_alias(char **args);
int set_alias(char **args);
int print_alias(void);
void custom_puts(char *str);
int custom_putchar(char c);
int custom_putchar_fd(char c, int fd);
int custom_puts_fd(char *str, int fd);

/* Variable substitution and tokenization functions */
int isChainDelimiter(char c);
int shouldContinueChaining(int lastStatus);
void replaceVars(char **token);

#endif /* SHELL_H */

