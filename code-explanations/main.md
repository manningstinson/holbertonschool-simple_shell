# main.c

The `main.c` file serves as the entry point for the shell program. It contains the `main` function and orchestrates the initialization of the shell, handling command-line arguments, opening files, and launching the main shell loop (`hsh` function). This file acts as the orchestrator, setting up the necessary components for the shell program to run and execute user commands.

The following code blocks outline the `main` function's structure: initialization of the `info_t` structure, handling command-line arguments, setting up the environment, and starting the main shell loop.

#### Function Signature and Initialization

```c
/**
 * main - entry point
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av) {
    // Initialization of the info_t structure
    info_t info[] = { INFO_INIT };
    int fd = 2;

    // Inline assembly code to modify the value of fd
    asm ("mov %1, %0\n\t"
        "add $3, %0"
        : "=r" (fd)
        : "r" (fd));
```

#### Command-Line Argument Handling

```c
    // Handling command-line arguments
    if (ac == 2) {
        fd = open(av[1], O_RDONLY);
        if (fd == -1) {
            // Error handling for file opening failures
            if (errno == EACCES)
                exit(126);
            if (errno == ENOENT) {
                _eputs(av[0]);
                _eputs(": 0: Can't open ");
                _eputs(av[1]);
                _eputchar('\n');
                _eputchar(BUF_FLUSH);
                exit(127);
            }
            return (EXIT_FAILURE);
        }
        info->readfd = fd; // Set the read file descriptor in the info structure
    }
```

#### Environment Setup and Initialization

```c
    // Populate environment list and read history
    populate_env_list(info);
    read_history(info);

    // Start the main shell loop
    hsh(info, av);

    return (EXIT_SUCCESS);
}
```
