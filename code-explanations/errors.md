# errors.c
In summary, `eoutput.c` facilitates enhanced output to `stderr` in the Simple Shell program. The functions `_eputs`, `_eputchar`, `_putfd`, and `_putsfd` collectively optimize character output operations, providing efficiency and flexibility in handling errors and user feedback within the shell.


## \_eputs Function

The `_eputs` function prints an input string to `stderr`. It iterates through the string, character by character, and utilizes the `_eputchar` function to write each character to the standard error.

```c
#include "shell.h"

/**
 * \_eputs - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
    int i = 0;

    if (!str)
        return;
    while (str[i] != '\0')
    {
        _eputchar(str[i]);
        i++;
    }
}
```

## \_eputchar Function

The `_eputchar` function writes a character to `stderr`. It maintains a buffer (`buf`) to optimize write operations, flushing the buffer when full or when a special character (`BUF_FLUSH`) is encountered.

```c
/**
 * \_eputchar - writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char c)
{
    static int i;
    static char buf[WRITE_BUF_SIZE];

    if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
    {
        write(2, buf, i);
        i = 0;
    }
    if (c != BUF_FLUSH)
        buf[i++] = c;
    return (1);
}
```

## \_putfd Function

The `_putfd` function writes a character to a specified file descriptor (`fd`). Similar to `_eputchar`, it optimizes write operations using a buffer (`buf`) and flushes the buffer when full or when a special character (`BUF_FLUSH`) is encountered.

```c
/**
 * \_putfd - writes the character c to given fd
 * @c: The character to print
 * @fd: The file descriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char c, int fd)
{
    static int i;
    static char buf[WRITE_BUF_SIZE];

    if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
    {
        write(fd, buf, i);
        i = 0;
    }
    if (c != BUF_FLUSH)
        buf[i++] = c;
    return (1);
}
```

## \_putsfd Function

The `_putsfd` function prints an input string to a specified file descriptor (`fd`). It iterates through the string, character by character, and utilizes the `_putfd` function to write each character to the specified file descriptor.

```c
/**
 * \_putsfd - prints an input string
 * @str: the string to be printed
 * @fd: the file descriptor to write to
 *
 * Return: the number of characters put
 */
int _putsfd(char *str, int fd)
{
    int i = 0;

    if (!str)
        return (0);
    while (*str)
    {
        i += _putfd(*str++, fd);
    }
    return (i);
}
```
