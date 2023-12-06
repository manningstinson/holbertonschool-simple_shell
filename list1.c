#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * add_node_at_index - Add a new node at a specific index in the list.
 * @head: Pointer to the head of the list.
 * @index: Index at which to add the new node.
 * @str: String to be added to the new node.
 * Return: Pointer to the new node, or NULL on failure.
 */
list_t *add_node_at_index(list_t **head __attribute__((unused)), size_t index __attribute__((unused)), const char *str __attribute__((unused)))
{
    size_t i;
    list_t *new_node, *current_node;

    new_node = malloc(sizeof(list_t));
    if (new_node == NULL)
    {
        perror("Unable to allocate memory");
        return NULL;
    }

    new_node->str = strdup(str);
    new_node->next = NULL;

    if (index == 0)
    {
        new_node->next = *head;
        *head = new_node;
        return new_node;
    }

    current_node = *head;

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

/**
 * delete_node - Delete a node at a specific index in the list.
 * @head: Pointer to the head of the list.
 * @index: Index at which to delete the node.
 * Return: 1 on success, 0 on failure.
 */
int delete_node(list_t **head __attribute__((unused)), size_t index __attribute__((unused)))
{
    list_t *current_node, *prev_node;

    if (*head == NULL)
    {
        return 0; /* Empty list, nothing to delete */
    }

    current_node = *head;
    prev_node = NULL;
    size_t i;

    /* Traverse the list to the specified index */
    for (i = 0; i < index; i++)
    {
        if (current_node == NULL)
        {
            return 0; /* Index out of bounds */
        }
        prev_node = current_node;
        current_node = current_node->next;
    }

    if (prev_node == NULL)
    {
        *head = current_node->next;
    }
    else
    {
        prev_node->next = current_node->next;
    }

    free(current_node->str);
    free(current_node);

    return 1; /* Node successfully deleted */
}

int main(void)
{
    list_t *head = NULL;
    list_t *current, *next;

    /* Add nodes to the list */
    add_node_at_index(&head, 0, "Node 1");
    add_node_at_index(&head, 1, "Node 2");
    add_node_at_index(&head, 1, "Node 3");

    /* Print the list */
    current = head;
    while (current != NULL)
    {
        printf("%s\n", current->str);
        current = current->next;
    }

    /* Delete a node */
    delete_node(&head, 1);

    /* Print the updated list */
    current = head;
    while (current != NULL)
    {
        printf("%s\n", current->str);
        current = current->next;
    }

    /* Free the memory */
    current = head;
    while (current != NULL)
    {
        next = current->next;
        free(current->str);
        free(current);
        current = next;
    }

    return 0;
}

