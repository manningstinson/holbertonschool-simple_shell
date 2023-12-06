#include "shell.h"

/**
 * string_copy - Copies a string.
 * @src: Source string.
 *
 * Return: A newly allocated copy of the source string.
 */
char *string_copy(const char *src)
{
    size_t len;

	if (src == NULL)
        return NULL;

    size_t len = _strlen(src);
    char *dest = malloc(len + 1);

    if (dest != NULL)
    {
        _strcpy(dest, src);
    }

    return dest;
}

/**
 * string_duplicate - Duplicates a string.
 * @str: String to duplicate.
 *
 * Return: A newly allocated duplicate of the string.
 */
char *string_duplicate(char *str)
{
    return strdup(str);
}

/**
 * print_string - Prints a string to stdout.
 * @str: String to print.
 */
void print_string(const char *str)
{
    if (str != NULL)
    {
        while (*str)
        {
            _putchar(*str);
            str++;
        }
    }
}

/**
 * write_character - Writes a character to stdout.
 * @c: Character to write.
 */
void write_character(char c)
{
    _putchar(c);
}

