#include "shell.h"

/**
 * _getenv - Get the value of an environment variable.
 * @name: The name of the environment variable.
 * 
 * Return: The value of the environment variable or NULL if not found.
 */
char *_getenv(const char *name)
{
    extern char **environ;
    char **env;

    for (env = environ; *env != NULL; env++)
    {
        if (_startswith(*env, name))
        {
            return (*env + _strlen(name) + 1);
        }
    }

    return NULL;
}

/**
 * _unsetenv - Unset an environment variable.
 * @name: The name of the environment variable to unset.
 * 
 * Return: 0 on success, -1 on failure.
 */
int _unsetenv(const char *name)
{
    if (name == NULL || _getenv(name) == NULL)
    {
        return -1;
    }

    return _clearenv(name);
}

/**
 * _setenv - Set or update an environment variable.
 * @name: The name of the environment variable.
 * @value: The value to set.
 * @overwrite: If true, overwrite the variable if it exists. If false, do nothing if the variable exists.
 * 
 * Return: 0 on success, -1 on failure.
 */
int _setenv(const char *name, const char *value, int overwrite)
{
    if (name == NULL || value == NULL)
    {
        return -1;
    }

    if (_getenv(name) != NULL)
    {
        if (!overwrite)
        {
            return 0;
        }
        else
        {
            if (_unsetenv(name) != 0)
            {
                return -1;
            }
        }
    }

    char *envvar = _strcat(_strcat(_strdup(name), "="), value);
    if (envvar == NULL)
    {
        return -1;
    }

    if (_putenv(envvar) != 0)
    {
        return -1;
    }

    return 0;
}
