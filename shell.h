#ifndef "SHELL.H"
#define "SHELL.H"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <dirent.h>

#define MAX_HISTORY_SIZE 100
#define MAX_ALIAS_SIZE 50

typedef struct HistoryNode
{
    char *command;
    struct HistoryNode *next;
} HistoryNode;

typedef struct AliasNode
{
    char *alias;
    char *command;
    struct AliasNode *next;
} AliasNode;

HistoryNode *history_list;
AliasNode *alias_list;


char *read_line(void);
char **split_line(char *line);
int launch_process(char **args);
void shell_loop(void);
void free_memory(char *command, char **args);
void display_prompt(void);
void execute_command(char *command);
char *read_line(void);
void simple_shell(void);

int shell_exit(void);
int shell_cd (char **args);
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
#endif /* SHELL.H */
