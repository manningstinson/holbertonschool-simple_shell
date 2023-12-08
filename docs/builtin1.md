# builtin1.c
This file comprises essential functions for a simple shell implementation. The _myhistory function facilitates the display of command history, leveraging the print_list function. unset_alias and set_alias handle the removal and addition/update of aliases in a list, respectively. The print_alias function is responsible for printing an alias stored in a linked list node. Lastly, _myalias mimics the behavior of the alias built-in command, allowing users to view, set, or update aliases. This set of functions forms the core functionality of the shell, providing history tracking and alias management features.

## \_myhistory Function

The `_myhistory` function is responsible for displaying the command history. It takes a structure `info_t` as an argument and prints the command history stored in `info->history` using the `print_list` function.

```c
/**
 * \_myhistory - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always 0
 */
int _myhistory(info_t *info)
{
    print_list(info->history);
    return 0;
}
```

## unset_alias Function

The `unset_alias` function removes an alias from the list. It takes the structure `info_t` and a string `str` as parameters and returns 0 on success, 1 on error.

```c
/**
 * unset_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
    char *p, c;
    int ret;

    p = _strchr(str, '=');
    if (!p)
        return 1;
    c = *p;
    *p = 0;
    ret = delete_node_at_index(&(info->alias),
        get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
    *p = c;
    return ret;
}
```

## set_alias Function

The `set_alias` function sets or updates an alias in the list. It takes the structure `info_t` and a string `str` as parameters and returns 0 on success, 1 on error.

```c
/**
 * set_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
    char *p;

    p = _strchr(str, '=');
    if (!p)
        return 1;
    if (!*++p)
        return unset_alias(info, str);

    unset_alias(info, str);
    return (add_node_end(&(info->alias), str, 0) == NULL);
}
```

## print_alias Function

The `print_alias` function prints an alias stored in a linked list node. It takes a `list_t` node as a parameter and returns 0 on success, 1 on error.

```c
/**
 * print_alias - prints an alias string
 * @node: the alias node
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
    char *p = NULL, *a = NULL;

    if (node)
    {
        p = _strchr(node->str, '=');
        for (a = node->str; a <= p; a++)
            _putchar(*a);
        _putchar('\'');
        _puts(p + 1);
        _puts("'\n");
        return 0;
    }
    return 1;
}
```

## \_myalias Function

The `_myalias` function mimics the behavior of the `alias` built-in command. It takes a structure `info_t` as an argument. If called with no arguments, it prints all stored aliases. If called with arguments, it sets or prints aliases based on the input. The function always returns 0.

```c
/**
 * \_myalias - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _myalias(info_t *info)
{
    int i = 0;
    char *p = NULL;
    list_t *node = NULL;

    if (info->argc == 1)
    {
        node = info->alias;
        while (node)
        {
            print_alias(node);
            node = node->next;
        }
        return 0;
    }
    for (i = 1; info->argv[i]; i++)
    {
        p = _strchr(info->argv[i], '=');
        if (p)
            set_alias(info, info->argv[i]);
        else
            print_alias(node_starts_with(info->alias, info->argv[i], '='));
    }

    return 0;
}
```

Feel free to use this updated content in your README.md, and adjust it as needed based on your project's specific details.
