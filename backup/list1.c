#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * add_node - Add a new node at the end of the list.
 * @head: Pointer to the head of the list.
 * @str: String to be added to the new node.
 * Return: Pointer to the new node, or NULL on failure.
 */
list_t *add_node(list_t **head, const char *str)
{
    list_t *new_node, *last_node = *head;

    new_node = malloc(sizeof(list_t));
    if (new_node == NULL)
    {
        perror("Unable to allocate memory");
        return NULL;
    }

    new_node->str = strdup(str);
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        while (last_node->next != NULL)
        {
            last_node = last_node->next;
        }
        last_node->next = new_node;
    }

    return new_node;
}

/**
 * add_node_at_index - Add a new node at a specific index in the list.
 * @head: Pointer to the head of the list.
 * @index: Index at which to add the new node.
 * @str: String to be added to the new node.
 * Return: Pointer to the new node, or NULL on failure.
 */
list_t *add_node_at_index(list_t **head, size_t index, const char *str)
{
    list_t *new_node, *current_node = *head;

    new_node = malloc(sizeof(list_t));
    if (new_node == NULL)
    {
        perror("Unable to allocate memory");
        return NULL;
    }

    new_node->str = strdup(str);
    new_node->next = NULL;

    size_t i;
    if (index == 0)
    {
        new_node->next = *head;
        *head = new_node;
        return new_node;
    }

    for (i = 0; i < index - 1; i++)
    {
        if (current_node == NULL)
        {
            free(new_node->str);
            free(new_node);
            return NULL;
        }
        current_node = current_node->next;
    }

    new_node->next = current_node->next;
    current_node->next = new_node;

    return new_node;
}
