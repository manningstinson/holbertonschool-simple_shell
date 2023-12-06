# ATOI

**_atoi Function:**
- Converts a string to an integer.
- Takes into account both positive and negative signs in the string.
- Ignores non-numeric characters after encountering the first non-numeric character in the string.

This function is essential for processing numeric inputs in the shell, particularly when converting user-provided strings to integers during command execution.

```c
#include "shell.h"

/**
 * @brief Checks if the shell is in interactive mode.
 *
 * @param info Pointer to the struct holding shell information.
 * @return 1 if in interactive mode, 0 otherwise.
 */
int interactive(info_t *info)
{
    return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
```

The `interactive` function checks whether the shell is running in interactive mode by verifying if the input is from a terminal.

```c
/**
 * @brief Checks if a character is a delimiter.
 *
 * @param c The character to check.
 * @param delim The delimiter string.
 * @return 1 if true, 0 if false.
 */
int is_delim(char c, char *delim)
{
    while (*delim)
        if (*delim++ == c)
            return (1);
    return (0);
}
```

The `is_delim` function checks if a given character is a delimiter by iterating through the provided delimiter string.

```c
/**
 * @brief Checks if a character is alphabetic.
 *
 * @param c The character to check.
 * @return 1 if c is alphabetic, 0 otherwise.
 */
int _isalpha(int c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
```

The `_isalpha` function checks if a given character is alphabetic.

```c
/**
 * @brief Converts a string to an integer.
 *
 * @param s The string to be converted.
 * @return 0 if no numbers in the string, converted number otherwise.
 */
int _atoi(char *s)
{
    int i, sign = 1, flag = 0, output;
    unsigned int result = 0;

    for (i = 0; s[i] != '\0' && flag != 2; i++)
    {
        if (s[i] == '-')
            sign *= -1;

        if (s[i] >= '0' && s[i] <= '9')
        {
            flag = 1;
            result *= 10;
            result += (s[i] - '0');
        }
        else if (flag == 1)
            flag = 2;
    }

    if (sign == -1)
        output = -result;
    else
        output = result;
    return (output);
}
```
