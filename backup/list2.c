#include "shell.h"
#include <stdlib.h>

/* Function declarations */
char *_strdup(const char *str);
void free_string_array(char **array);
void _puts(const char *str);
void _putchar(char c);

/**
 * list_len - Get the number of nodes in the list.
 * @head: Pointer to the head of the list.
 * Return: Number of nodes in the list.
 */
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

/**
 * list_to_strings - Convert the linked list to an array of strings.
 * @head: Pointer to the head of the list.
 * Return: Array of strings.
 */
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
        strings[i] = strdup(head->str);
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

/**
 * print_node_start - Print the string of the start node.
 * @start: Pointer to the start node.
 */
void print_node_start(list_t *start)
{
    if (start != NULL)
    {
        _puts(start->str);
        _putchar('\n');
    }
}

/**
 * print_node_at_index - Print the string of the node at a specific index.
 * @head: Pointer to the head of the list.
 * @index: Index of the node to be printed.
 */
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
