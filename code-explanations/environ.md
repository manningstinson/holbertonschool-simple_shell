# environ.c
In summary, `environ.c` is a fundamental component of the Simple Shell project, providing functions to interact with and manipulate environment variables. These functions contribute to the overall functionality of the shell by enabling users to view, set, modify, and remove environment variables as needed. The populate_env_list function ensures that the shell starts with an environment that reflects the system's initial state.

## \_myenv Function

The`_myenv` function is responsible for printing the current environment. It achieves this by utilizing the print_list_str function, which prints the elements of a linked list of strings. The function takes a info_t structure as an argument and contributes to the shell's ability to display the current environment to the user.

```c
#include "shell.h"

/**
 * \_myenv - prints the current environment
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int _myenv(info_t *info)
{
    print_list_str(info->env);
    return (0);
}
```

## \_getenv Function

The `_getenv` function is designed to retrieve the value of a specified environment variable. It searches through the linked list of environment variables stored in the info->env structure. The function takes a `info_t structure` and the name of the environment variable as parameters. It returns the value associated with the specified environment variable, providing essential functionality for accessing and utilizing environment variables within the shell.

```c
/**
 * \_getenv - gets the value of an environ variable
 * @info: Structure containing potential arguments. Used to maintain
 * @name: env var name
 * Return: the value
 */
char *_getenv(info_t *info, const char *name)
{
    list_t *node = info->env;
    char *p;

    while (node)
    {
        p = starts_with(node->str, name);
        if (p && *p)
            return (p);
        node = node->next;
    }
    return (NULL);
}
```

## \_mysetenv Function

The _mysetenv function plays a crucial role in initializing a new environment variable or modifying an existing one. It checks the number of arguments received and uses `the _setenv function`, which is not explicitly provided in the provided code snippet but is assumed to handle the actual setting or modification of environment variables. This function enables users to interact with the environment, allowing for the creation or alteration of environment variables within the shell.

```c
/**
 * \_mysetenv - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always 0
 */
int _mysetenv(info_t *info)
{
    if (info->argc != 3)
    {
        _eputs("Incorrect number of arguments\n");
        return (1);
    }
    if (_setenv(info, info->argv[1], info->argv[2]))
        return (0);
    return (1);
}
```

## \_myunsetenv Function

The `_myunsetenv` function is responsible for removing one or more specified environment variables. It ensures that a sufficient number of arguments are provided before proceeding to call the _unsetenv function. Similar to _setenv, the _unsetenv function is assumed to handle the actual removal of environment variables. This function provides users with the capability to selectively remove environment variables, contributing to the shell's flexibility and user control.

```c
/**
 * \_myunsetenv - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always 0
 */
int _myunsetenv(info_t *info)
{
    int i;

    if (info->argc == 1)
    {
        _eputs("Too few arguments.\n");
        return (1);
    }
    for (i = 1; i <= info->argc; i++)
        _unsetenv(info, info->argv[i]);

    return (0);
}
```

## populate_env_list Function

The populate_env_list function initializes the environment linked list (info->env) based on the system's environment variables (environ). It creates a linked list of environment variable strings, where each node corresponds to an environment variable. This function is crucial for setting up the initial environment within the shell, allowing it to operate with the existing system environment variables.

```c
/**
 * populate_env_list - populates env linked list
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int populate_env_list(info_t *info)
{
    list_t *node = NULL;
    size_t i;

    for (i = 0; environ[i]; i++)
        add_node_end(&node, environ[i], 0);
    info->env = node;
    return (0);
}
```
