errors2.c

#include "shell.h"

/**
 * Convert string to integer.
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
 * Print error message.
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
}

/**
 * Print decimal (integer) number (base 10).
 * @input: The input number.
 * @fd: The file descriptor to write to.
 * 
 * Returns: The number of characters printed.
 */
int printDecimal(int input, int fd)
{
    int (*outputChar)(char) = (fd == STDERR_FILENO) ? _eputchar : _putchar;
    int count = 0;
    int absoluteValue = (input < 0) ? -input : input;
    int current = absoluteValue;

    if (input < 0)
    {
        outputChar('-');
        count++;
    }

    for (int divisor = 1000000000; divisor > 1; divisor /= 10)
    {
        if (absoluteValue / divisor)
        {
            outputChar('0' + current / divisor);
            count++;
        }
        current %= divisor;
    }

    outputChar('0' + current);
    count++;

    return count;
}

/**
 * Convert number to string.
 * @num: The number.
 * @base: The base.
 * @flags: Argument flags.
 * 
 * Returns: The string representation of the number.
 */
char *convertNumber(long int num, int base, int flags)
{
    static char buffer[50];
    char *ptr = &buffer[49];
    unsigned long n = (num < 0 && !(flags & CONVERT_UNSIGNED)) ? -num : num;
    char sign = (num < 0 && !(flags & CONVERT_UNSIGNED)) ? '-' : 0;
    char *array = (flags & CONVERT_LOWERCASE) ? "0123456789abcdef" : "0123456789ABCDEF";

    *ptr = '\0';

    do
    {
        *--ptr = array[n % base];
        n /= base;
    } while (n != 0);

    if (sign)
        *--ptr = sign;

    return ptr;
}

/**
 * Replace the first instance of '#' with '\0'.
 * @buf: The address of the string to modify.
 */
void removeComments(char *buf)
{
    while (*buf)
    {
        if (*buf == '#' && (buf == buf || *(buf - 1) == ' '))
        {
            *buf = '\0';
            break;
        }
        buf++;
    }
}
