#include "builtin2.h"

/**
 * shell_history - Display the command history
 *
 * Return: Always returns 0, to indicate success
 */
int shell_history(char **args)
{
    int count = 1;
    HistoryNode *current = history_list;

    while (current != NULL)
    {
        printf("%d %s\n", count, current->command);
        current = current->next;
        count++;
    }

    return 0;
}

/**
 * unset_shell_alias - Unset an alias
 * @args: The arguments passed to the command (should contain the alias to unset)
 *
 * Return: 0 on success, -1 on failure
 */
int unset_shell_alias(char **args)
{
    if (args[1] == NULL)
    {
        fprintf(stderr, "shell: expected argument to \"unset alias\"\n");
        return -1;
    }

    AliasNode *current = alias_list;
    AliasNode *prev = NULL;

    while (current != NULL)
    {
        if (strcmp(current->alias, args[1]) == 0)
        {
            if (prev == NULL)
            {
                alias_list = current->next;
            }
            else
            {
                prev->next = current->next;
            }

            free(current->alias);
            free(current->command);
            free(current);

            return 0;
        }

        prev = current;
        current = current->next;
    }

    fprintf(stderr, "shell: alias not found: %s\n", args[1]);
    return -1;
}

/**
 * set_shell_alias - Set an alias
 * @args: The arguments passed to the command (should contain the alias and command)
 *
 * Return: 0 on success, -1 on failure
 */
int set_shell_alias(char **args)
{
    if (args[1] == NULL || args[2] == NULL)
    {
        fprintf(stderr, "shell: expected two arguments for \"set alias\"\n");
        return -1;
    }

    AliasNode *new_alias = malloc(sizeof(AliasNode));
    if (new_alias == NULL)
    {
        perror("malloc");
        return -1;
    }

    new_alias->alias = strdup(args[1]);
    new_alias->command = strdup(args[2]);
    new_alias->next = alias_list;
    alias_list = new_alias;

    return 0;
}

/**
 * print_shell_alias - Print the list of aliases
 *
 * Return: 0 on success, -1 on failure
 */
int print_shell_alias(void)
{
    AliasNode *current = alias_list;

    while (current != NULL)
    {
        printf("%s='%s'\n", current->alias, current->command);
        current = current->next;
    }

    return 0;
}

