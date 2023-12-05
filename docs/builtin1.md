# BuiltIn 1 (builtin1.c)
```c
#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
```

This section includes necessary header files for the C code. `"shell.h"` is presumably a custom header file specific to the shell implementation, and the standard library headers (`stdio.h`, `stdlib.h`, `string.h`, and `unistd.h`) are included for various functionalities.

```c
/**
 * execute_command - Execute a shell command
 * @command: The command to execute
 */
void execute_command(char *command)
{
    UNUSED(command);
    /* Your implementation here */
}
```

The `execute_command` function is a placeholder for executing shell commands. The `UNUSED(command)` macro indicates that the `command` parameter is currently unused in the function. The comment suggests that the actual implementation of executing a command is expected to be written in place of the placeholder.

```c
/**
 * shell_exit - Exit the shell
 *
 * Return: Always returns 0, to indicate success
 */
int shell_exit(void)
{
    exit(0);
}
```

The `shell_exit` function is a simple built-in command to exit the shell. It calls the `exit` function with a status code of 0, indicating a successful exit.

```c
/**
 * shell_cd - Change directory
 * @args: The arguments passed to the command (should contain the new directory)
 *
 * Return: 0 on success, -1 on failure
 */
int shell_cd(char **args)
{
    if (args[1] == NULL)
    {
        fprintf(stderr, "shell: expected argument to \"cd\"\n");
        return -1;
    }

    if (chdir(args[1]) != 0)
        return handle_cd_error(args[1]);

    return 0;
}
```

The `shell_cd` function handles the built-in command to change the current working directory. It expects the new directory as an argument in `args`. If the argument is not provided, it prints an error message and returns -1. If the `chdir` function fails, it calls the `handle_cd_error` function, otherwise, it returns 0 to indicate success.

```c
/**
 * shell_help - Display information about built-in commands
 *
 * Return: Always returns 0, to indicate success
 */
int shell_help(void)
{
    printf("Simple Shell\n");
    printf("Built-in commands:\n");
    printf("  exit - Exit the shell\n");
    printf("  cd - Change directory\n");
    printf("  help - Display information about built-in commands\n");

    return 0;
}
```

The `shell_help` function displays information about built-in commands of the shell. It prints a simple help message to the console, listing the available built-in commands: `exit`, `cd`, and `help`. It always returns 0 to indicate success.

```c
/**
 * handle_cd_error - Display an error message for cd command
 * @path: The path that caused the error
 *
 * Return: Always returns -1, to indicate failure
 */
int handle_cd_error(char *path)
{
    perror(path);
    return -1;
}
```

The `handle_cd_error` function is a utility function to display an error message when the `cd` command encounters an issue. It uses the `perror` function to print an error message based on the value of `errno` related to the last `chdir` operation. It always returns -1 to indicate failure.
