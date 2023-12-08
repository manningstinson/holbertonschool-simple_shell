# get_info.c

In summary, `get_info.c` is a crucial component in the Simple Shell program, providing functions to initialize, set values, and free memory for the `info_t` struct. These functions contribute to the overall functionality and memory management of the Simple Shell, ensuring proper initialization and cleanup of the information structure.

## `clear_info` Function

The `clear_info` function initializes the `info_t` struct by setting its fields to default values.

```c
#include "shell.h"

/**
 * clear_info - initializes info_t struct
 * @info: struct address
 */
void clear_info(info_t *info)
{
    info->arg = NULL;
    info->argv = NULL;
    info->path = NULL;
    info->argc = 0;
}
```

## `set_info` Function

The `set_info` function initializes the `info_t` struct using the provided argument vector (`av`). It sets various fields, including parsing the argument string, creating an argument vector, and replacing aliases and variables.

```c
/**
 * set_info - initializes info_t struct
 * @info: struct address
 * @av: argument vector
 */
void set_info(info_t *info, char **av)
{
    int i = 0;

    info->fname = av[0];
    if (info->arg)
    {
        info->argv = strtow(info->arg, " \t");
        if (!info->argv)
        {

            info->argv = malloc(sizeof(char *) * 2);
            if (info->argv)
            {
                info->argv[0] = _strdup(info->arg);
                info->argv[1] = NULL;
            }
        }
        for (i = 0; info->argv && info->argv[i]; i++)
            ;
        info->argc = i;

        replace_alias(info);
        replace_vars(info);
    }
}
```

## `free_info` Function

The `free_info` function frees dynamically allocated memory associated with the fields of the `info_t` struct. The `all` parameter indicates whether to free all fields or only specific ones.

```c
/**
 * free_info - frees info_t struct fields
 * @info: struct address
 * @all: true if freeing all fields
 */
void free_info(info_t *info, int all)
{
    ffree(info->argv);
    info->argv = NULL;
    info->path = NULL;
    if (all)
    {
        if (!info->cmd_buf)
            free(info->arg);
        if (info->env)
            free_list(&(info->env));
        if (info->history)
            free_list(&(info->history));
        if (info->alias)
            free_list(&(info->alias));
        ffree(info->environ);
        info->environ = NULL;
        bfree((void **)info->cmd_buf);
        if (info->readfd > 2)
            close(info->readfd);
        _putchar(BUF_FLUSH);
    }
}
```
