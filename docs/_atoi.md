# Shell Utility Functions

This file (`shell.c`) contains utility functions crucial for a simple shell project. These functions cover various tasks, including checking if the shell is in interactive mode, identifying delimiters, verifying alphabetic characters, and converting strings to integers.

### `int interactive(info_t *info)`
```c
/**
 * interactive - returns true if shell is in interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
    return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
```
Determines if the shell is in interactive mode. Returns 1 if interactive mode, 0 otherwise.

### `int is_delim(char c, char *delim)`
```c
/**
 * is_delim - checks if character is a delimiter
 * @c: the char to check
 * @delim: the delimiter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char c, char *delim)
{
    while (*delim)
        if (*delim++ == c)
            return (1);
    return (0);
}
```
Checks if a character is a delimiter. Returns 1 if true, 0 if false.

### `int _isalpha(int c)`
```c
/**
 * _isalpha - checks for an alphabetic character
 * @c: The character to input
 * Return: 1 if `c` is alphabetic, 0 otherwise
 */
int _isalpha(int c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (1);
    else
        return (0);
}
```
Checks for an alphabetic character. Returns 1 if `c` is alphabetic, 0 otherwise.

### `int _atoi(char *s)`
```c
/**
 * _atoi - converts a string to an integer
 * @s: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */
int _atoi(char *s)
{
    // Implementation details...
}
```
Converts a string to an integer. Returns 0 if no numbers in the string, the converted number otherwise.
