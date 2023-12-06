#include "shell.h"

void custom_puts(char *str)
{
    int i = 0;

    if (!str)
        return;
    while (str[i] != '\0')
    {
        custom_putchar(str[i]);
        i++;
    }
}

int custom_putchar(char c)
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
    return 1;
}

int custom_putchar_fd(char c, int fd)
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
    return 1;
}

int custom_puts_fd(char *str, int fd)
{
    int i = 0;

    if (!str)
        return 0;
    while (*str)
    {
        i += custom_putchar_fd(*str++, fd);
    }
    return i;
}

