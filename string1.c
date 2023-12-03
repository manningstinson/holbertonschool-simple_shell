#include "shell.h"
#include <stddef.h>

/**
 * _strlen - Get the length of a string
 * @str: String to get the length of
 * Return: Length of the string
 */
size_t _strlen(const char *str)
{
    size_t length = 0;
    while (str && *str)
    {
        length++;
        str++;
    }
    return length;
}

/**
 * _strcmp - Compare two strings lexicographically
 * @s1: First string
 * @s2: Second string
 * Return: Negative value if s1 < s2, 0 if s1 == s2, positive value if s1 > s2
 */
int _strcmp(const char *s1, const char *s2)
{
    while (s1 && s2 && *s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    return (s1 && s2) ? (*s1 - *s2) : 0;
}

/**
 * _startswith - Check if needle starts with haystack
 * @haystack: String to check the start of
 * @needle: Prefix string to check for
 * Return: 1 if needle starts with haystack, 0 otherwise
 */
int _startswith(const char *haystack, const char *needle)
{
    while (haystack && needle && *needle)
    {
        if (*haystack != *needle)
            return 0;
        haystack++;
        needle++;
    }
    return (needle && !*needle);
}

/**
 * _strcat - Concatenate two strings
 * @dest: Destination string to append to
 * @src: Source string to append
 * Return: Pointer to the concatenated string
 */
char *_strcat(char *dest, const char *src)
{
    char *result = dest;

    while (dest && *dest)
        dest++;

    while (src && *src)
    {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';

    return result;
}
