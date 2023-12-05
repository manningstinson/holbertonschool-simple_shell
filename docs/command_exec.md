# Command Exec
In a simple shell context, this function allows the shell to spawn a child process to execute external commands. The `fork()` creates a copy of the current process, and `execv` overlays this copy with the specified command. The parent process waits for the child to complete, ensuring proper synchronization in the shell. If the command is not found, an error message is printed to stderr.

```c
#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
```

This section includes necessary header files for the C code. `"shell.h"` is presumably a custom header file specific to the shell implementation, and the standard library headers (`stdio.h`, `stdlib.h`, `unistd.h`, `sys/types.h`, and `sys/wait.h`) are included for various functionalities.

```c
/**
 * execute_command - Execute external commands
 * @command: The command to execute
 */
void execute_command(char *command)
{
    pid_t child_pid;
    int status;

    child_pid = fork();
    if (child_pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0)
    {
        /* Child process */
        char *args[2];
        args[0] = command;
        args[1] = NULL;

        if (execv(command, args) == -1)
        {
            fprintf(stderr, "%s: command not found\n", command);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        /* Parent process */
        waitpid(child_pid, &status, 0);
    }
}
```

The `execute_command` function is responsible for executing external commands in a simple shell. It begins by forking a new process using `fork()`. If the fork fails (`child_pid == -1`), an error is printed, and the program exits. In the child process (`child_pid == 0`), it constructs an argument array `args` with the command and a `NULL` terminator. It then uses `execv` to replace the child process with the specified command, and if it fails, an error message is printed, and the child process exits. In the parent process, it waits for the child process to complete using `waitpid`.

