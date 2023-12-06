#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * check_executable - Check if a command is an executable
 * @command: The command to check
 * @path: The path to search for the command
 *
 * Return: 1 if executable, 0 otherwise
 */
int check_executable(const char *command, const char *path)
{
    char *full_path;
    int result;

    if (access(command, X_OK) == 0)
        return 1;

    full_path = find_command_in_path(command, path);
    if (full_path == NULL)
        return 0;

    result = access(full_path, X_OK) == 0;
    free(full_path);

    return result;
}

/**
 * duplicate_chars - Duplicate characters in a string
 * @str: The string to duplicate
 *
 * Return: The duplicated string
 */
char *duplicate_chars(const char *str)
{
    size_t i; /* Declare 'i' outside of the loop for C99 compatibility */
    size_t len = strlen(str);
    char *duplicate = malloc((2 * len + 1) * sizeof(char));

    if (duplicate == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < len; i++)
    {
        duplicate[2 * i] = str[i];
        duplicate[2 * i + 1] = str[i];
    }

    duplicate[2 * len] = '\0';

    return duplicate;
}

/**
 * find_command_in_path - Find a command in the PATH
 * @command: The command to find
 * @path: The PATH string
 *
 * Return: The full path of the command, or NULL if not found
 */
char *find_command_in_path(const char *command, const char *path)
{
    char *token;
    char *path_copy = strdup(path);

    if (path_copy == NULL)
    {
        perror("strdup");
        exit(EXIT_FAILURE);
    }

    token = strtok(path_copy, ":");
    while (token != NULL)
    {
        char *full_path = malloc((strlen(token) + strlen(command) + 2) * sizeof(char));

        if (full_path == NULL)
        {
            perror("malloc");
            exit(EXIT_FAILURE);
        }

        sprintf(full_path, "%s/%s", token, command);

        if (access(full_path, F_OK) == 0)
        {
            free(path_copy);
            return full_path;
        }

        free(full_path);
        token = strtok(NULL, ":");
    }

    free(path_copy);
    return NULL;
}

