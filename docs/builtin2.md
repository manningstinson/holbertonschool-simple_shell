# Builtin 2 (builtin2.c)
```c
#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
```

This section includes necessary header files for the C code. `"shell.h"` is presumably a custom header file specific to the shell implementation, and the standard library headers (`stdio.h`, `stdlib.h`, and `string.h`) are included for various functionalities.

```c
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
```

The `unset_shell_alias` function removes a shell alias from the alias list. It iterates through the linked list of aliases (`AliasNode`), finds the alias to unset, updates the linked list, and frees the memory associated with the removed alias.

```c
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
```

The `set_shell_alias` function adds a new shell alias to the alias list. It allocates memory for a new `AliasNode`, sets its `alias` and `value`, and appends it to the end of the linked list.

```c
#include <unistd.h>
```

This section includes the `<unistd.h>` header, providing access to the `access` function, which is used to check if a file (in this context, a shell command) is accessible.

```c
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
```

The `check_executable` function verifies if a given command is executable. It first checks if the command is accessible in the current directory using `access`. If not, it searches for the command in the specified path using the `find_command_in_path` function and then checks its accessibility.

```c
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
```

The `duplicate_chars` function duplicates characters in a string, effectively doubling each character. It allocates memory for the duplicated string, iterates through the original string, and fills the new string with doubled characters.

```c
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
```

The `find_command_in_path` function searches for a command in the specified PATH. It tokenizes the PATH string, constructs the full path for the command, and checks if the command is accessible using the `access` function. If found, it returns the full path; otherwise, it returns NULL.

In summary, these functions contribute to a simple shell by providing functionality to unset and set shell aliases, check the executability of commands, and search for commands in the PATH. The code also includes utility functions for string manipulation and memory management.
