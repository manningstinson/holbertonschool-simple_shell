# Builtins
README for builtin commands.  We were only allowed five functions per file, so the built-in commands were broken up into two files which include builtins1.c, and builtins2.c. 

## Builtins 1 (builtins1.c)

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
Sure, let's break down this additional code with explanations in each step:

# Bultin2 (builtin2.c)

### Include Header

```c
#include "builtin2.h"
```

This step includes the header file "builtin2.h," presumably containing necessary declarations and structures for the shell's built-in functionalities.

### Implement `shell_history`

```c
int shell_history(char **args)
{
    int count = 1;
    HistoryNode *current = history_list;

    while (current != NULL)
    {
        printf("%d %s\n", count, current->command);
        current = current->next;
        count++;
    }

    return 0;
}
```

The `shell_history` function displays the command history stored in a linked list (`history_list`). It prints each command along with a count.

### Implement `unset_shell_alias`

```c
int unset_shell_alias(char **args)
{
    if (args[1] == NULL)
    {
        fprintf(stderr, "shell: expected argument to \"unset alias\"\n");
        return -1;
    }

    AliasNode *current = alias_list;
    AliasNode *prev = NULL;

    while (current != NULL)
    {
        if (strcmp(current->alias, args[1]) == 0)
        {
            // Remove the alias from the list
            if (prev == NULL)
            {
                alias_list = current->next;
            }
            else
            {
                prev->next = current->next;
            }

            // Free memory for the removed alias
            free(current->alias);
            free(current->command);
            free(current);

            return 0;
        }

        prev = current;
        current = current->next;
    }

    fprintf(stderr, "shell: alias not found: %s\n", args[1]);
    return -1;
}
```

The `unset_shell_alias` function removes an alias from the linked list (`alias_list`). It searches for the alias and frees the associated memory.

### Implement `set_shell_alias`

```c
int set_shell_alias(char **args)
{
    if (args[1] == NULL || args[2] == NULL)
    {
        fprintf(stderr, "shell: expected two arguments for \"set alias\"\n");
        return -1;
    }

    // Create a new alias node and populate it with the provided alias and command
    AliasNode *new_alias = malloc(sizeof(AliasNode));
    if (new_alias == NULL)
    {
        perror("malloc");
        return -1;
    }

    new_alias->alias = strdup(args[1]);
    new_alias->command = strdup(args[2]);
    new_alias->next = alias_list;
    alias_list = new_alias;

    return 0;
}
```

The `set_shell_alias` function sets a new alias. It creates a new `AliasNode`, assigns the alias and command, and adds it to the beginning of the linked list.

### Implement `print_shell_alias`

```c
int print_shell_alias(void)
{
    AliasNode *current = alias_list;

    while (current != NULL)
    {
        printf("%s='%s'\n", current->alias, current->command);
        current = current->next;
    }

    return 0;
}
```

The `print_shell_alias` function prints the list of aliases stored in `alias_list`.

These functions seem to manage command history and aliases within the shell. Make sure to include appropriate declarations and structures in the "builtin2.h" header file.


The `handle_cd_error` function prints an error message using `perror` for the `cd` command.


