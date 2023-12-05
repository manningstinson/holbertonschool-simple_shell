#include "shell.h"

/**
 * add_node - Add a new node at the end of the list.
 * @head: Pointer to the head of the list.
 * @str: String to be stored in the new node.
 * Return: A pointer to the new node.
 */
list_t *add_node(list_t **head, const char *str)
{
    list_t *new_node = malloc(sizeof(list_t));
    list_t *last = *head;

    if (new_node == NULL)
    {
        perror("Error creating new node");
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
        while (last->next != NULL)
        {
            last = last->next;
        }

        last->next = new_node;
    }

    return new_node;
}

/**
 * add_node_at_index - Add a new node at a specific index in the list.
 * @head: Pointer to the head of the list.
 * @index: Index at which the new node should be added.
 * @str: String to be stored in the new node.
 * Return: A pointer to the new node.
 */
list_t *add_node_at_index(list_t **head, size_t index, const char *str)
{
    // Your implementation to add a node at a specific index
    // This might involve traversing the list to the desired position
    // and updating the pointers accordingly.
}

/**
 * print_list_str - Print the list as strings.
 * @head: Pointer to the head of the list.
 */
void print_list_str(list_t *head)
{
    list_t *current = head;

    while (current != NULL)
    {
        printf("%s\n", current->str);
        current = current->next;
    }
}

/**
 * delete_node - Delete a node at a specific index in the list.
 * @head: Pointer to the head of the list.
 * @index: Index of the node to be deleted.
 * Return: 1 if successful, 0 if the index is out of bounds.
 */
int delete_node(list_t **head, size_t index)
{
    // Your implementation to delete a node at a specific index
    // This might involve traversing the list to the desired position
    // and updating the pointers accordingly.
}

/**
 * free_list - Free the entire list.
 * @head: Pointer to the head of the list.
 */
void free_list(list_t **head)
{
    list_t *current = *head;
    list_t *next;

    while (current != NULL)
    {
        next = current->next;
        free(current->str);
        free(current);
        current = next;
    }

    *head = NULL;
}
