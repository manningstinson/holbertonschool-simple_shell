# Builtins
README for builtin commands.  We were only allowed five functions per file, so the built-in commands were broken up into two files which include builtins1.c, and builtins2.c. 

### Include Necessary Headers

```c
#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
```

This step includes the required headers for the shell program, including standard input/output functions (`stdio.h`), memory allocation functions (`stdlib.h`), string manipulation functions (`string.h`), and system-related functions (`unistd.h`).

### Define Shell Built-in Commands

```c
int shell_exit(void) { /* ... */ }
int shell_cd(char **args) { /* ... */ }
int shell_help(void) { /* ... */ }
int handle_cd_error(char *path) { /* ... */ }
```

These functions define the built-in commands for the shell:

- `shell_exit`: Exits the shell.
- `shell_cd`: Changes the current directory.
- `shell_help`: Displays information about built-in commands.
- `handle_cd_error`: Handles errors for the `cd` command.

### Implement `shell_exit`

```c
int shell_exit(void) {
    exit(0);
}
```

The `shell_exit` function simply exits the shell with a success status.

### Implement `shell_cd`

```c
int shell_cd(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "shell: expected argument to \"cd\"\n");
        return -1;
    }

    if (chdir(args[1]) != 0)
        return handle_cd_error(args[1]);

    return 0;
}
```

The `shell_cd` function changes the current working directory. If no directory is provided as an argument, it prints an error message. If changing the directory fails, it calls `handle_cd_error`.

### Implement `shell_help`

```c
int shell_help(void) {
    printf("Simple Shell\n");
    printf("Built-in commands:\n");
    printf("  exit - Exit the shell\n");
    printf("  cd - Change directory\n");
    printf("  help - Display information about built-in commands\n");

    return 0;
}
```

The `shell_help` function displays information about built-in commands.

### Implement `handle_cd_error`

```c
int handle_cd_error(char *path) {
    perror(path);
    return -1;
}
```

The `handle_cd_error` function prints an error message using `perror` for the `cd` command.

### Additional Note

- The `main` function (not provided) is assumed to exist and should handle the overall execution of the shell.

Feel free to structure your README accordingly, elaborating on each step and providing more details as needed.


