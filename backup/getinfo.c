#include "shell.h"
#include <stdlib.h>
#include <string.h>

/**
 * clear_info - Clear the information struct.
 * @info: Pointer to the information struct.
 */
void clear_info(info_t *info)
{
    if (info != NULL)
    {
        if (info->fname != NULL)
        {
            free(info->fname);
        }
        if (info->line != NULL)
        {
            free(info->line);
        }
        free(info);
    }
}

/**
 * set_info - Set values in the information struct.
 * @info: Pointer to the information struct.
 * @fname: File name associated with the information.
 * @line: Line number associated with the information.
 * @argv: Array of arguments.
 */
void set_info(info_t *info, char *fname, char *line, char **argv)
{
    if (info != NULL)
    {
        info->fname = strdup(fname);
        info->line = strdup(line);
        info->argv = arrdup(argv);
    }
}

/**
 * free_info - Free allocated memory in the information struct.
 * @info: Pointer to the information struct.
 */
void free_info(info_t *info)
{
    if (info != NULL)
    {
        if (info->fname != NULL)
        {
            free(info->fname);
        }
            if (info->line != NULL)
        {
            free(info->line);
        }
        if (info->argv != NULL)
        {
            free(info->argv);
        }
    }
}

/**
 * arrdup - Create a copy of an array of strings
 * @argv: The array to copy
 *
 * Return: A pointer to the new array, or NULL on failure
 */
char **arrdup(char **argv)
{
    char **new_arr;
    size_t i, len;

    /* Get the length of the array */
    len = 0;
    while (argv[len] != NULL)
        len++;

    /* Allocate memory for the new array */
    new_arr = malloc(sizeof(char *) * (len + 1));
    if (new_arr == NULL)
        return (NULL);

    /* Copy each element of the array */
    for (i = 0; i < len; i++)
    {
        new_arr[i] = strdup(argv[i]);
        if (new_arr[i] == NULL)
        {
            /* Free the allocated memory in case of failure */
            while (i > 0)
                free(new_arr[--i]);
            free(new_arr);
            return (NULL);
        }
    }

    /* Add a NULL terminator to the new array */
    new_arr[len] = NULL;

    /* Return the new array */
    return (new_arr);
}

