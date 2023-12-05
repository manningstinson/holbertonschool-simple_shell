# Environment

Certainly! Let's break down the provided C code into code blocks and explain each part in the context of a simple shell.

```c
#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
```

This section includes necessary header files for the C code. `"shell.h"` is presumably a custom header file specific to the shell implementation, and the standard library headers (`stdio.h`, `stdlib.h`, and `string.h`) are included for various functionalities.

```c
/**
 * my_enviro - Print the environment
 *
 * Return: Always returns 0, to indicate success
 */
int my_enviro(__attribute__((unused)) char **args)
{
    char **env = environ;

    while (*env != NULL)
    {
        printf("%s\n", *env);
        env++;
    }

    return 0;
}
```

The `my_enviro` function prints the environment variables to the console. It uses the `environ` variable, which is a global variable containing the environment variables, and iterates through the array, printing each variable. The `__attribute__((unused))` annotation indicates that the `args` parameter is not currently used, suppressing any compiler warnings.

```c
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
```

The `get_enviro` function retrieves the value of a specified environment variable. It uses the `getenv` function provided by the standard library, which returns a pointer to the value of the specified environment variable or NULL if the variable is not found.

```c
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
```

The `set_enviro` function sets the value of a specified environment variable. It uses the `setenv` function, which adds or modifies an environment variable. The third argument `1` indicates that existing variables with the same name should be replaced. The function returns 0 on success and -1 on failure, printing an error message using `perror` if needed.

```c
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
```

The `unset_enviro` function removes a specified environment variable. It uses the `unsetenv` function provided by the standard library. Similar to the previous functions, it returns 0 on success and -1 on failure, printing an error message if needed.

```c
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
```

The `populate_enviro` function sets the environment variables based on the provided array `envp`. It uses the `putenv` function, which adds or modifies an environment variable. The function iterates through the array until a `NULL` entry is encountered, setting each environment variable accordingly.

In a simple shell context, these functions provide essential utilities for managing and interacting with environment variables. They enable the shell to print the environment, retrieve, set, and unset specific variables, as well as populate the environment with a provided set of variables.
