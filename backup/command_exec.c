#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * execute_command - Execute external commands
 * @info: The information about the shell
 * @argv: The command and its arguments
 *
 * Return: 0 on success, -1 on failure
 */
int execute_command(info_t *info, char **argv)
{
    pid_t child_pid;
    int status;

    child_pid = fork();
    if (child_pid == -1)
    {
        perror("fork");
        return (-1);
    }

    if (child_pid == 0)
    {
        /* Child process */
        if (execv(argv[0], argv) == -1)
        {
            fprintf(stderr, "%s: command not found\n", argv[0]);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        /* Parent process */
        waitpid(child_pid, &status, 0);
    }
    printf("Current working directory: %s\n", info->cwd);
    return (0);
}

