### File: lists.c

This file, **lists.c**, contains functions for managing linked lists in the shell program. Below is a detailed explanation of each function:

### `add_node` Function

This function adds a new node to the start of the linked list. It allocates memory for the new node, sets its fields, and adjusts the head pointer accordingly.

```c
/**
 * add_node - adds a node to the start of the list
 * @head: address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: size of list
 */
list_t *add_node(list_t **head, const char *str, int num) {
    list_t *new_head;

    if (!head)
        return (NULL);

    new_head = malloc(sizeof(list_t));
    if (!new_head)
        return (NULL);

    _memset((void *)new_head, 0, sizeof(list_t));
    new_head->num = num;

    if (str) {
        new_head->str = _strdup(str);
        if (!new_head->str) {
            free(new_head);
            return (NULL);
        }
    }

    new_head->next = *head;
    *head = new_head;

    return (new_head);
}
```

### `add_node_end` Function

This function adds a new node to the end of the linked list. It allocates memory for the new node, sets its fields, and appends it to the end of the list.

```c
/**
 * add_node_end - adds a node to the end of the list
 * @head: address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: size of list
 */
list_t *add_node_end(list_t **head, const char *str, int num) {
    list_t *new_node, *node;

    if (!head)
        return (NULL);

    node = *head;
    new_node = malloc(sizeof(list_t));
    if (!new_node)
        return (NULL);

    _memset((void *)new_node, 0, sizeof(list_t));
    new_node->num = num;

    if (str) {
        new_node->str = _strdup(str);
        if (!new_node->str) {
            free(new_node);
            return (NULL);
        }
    }

    if (node) {
        while (node->next)
            node = node->next;
        node->next = new_node;
    } else
        *head = new_node;

    return (new_node);
}
```

### `print_list_str` Function

This function prints only the `str` element of each node in the linked list.

```c
/**
 * print_list_str - prints only the str element of a list_t linked list
 * @h: pointer to the first node
 *
 * Return: size of list
 */
size_t print_list_str(const list_t *h) {
    size_t i = 0;

    while (h) {
        _puts(h->str ? h->str : "(nil)");
        _puts("\n");
        h = h->next;
        i++;
    }

    return (i);
}
```

### `delete_node_at_index` Function

This function deletes a node at a given index in the linked list. It adjusts pointers and frees memory accordingly.

```c
/**
 * delete_node_at_index - deletes a node at the given index
 * @head: address of pointer to the first node
 * @index: index of the node to delete
 *
 * Return: 1 on success, 0 on failure
 */
int delete_node_at_index(list_t **head, unsigned int index) {
    list_t *node, *prev_node;
    unsigned int i = 0;

    if (!head || !*head)
        return (0);

    if (!index) {
        node = *head;
        *head = (*head)->next;
        free(node->str);
        free(node);
        return (1);
    }

    node = *head;

    while (node) {
        if (i == index) {
            prev_node->next = node->next;
            free(node->str);
            free(node);
            return (1);
        }

        i++;
        prev_node = node;
        node = node->next;
    }

    return (0);
}
```

### `free_list` Function

This function frees all nodes of the linked list and sets the head pointer to `NULL`.

```c
/**
 * free_list - frees all nodes of a list
 * @head_ptr: address of pointer to the head node
 *
 * Return: void
 */
void free_list(list_t **head_ptr) {
    list_t *node, *next_node, *head;

    if (!head_ptr || !*head_ptr)
        return;

    head = *head_ptr;
    node = head;

    while (node) {
        next_node = node->next;
        free(node->str);
        free(node);
        node = next_node;
    }

    *head_ptr = NULL;
}
```

These functions collectively provide the functionality to manipulate linked lists, including adding nodes to the beginning and end, printing the content of the list, deleting a node at a specific index, and freeing the entire list.
