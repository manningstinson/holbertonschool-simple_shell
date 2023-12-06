#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void shell_loop(info_t *info);
void write_history(void);
void read_history(void);
int find_builtin(void);
char *find_command_path(void);

void shell_loop(info_t *info)
{
    ssize_t read_status;
    char *line;
    char **argv;
    int status;

    do
    {
        printf("$ ");
        read_status = getline(&line, NULL, stdin);
        if (read_status == -1 || line == NULL)
        {
            break;
        }

        argv = parse_line(line);
        if (argv == NULL || argv[0] == NULL)
        {
            custom_free_strings(argv);
            continue;
        }

        status = execute_command(info, argv);

        custom_free_strings(argv);
        free(line);

    } while (status);
}

void write_history(void)
{
    /* Implementation to write history to a file
     * You can use info->history to access the history data
     * and info->history_file to get the file name
     */
}

void read_history(void)
{
    /* Implementation to read history from a file
     * You can use info->history_file to get the file name
     * and update info->history with the read data
     */
}

int find_builtin(void)
{
    /* Implementation to find and execute built-in commands
     * You can use info->builtins to check if a command is built-in
     * and execute the corresponding function
     */

    return 0;
}

char *find_command_path(void)
{
    /* Implementation to find the full path of a command
     * You can use info->path to search for the command in the directories
     */

    return NULL;
}

int execute_command(info_t *info, char **argv)
{
    pid_t pid;
    int status;

    if (find_builtin())
        return 1;

    pid = fork();
    if (pid == 0)
    {
        /* Child process */
        if (execve(argv[0], argv, info->env) == -1)
        {
            perror("hsh");
        }
        exit(EXIT_FAILURE);
    }
    else if (pid < 0)
    {
        perror("hsh");
    }
    else
    {
        /* Parent process */
        do
        {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}

