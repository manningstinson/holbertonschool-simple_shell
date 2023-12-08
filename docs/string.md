# string.c
The file contains several essential string manipulation functions for the custom shell.

## Code Block: _strlen
```c
/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *s)
{
    int i = 0;

    if (!s)
        return (0);

    while (*s++)
        i++;
    return (i);
}
```
This function calculates the length of a string by iterating through each character until the null terminator is reached. It returns the length of the string.

## Code Block: _strcmp
```c
/**
 * _strcmp - performs lexicographic comparison of two strings.
 * @s1: the first string
 * @s2: the second string
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
    while (*s1 && *s2)
    {
        if (*s1 != *s2)
            return (*s1 - *s2);
        s1++;
        s2++;
    }
    if (*s1 == *s2)
        return (0);
    else
        return (*s1 < *s2 ? -1 : 1);
}
```
This function compares two strings lexicographically. It returns a negative value if the first string is less than the second, a positive value if the first string is greater than the second, and zero if they are equal.

## Code Block: starts_with
```c
/**
 * starts_with - checks if needle starts with haystack
 * @haystack: string to search
 * @needle: the substring to find
 *
 * Return: address of next char of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
    while (*needle)
        if (*needle++ != *haystack++)
            return (NULL);
    return ((char *)haystack);
}
```
This function checks if a substring (`needle`) starts with a given string (`haystack`). It returns the address of the next character in `haystack` after the match or NULL if no match is found.

## Code Block: _strcat
```c
/**
 * _strcat - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
    char *ret = dest;

    while (*dest)
        dest++;
    while (*src)
        *dest++ = *src++;
    *dest = *src;
    return (ret);
}
```
This function concatenates two strings (`src` and `dest`). It appends the characters from `src` to the end of `dest`. The function returns a pointer to the destination buffer.
