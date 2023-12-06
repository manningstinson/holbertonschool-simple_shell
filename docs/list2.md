# List 2 (list2.c)

The provided code supports basic linked list operations and string manipulations. The linked list structure (`list_t`) is used to store strings, and functions are provided to calculate the length of the list, convert it to an array of strings, and print nodes at the start or a specified index. These functionalities can be part of a larger project, potentially a simple shell, where linked lists are used to manage command arguments or history. The implementation includes error handling for memory allocation failures.

### Header file: shell.h

```c
#ifndef SHELL_H
#define SHELL_H

/* Definition of the linked list structure */
typedef struct list_s
{
    char *str;
    struct list_s *next;
} list_t;

/* Function declarations */
size_t list_len(list_t *head);
char **list_to_strings(list_t *head);
void print_node_start(list_t *start);
void print_node_at_index(list_t *head, size_t index);

#endif /* SHELL_H */
```

This header file declares the structure `list_t` for a linked list node containing a string and a pointer to the next node. It also declares functions that are implemented in the corresponding C file.

### Implementation file: shell.c

```c
#include "shell.h"
#include <stdlib.h>

/* Function declarations */
char *_strdup(const char *str);
void free_string_array(char **array);
void _puts(const char *str);
void _putchar(char c);
```

Here, standard library functions and additional functions like `_strdup`, `free_string_array`, `_puts`, and `_putchar` are declared. These functions are likely defined elsewhere and handle string operations, memory management, and output.

### Function: list_len

```c
size_t list_len(list_t *head)
{
    size_t count = 0;

    while (head != NULL)
    {
        count++;
        head = head->next;
    }

    return count;
}
```

This function calculates the number of nodes in a linked list by iterating through the list and incrementing a counter.

### Function: list_to_strings

```c
char **list_to_strings(list_t *head)
{
    size_t len = list_len(head);
    char **strings = malloc((len + 1) * sizeof(char *));
    size_t i = 0;

    if (strings == NULL)
    {
        perror("Unable to allocate memory");
        return NULL;
    }

    while (head != NULL)
    {
        strings[i] = _strdup(head->str);
        if (strings[i] == NULL)
        {
            perror("Unable to allocate memory");
            free_string_array(strings);
            return NULL;
        }
        i++;
        head = head->next;
    }

    strings[i] = NULL;

    return strings;
}
```

This function converts a linked list of strings into an array of strings. It uses dynamic memory allocation and the `_strdup` function to duplicate each string.

### Function: print_node_start

```c
void print_node_start(list_t *start)
{
    if (start != NULL)
    {
        _puts(start->str);
        _putchar('\n');
    }
}
```

This function prints the string content of the start node in the linked list, followed by a newline character.

### Function: print_node_at_index

```c
void print_node_at_index(list_t *head, size_t index)
{
    size_t i = 0;

    while (head != NULL)
    {
        if (i == index)
        {
            _puts(head->str);
            _putchar('\n');
            return;
        }

        i++;
        head = head->next;
    }
}
```

This function prints the string content of the node at a specific index in the linked list.
