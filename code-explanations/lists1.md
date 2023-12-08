# list1.c

These functions provide essential linked list operations, including calculating the length, converting to an array of strings, printing elements, finding nodes with specific prefixes, and obtaining the index of a given node.

### `list_len` Function

This function calculates the length of a linked list by iterating through its nodes.

```c
/**
 * list_len - determines length of linked list
 * @h: pointer to the first node
 *
 * Return: size of the list
 */
size_t list_len(const list_t *h) {
    size_t i = 0;

    while (h) {
        h = h->next;
        i++;
    }

    return (i);
}
```

### `list_to_strings` Function

This function converts a linked list of strings into an array of strings.

```c
/**
 * list_to_strings - returns an array of strings of the list->str
 * @head: pointer to the first node
 *
 * Return: array of strings
 */
char **list_to_strings(list_t *head) {
    list_t *node = head;
    size_t i = list_len(head), j;
    char **strs;
    char *str;

    if (!head || !i)
        return (NULL);

    strs = malloc(sizeof(char *) * (i + 1));
    if (!strs)
        return (NULL);

    for (i = 0; node; node = node->next, i++) {
        str = malloc(_strlen(node->str) + 1);
        if (!str) {
            for (j = 0; j < i; j++)
                free(strs[j]);
            free(strs);
            return (NULL);
        }

        str = _strcpy(str, node->str);
        strs[i] = str;
    }

    strs[i] = NULL;
    return (strs);
}
```

### `print_list` Function

This function prints all elements of a linked list, including their numerical indices.

```c
/**
 * print_list - prints all elements of a list_t linked list
 * @h: pointer to the first node
 *
 * Return: size of the list
 */
size_t print_list(const list_t *h) {
    size_t i = 0;

    while (h) {
        _puts(convert_number(h->num, 10, 0));
        _putchar(':');
        _putchar(' ');
        _puts(h->str ? h->str : "(nil)");
        _puts("\n");
        h = h->next;
        i++;
    }

    return (i);
}
```

### `node_starts_with` Function

This function returns the node whose string starts with a given prefix and optionally matches a specified character.

```c
/**
 * node_starts_with - returns a node whose string starts with a prefix
 * @node: pointer to list head
 * @prefix: string to match
 * @c: the next character after the prefix to match (-1 for any)
 *
 * Return: matching node or null
 */
list_t *node_starts_with(list_t *node, char *prefix, char c) {
    char *p = NULL;

    while (node) {
        p = starts_with(node->str, prefix);
        if (p && ((c == -1) || (*p == c)))
            return (node);
        node = node->next;
    }

    return (NULL);
}
```

### `get_node_index` Function

This function retrieves the index of a specified node in a linked list.

```c
/**
 * get_node_index - gets the index of a node
 * @head: pointer to list head
 * @node: pointer to the node
 *
 * Return: index of the node or -1
 */
ssize_t get_node_index(list_t *head, list_t *node) {
    size_t i = 0;

    while (head) {
        if (head == node)
            return (i);
        head = head->next;
        i++;
    }

    return (-1);
}
```
