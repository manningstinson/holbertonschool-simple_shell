#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * unset_shell_alias - Unset a shell alias.
 * @alias_list: Pointer to the head of the alias list.
 * @alias: Alias to unset.
 * Return: 0 on success, -1 on failure.
 */
int unset_shell_alias(AliasNode **alias_list, const char *alias)
{
    AliasNode *current = *alias_list, *prev = NULL;

    while (current != NULL)
    {
        if (_strcmp(current->alias, alias) == 0)
        {
            if (prev == NULL)
            {
                *alias_list = current->next;
            }
            else
            {
                prev->next = current->next;
            }

            free(current->alias);
            free(current->value);
            free(current);
            return 0;
        }

        prev = current;
        current = current->next;
    }

    return -1; /* Alias not found */
}

/**
 * set_shell_alias - Set a shell alias.
 * @alias_list: Pointer to the head of the alias list.
 * @alias: Alias to set.
 * @value: Value of the alias.
 * Return: 0 on success, -1 on failure.
 */
int set_shell_alias(AliasNode **alias_list, const char *alias, const char *value)
{
    AliasNode *current = *alias_list;
    AliasNode *new_alias = malloc(sizeof(AliasNode));

    if (new_alias == NULL)
    {
        perror("Unable to allocate memory");
        return -1;
    }

    new_alias->alias = strdup(alias);
    new_alias->value = strdup(value);
    new_alias->next = NULL;

    if (*alias_list == NULL)
    {
        *alias_list = new_alias;
    }
    else
    {
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_alias;
    }

    return 0;
}

