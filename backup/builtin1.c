#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * execute_command - Execute a shell command
 * @info: The information about the shell
 * @argv: The command and its arguments
 *
 * Return: 0 on success, -1 on failure
 */
int execute_command(info_t *info, char **argv)
{
    int result;  /* Declaration moved to the beginning of the block */

    /* Example: Print the current working directory and the command */
    printf("Current working directory: %s\n", info->cwd);
    printf("Command: %s\n", argv[0]);

    result = 0;  /* Replace with your actual logic */
    return result;
}

/**
 * shell_exit - Exit the shell
 *
 * Return: Always returns 0, to indicate success
 */
int shell_exit(void)
{
    exit(0);
}

/**
 * shell_cd - Change directory
 * @args: The arguments passed to the command (should contain the new directory)
 *
 * Return: 0 on success, -1 on failure
 */
int shell_cd(char **args)
{
    if (args[1] == NULL)
    {
        fprintf(stderr, "shell: expected argument to \"cd\"\n");
        return -1;
    }

    if (chdir(args[1]) != 0)
        return handle_cd_error(args[1]);

    return 0;
}

/**
 * shell_help - Display information about built-in commands
 *
 * Return: Always returns 0, to indicate success
 */
int shell_help(void)
{
    printf("Simple Shell\n");
    printf("Built-in commands:\n");
    printf("  exit - Exit the shell\n");
    printf("  cd - Change directory\n");
    printf("  help - Display information about built-in commands\n");

    return 0;
}

/**
 * handle_cd_error - Display an error message for cd command
 * @path: The path that caused the error
 *
 * Return: Always returns -1, to indicate failure
 */
int handle_cd_error(char *path)
{
    perror(path);
    return -1;
}

