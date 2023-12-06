#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * shell_loop - Main loop for the shell
 * @info: Pointer to the shell information struct
 */
void shell_loop(info_t *info)
{
    char *line;
    char **argv;
    int status;

    do
    {
        printf("$ ");
        line = _getline(info);
        if (line == NULL)
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
        bfree((void **)&line);

    } while (status);
}

/**
 * write_history - Write history to a file
 * @info: Pointer to the shell information struct
 */
void write_history(info_t *info)
{
    // Implementation to write history to a file
    // You can use info->history to access the history data
    // and info->history_file to get the file name
}

/**
 * read_history - Read history from a file
 * @info: Pointer to the shell information struct
 */
void read_history(info_t *info)
{
    // Implementation to read history from a file
    // You can use info->history_file to get the file name
    // and update info->history with the read data
}

/**
 * find_builtin - Find and execute built-in commands
 * @info: Pointer to the shell information struct
 * @argv: Argument vector containing the command and its arguments
 * Return: 1 if the command is built-in, 0 otherwise
 */
int find_builtin(info_t *info, char **argv)
{
    // Implementation to find and execute built-in commands
    // You can use info->builtins to check if a command is built-in
    // and execute the corresponding function

    return 0;
}

/**
 * find_command_path - Find the full path of a command
 * @info: Pointer to the shell information struct
 * @command: Command to find
 * Return: Full path of the command if found, NULL otherwise
 */
char *find_command_path(info_t *info, const char *command)
{
    // Implementation to find the full path of a command
    // You can use info->path to search for the command in the directories

    return NULL;
}

/**
 * execute_command - Fork and execute a command
 * @info: Pointer to the shell information struct
 * @argv: Argument vector containing the command and its arguments
 * Return: Status code of the executed command
 */
int execute_command(info_t *info, char **argv)
{
    pid_t pid, wpid;
    int status;

    if (find_builtin(info, argv))
        return 1;

    pid = fork();
    if (pid == 0)
    {
        // Child process
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
        // Parent process
        do
        {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}

