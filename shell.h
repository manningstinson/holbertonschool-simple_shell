// shell.h
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
#define INFO_INIT { NULL, NULL, NULL, -1, NULL, NULL, NULL, 0 }
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
void replaceVars(char **tokens);
void replaceAliases(char **tokens);
void replaceAliasesAndVars(char **tokens);
char **tokenize(char *str);
char *string_copy(const char *src);
char *string_duplicate(char *str);
void print_string(const char *str);
void write_character(char c);
size_t _strlen(const char *s);
int _strcmp(const char *s1, const char *s2);
int _startswith(const char *haystack, const char *needle);
char *_strcat(char *dest, const char *src);

/* List manipulation functions */
size_t list_len(list_t *head);
char **list_to_strings(list_t *head);
void print_node_start(list_t *start);
void print_node_at_index(list_t *head, size_t index);
list_t *add_node(list_t **head, const char *str);
list_t *add_node_at_index(list_t **head, size_t index, const char *str);
void print_list_str(list_t *head);
int delete_node(list_t **head, size_t index);
void free_list(list_t **head);

/* I/O and string manipulation functions */
void custom_puts(char *str);
int custom_putchar(char c);
int custom_putchar_fd(char c, int fd);
int custom_puts_fd(char *str, int fd);

/* Conversion and error handling functions */
int convertStringToInt(char *s);
void displayError(info_t *info, char *estr);
void printDecimal(int n, int fd);
int itoaClone(int n, char *str, size_t size);
void replaceFirstHash(char *str);

/* Environmental variable functions */
char *_getenv(char *name);
int _unsetenv(char *name);
int _setenv(char *name, char *value);

/* Command execution functions */
int my_exit(char **args);
int execute_command(info_t *info, char **argv);

#endif /* SHELL_H */
