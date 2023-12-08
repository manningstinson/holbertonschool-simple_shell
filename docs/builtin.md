# builtin
These functions collectively contribute to the basic functionality of a shell, including the ability to exit, navigate directories, and potentially obtain help on command usage. In a simple shell project, these functions form essential building blocks for user interaction and control over the shell's behavior.

```c
#include "shell.h"
```

**Header Inclusion:**
Includes the necessary header file for the shell project.

```c
/**
 * _myexit - exits the shell
 * @info: Structure containing potential arguments.
 *         Used to maintain a constant function prototype.
 * Return: exits with a given exit status (0) if info->argv[0] != "exit"
 */
```

**Function `_myexit` Signature:**
Declares the `_myexit` function, which exits the shell based on the provided arguments.

```c
int _myexit(info_t *info)
{
    int exitcheck;

    if (info->argv[1])
    {
        // Convert argument to an integer using custom _erratoi function
        exitcheck = _erratoi(info->argv[1]);

        // Handle the case where _erratoi returns -1 (invalid number)
        if (exitcheck == -1)
        {
            info->status = 2;
            print_error(info, "Illegal number: ");
            _eputs(info->argv[1]);
            _eputchar('\n');
            return (1);
        }

        // Set err_num to the converted exit status
        info->err_num = exitcheck;
        return (-2);
    }
```

**Function `_myexit` Implementation (Part 1):**
The `_myexit` function implementation begins. It checks if an argument is provided, attempts to convert it to an integer using `_erratoi`, and handles invalid numbers.

```c
    // No argument provided, set err_num to -1
    info->err_num = -1;
    return (-2);
}
```

**Function `_myexit` Implementation (Part 2):**
Continuation of `_myexit` function implementation. If no argument is provided, it sets `err_num` to -1.

```c
/**
 * _mycd - changes the current directory of the process
 * @info: Structure containing potential arguments.
 *         Used to maintain a constant function prototype.
 * Return: Always 0
 */
```

**Function `_mycd` Signature:**
Declares the `_mycd` function, responsible for changing the current directory.

```c
int _mycd(info_t *info)
{
    char *s, *dir, buffer[1024];
    int chdir_ret;

    // Get the current working directory
    s = getcwd(buffer, 1024);
```

**Function `_mycd` Implementation (Part 1):**
Starts the implementation of the `_mycd` function. It gets the current working directory using `getcwd`.

```c
    // Handle getcwd failure
    if (!s)
        _puts("TODO: >>getcwd failure emsg here<<\n");

    // No argument provided, change to home directory
    if (!info->argv[1])
    {
        dir = _getenv(info, "HOME=");
        if (!dir)
            chdir_ret = chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
        else
            chdir_ret = chdir(dir);
    }
```

**Function `_mycd` Implementation (Part 2):**
Continuation of `_mycd` implementation. Handles `getcwd` failure and checks if no argument is provided to change to the home directory.

```c
    // Argument is "-", change to the previous directory
    else if (_strcmp(info->argv[1], "-") == 0)
    {
        if (!_getenv(info, "OLDPWD="))
        {
            _puts(s);
            _putchar('\n');
            return (1);
        }
        _puts(_getenv(info, "OLDPWD=")), _putchar('\n');
        chdir_ret = chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
    }
```

**Function `_mycd` Implementation (Part 3):**
Continuation of `_mycd` implementation. Handles the case where the argument is "-", changing to the previous directory.

```c
    else
        chdir_ret = chdir(info->argv[1]);

    // Handle chdir failure
    if (chdir_ret == -1)
    {
        print_error(info, "can't cd to ");
        _eputs(info->argv[1]), _eputchar('\n');
    }
    else
    {
        // Update environment variables (OLDPWD and PWD)
        _setenv(info, "OLDPWD", _getenv(info, "PWD="));
        _setenv(info, "PWD", getcwd(buffer, 1024));
    }

    return (0);
}
```

**Function `_mycd` Implementation (Part 4):**
Final part of `_mycd` implementation. Handles changing to a specified directory, chdir failure, and updates environment variables.

```c
/**
 * _myhelp - changes the current directory of the process
 * @info: Structure containing potential arguments.
 *         Used to maintain a constant function prototype.
 * Return: Always 0
 */
```

**Function `_myhelp` Signature:**
Declares the `_myhelp` function, which currently provides a placeholder message.

```c
int _myhelp(info_t *info)
{
    char **arg_array;

    arg_array = info->argv;

    // Placeholder message indicating that the help function is not yet implemented
    _puts("help call works. Function not yet implemented \n");
    if (0)
        _puts(*arg_array); /* temp att_unused workaround */
    return (0);
}
```

**Function `_myhelp` Implementation:**
The `_myhelp` function implementation, providing a placeholder message indicating that the help function is not yet implemented.
