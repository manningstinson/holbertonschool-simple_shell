# environ.c

This file, `environ.c`, plays a crucial role in the Simple Shell project. It contains functions related to environment variables. Let's break down each function:

## \_myenv Function

The `_myenv` function prints the current environment by utilizing the `print_list_str` function. It takes a structure `info_t` as an argument.

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

The `_getenv` function retrieves the value of a specified environment variable. It takes a structure `info_t` and the name of the environment variable as parameters.

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

The `_mysetenv` function initializes a new environment variable or modifies an existing one. It checks for the correct number of arguments and uses the `_setenv` function.

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

The `_myunsetenv` function removes one or more specified environment variables. It ensures a sufficient number of arguments and uses the `_unsetenv` function.

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

The `populate_env_list` function initializes the environment linked list (`info->env`) based on the system's environment variables (`environ`). It takes a structure `info_t` as an argument.

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

These functions collectively provide essential functionality for managing and interacting with environment variables in the Simple Shell project.
