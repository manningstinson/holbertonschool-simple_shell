# Get Line (getline.md)
In a simple shell context, this function is crucial for reading user input. It displays the prompt, reads a line of input, and handles potential errors or end-of-file conditions gracefully. The dynamically allocated string containing the input line is then processed by other parts of the shell.


```c
#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
```

This section includes the necessary header files, including `"shell.h"`, which likely contains declarations specific to the shell, and standard library headers (`stdio.h`, `stdlib.h`).

```c
void _prompt(void);
void clear_info(info_t *info);
```

These lines declare two functions: `_prompt` and `clear_info`. The `_prompt` function is responsible for displaying the shell prompt, and `clear_info` is a function that presumably clears or resets some information structure (`info_t`).

```c
/**
 * _getline - Read a line of input from standard input.
 * @info: Pointer to the information struct.
 * Return: A pointer to the read line.
 */
char *_getline(info_t *info)
{
    size_t bufsize = 0; /* Initial size of the buffer */
    ssize_t characters_read;
    char *line = NULL;

    if (info != NULL)
    {
        _prompt();
        characters_read = getline(&line, &bufsize, stdin);

        if (characters_read == -1)
        {
            _eputchar('\n');
            clear_info(info);
            free(line);
            exit(EXIT_SUCCESS);
        }

        if (line[characters_read - 1] == '\n')
        {
            line[characters_read - 1] = '\0';
        }
    }

    return line;
}
```

The `_getline` function reads a line of input from the standard input (`stdin`). It takes a pointer to an information structure (`info_t`) as a parameter. Inside the function:

- `size_t bufsize = 0;` initializes the initial size of the buffer used by `getline`.
- `_prompt();` is called to display the shell prompt.
- `characters_read = getline(&line, &bufsize, stdin);` reads a line of input into the dynamically allocated buffer (`line`). The buffer size is managed automatically by `getline`.
- If `characters_read` is -1, it indicates an error or end-of-file. In this case, the program prints a newline character, clears the information structure, frees the allocated memory for the line, and exits with success status (`EXIT_SUCCESS`).
- If the last character of the line is a newline character, it is replaced with a null terminator, effectively removing the newline from the end of the string.

The function returns a pointer to the dynamically allocated string containing the read line.
