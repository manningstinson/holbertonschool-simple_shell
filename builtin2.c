#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * unset_shell_alias - Unset a shell alias.
 * @alias_list: Pointer to the head of the alias list.
 * @alias: Alias to unset.
 * Return: 0 on success, -1 on failure.
 */
int unset_shell_alias(AliasNode **alias_list, const char *alias)
{
    AliasNode *current = *alias_list, *prev = NULL;

    while (current != NULL)
    {
        if (_strcmp(current->alias, alias) == 0)
        {
            if (prev == NULL)
            {
                *alias_list = current->next;
            }
            else
            {
                prev->next = current->next;
            }

            free(current->alias);
            free(current->value);
            free(current);
            return 0;
        }

        prev = current;
        current = current->next;
    }

    return -1; /* Alias not found */
}

/**
 * set_shell_alias - Set a shell alias.
 * @alias_list: Pointer to the head of the alias list.
 * @alias: Alias to set.
 * @value: Value of the alias.
 * Return: 0 on success, -1 on failure.
 */
int set_shell_alias(AliasNode **alias_list, const char *alias, const char *value)
{
    AliasNode *current = *alias_list;
    AliasNode *new_alias = malloc(sizeof(AliasNode));

    if (new_alias == NULL)
    {
        perror("Unable to allocate memory");
        return -1;
    }

    new_alias->alias = strdup(alias);
    new_alias->value = strdup(value);
    new_alias->next = NULL;

    if (*alias_list == NULL)
    {
        *alias_list = new_alias;
    }
    else
    {
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_alias;
    }

    return 0;
}

=======
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
    size_t len = strlen(str);
    char *duplicate = malloc((2 * len + 1) * sizeof(char));

    if (duplicate == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < len; i++)
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
