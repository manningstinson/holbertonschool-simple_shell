#include "shell.h"
#include <stdio.h>
#include <limits.h>

/**
 * convertStringToInt - Convert string to integer.
 * @s: The string to be converted.
 *
 * Returns:
 *  - The converted number if successful.
 *  - -1 on error.
 */
int convertStringToInt(char *s)
{
    int result = 0;

    while (*s)
    {
        if (*s < '0' || *s > '9')
            return -1;

        result = result * 10 + (*s - '0');

        if (result > INT_MAX)
            return -1;

        s++;
    }

    return result;
}

/**
 * displayError - Print error message.
 * @info: Information struct.
 * @estr: String containing the error type.
 */
void displayError(info_t *info, char *estr)
{
    _eputs(info->fname);
    _eputs(": ");
    printDecimal(info->line_count, STDERR_FILENO);
    _eputs(": ");
    _eputs(info->argv[0]);
    _eputs(": ");
    _eputs(estr);
    _eputchar('\n');
}

/**
 * printDecimal - Print a decimal number to a file descriptor.
 * @n: The number to be printed.
 * @fd: File descriptor.
 */
void printDecimal(int n, int fd)
{
    char buffer[12]; 
    int size = snprintf(buffer, sizeof(buffer), "%d", n);

    if (size > 0 && (size_t)size < sizeof(buffer))
    {
        write(fd, buffer, size);
    }
}

/**
 * itoaClone - Convert integer to string (similar to itoa).
 * @n: The number to be converted.
 * @str: The buffer to store the result.
 * @size: The size of the buffer.
 *
 * Returns:
 *  - 0 on success.
 *  - -1 if the buffer is too small.
 */
int itoaClone(int n, char *str, size_t size)
{
    int result = snprintf(str, size, "%d", n);
    return (result >= 0 && (size_t)result < size) ? 0 : -1;
}

/**
 * replaceFirstHash - Replace the first instance of '#' with '\0'.
 * @str: The string to be modified.
 */
void replaceFirstHash(char *str)
{
    while (*str != '\0')
    {
        if (*str == '#')
        {
            *str = '\0';
            break;
        }
        str++;
    }
}
