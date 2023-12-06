# Shell Built-in Commands

Certainly! Here's the code broken down into smaller, more detailed code blocks:

```c
#include "shell.h"
```

**Header Inclusion:**
This line includes the necessary header file for the shell project.

```c
/**
 * _myexit - exits the shell
 * @info: Structure containing potential arguments. Used to maintain
 *         a constant function prototype.
 * Return: exits with a given exit status
 *         (0) if info->argv[0] != "exit"
 */
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

    // No argument provided, set err_num to -1
    info->err_num = -1;
    return (-2);
}
```

**Function `_myexit` Description:**
The `_myexit` function exits the shell. If an argument is provided, it attempts to convert it to an integer as an exit status using the custom `_erratoi` function. If successful, it sets the exit status; otherwise, it prints an error message.

```c
/**
 * _mycd - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *         a constant function prototype.
 * Return: Always 0
 */
int _mycd(info_t *info)
{
    char *s, *dir, buffer[1024];
    int chdir_ret;

    // Get the current working directory
    s = getcwd(buffer, 1024);

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
    // Change to the specified directory
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

**Function `_mycd` Description:**
The `_mycd` function changes the current directory of the process. It supports changing to the home directory, the previous directory, or a specified directory. It updates environment variables accordingly.

```c
/**
 * _myhelp - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *         a constant function prototype.
 * Return: Always 0
 */
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

**Function `_myhelp` Description:**
The `_myhelp` function currently provides a placeholder message indicating that the help function is not yet implemented. It is intended to offer assistance and information about shell commands.
