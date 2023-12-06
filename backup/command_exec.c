#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * execute_command - Execute external commands
 * @command: The command to execute
 */
void execute_command(char *command)
{
    pid_t child_pid;
    int status;

    child_pid = fork();
    if (child_pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0)
    {
        /* Child process */
        char *args[2];
        args[0] = command;
        args[1] = NULL;

        if (execv(command, args) == -1)
        {
            fprintf(stderr, "%s: command not found\n", command);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        /* Parent process */
        waitpid(child_pid, &status, 0);
    }
}
