# exits.c
In summary, `exits.c` provides crucial string manipulation functionalities for the Simple Shell program. The functions `_strncpy`, `_strncat`, and `_strchr` contribute to the overall capability of the shell to process and manipulate strings, supporting various operations within the shell environment.

## \_strncpy Function

The `_strncpy` function copies a specified number of characters from the source string (`src`) to the destination string (`dest`). It ensures that the destination string is null-terminated and has a maximum length of `n`.

```c
#include "shell.h"

/**
 ** \_strncpy - copies a string
 * @dest: the destination string to be copied to
 * @src: the source string
 * @n: the amount of characters to be copied
 * Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
    int i, j;
    char *s = dest;

    i = 0;

    while (src[i] != '\0' && i < n - 1)
    {
        dest[i] = src[i];
        i++;
    }
    if (i < n)
    {
        j = i;
        while (j < n)
        {
            dest[j] = '\0';
            j++;
        }
    }
    return (s);
}
```

## \_strncat Function

The `_strncat` function concatenates a specified number of characters from the source string (`src`) to the end of the destination string (`dest`). It ensures that the destination string remains null-terminated and has a maximum length of `n`.

```c
/**
 ** \_strncat - concatenates two strings
 * @dest: the first string
 * @src: the second string
 * @n: the amount of bytes to be maximally used
 * Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
    int i, j;
    char *s = dest;

    i = 0;
    j = 0;

    while (dest[i] != '\0')
        i++;
    while (src[j] != '\0' && j < n)
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    if (j < n)
        dest[i] = '\0';
    return (s);
}
```

## \_strchr Function

The `_strchr` function locates a specified character (`c`) in a string (`s`). It returns a pointer to the first occurrence of the character in the string or `NULL` if the character is not found.

```c
/**
 ** \_strchr - locates a character in a string
 * @s: the string to be parsed
 * @c: the character to look for
 * Return: a pointer to the first occurrence of the character c
 */
char *_strchr(char *s, char c)
{
    while (*s != '\0')
    {
        if (*s == c)
            return (s);
        s++;
    }
    return (NULL);
}
``
