 # string1.c
The file contains string manipulation functions essential for the custom shell. These functions are responsible for copying strings, duplicating strings, and printing strings, contributing to the overall string processing capabilities of the shell.

## _strcpy
```c
/**
 * _strcpy - copies a string
 * @dest: the destination
 * @src: the source
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
    int i = 0;

    if (dest == src || src == 0)
        return (dest);
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = 0;
    return (dest);
}
```

This function, `_strcpy`, copies a string from the source (`src`) to the destination (`dest`). It iterates through the characters of the source string and copies them to the destination until it encounters the null terminator. The function returns a pointer to the destination string.

## _strdup
```c
/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
    int length = 0;
    char *ret;

    if (str == NULL)
        return (NULL);
    while (*str++)
        length++;
    ret = malloc(sizeof(char) * (length + 1));
    if (!ret)
        return (NULL);
    for (length++; length--;)
        ret[length] = *--str;
    return (ret);
}
```

The `_strdup` function duplicates a given string (`str`). It calculates the length of the string, allocates memory for a new string of the same length, and then copies each character from the original string to the new one. The function returns a pointer to the duplicated string.

## _puts
```c
/**
 *_puts - prints an input string
 *@str: the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *str)
{
    int i = 0;

    if (!str)
        return;
    while (str[i] != '\0')
    {
        _putchar(str[i]);
        i++;
    }
}
```

The `_puts` function prints a string (`str`) to the standard output. It iterates through the characters of the string and uses the `_putchar` function to write each character to the output.

## _putchar
```c
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
    static int i;
    static char buf[WRITE_BUF_SIZE];

    if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
    {
        write(1, buf, i);
        i = 0;
    }
    if (c != BUF_FLUSH)
        buf[i++] = c;
    return (1);
}
```

The `_putchar` function writes a character (`c`) to the standard output. It utilizes a buffer (`buf`) to store characters before flushing them to the output. The buffer is flushed either when the buffer is full or when the special character `BUF_FLUSH` is encountered. The function returns 1 on success and -1 on error.
