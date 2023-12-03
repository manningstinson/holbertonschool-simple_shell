#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * my_enviro - Print the environment
 *
 * Return: Always returns 0, to indicate success
 */
int my_enviro(char **args)
{
    char **env = environ;

    while (*env != NULL)
    {
        printf("%s\n", *env);
        env++;
    }

    return 0;
}

/**
 * get_enviro - Get the value of an environment variable
 * @name: The name of the environment variable
 *
 * Return: The value of the environment variable, or NULL if not found
 */
char *get_enviro(char *name)
{
    return getenv(name);
}

/**
 * set_enviro - Set the value of an environment variable
 * @name: The name of the environment variable
 * @value: The new value for the environment variable
 *
 * Return: 0 on success, -1 on failure
 */
int set_enviro(char *name, char *value)
{
    if (name == NULL || value == NULL)
        return -1;

    if (setenv(name, value, 1) != 0)
    {
        perror("setenv");
        return -1;
    }

    return 0;
}

/**
 * unset_enviro - Unset an environment variable
 * @name: The name of the environment variable to unset
 *
 * Return: 0 on success, -1 on failure
 */
int unset_enviro(char *name)
{
    if (name == NULL)
        return -1;

    if (unsetenv(name) != 0)
    {
        perror("unsetenv");
        return -1;
    }

    return 0;
}

/**
 * populate_enviro - Populate the environment with provided variables
 * @envp: The array of environment variables to set
 */
void populate_enviro(char **envp)
{
    int i = 0;

    while (envp[i] != NULL)
    {
        putenv(envp[i]);
        i++;
    }
}
