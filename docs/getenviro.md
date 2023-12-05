# Get Environment (getenviro.c)
In a simple shell context, these functions provide an interface for interacting with environment variables. Users can retrieve, set, and unset environment variables using the `_getenv`, `_setenv`, and `_unsetenv` functions, respectively. This is crucial for managing the shell's environment and configuration during its execution.

```c
#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
```

This section includes the necessary header files, including `"shell.h"`, which likely contains declarations specific to the shell, and standard library headers (`stdio.h`, `stdlib.h`, `string.h`).

```c
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
```

The `_getenv` function retrieves the value of an environment variable given its name. It iterates through the environment variables (`environ`), searching for a variable whose name matches the provided `name`. The comparison is done using the `_startswith` function, which checks if the current environment variable starts with the specified name. If a match is found, the function returns a pointer to the value of that environment variable (excluding the name). If no match is found, it returns NULL.

```c
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
```

The `_unsetenv` function is a wrapper around the `unset_enviro` function, which likely handles the unsetting of environment variables. It takes the name of the environment variable as a parameter and returns the result of the `unset_enviro` function (0 on success, -1 on failure).

```c
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
```

Similarly, the `_setenv` function is a wrapper around the `set_enviro` function, likely responsible for setting or modifying the value of an environment variable. It takes the name and value of the environment variable as parameters and returns the result of the `set_enviro` function (0 on success, -1 on failure).
