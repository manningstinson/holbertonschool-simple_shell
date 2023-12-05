#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * _getenv - Get the value of an environment variable
 * @name: The name of the environment variable
 *
 * Return: The value of the environment variable, or NULL if not found
 */
char *_getenv(char *name)
{
    char **env = environ;

    while (*env != NULL)
    {
        if (_startswith(*env, name))
            return (*env + _strlen(name) + 1);

        env++;
    }

    return NULL;
}

/**
 * _unsetenv - Unset an environment variable
 * @name: The name of the environment variable to unset
 *
 * Return: 0 on success, -1 on failure
 */
int _unsetenv(char *name)
{
    return unset_enviro(name);
}

/**
 * _setenv - Set the value of an environment variable
 * @name: The name of the environment variable
 * @value: The new value for the environment variable
 *
 * Return: 0 on success, -1 on failure
 */
int _setenv(char *name, char *value)
{
    return set_enviro(name, value);
}

