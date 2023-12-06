#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * get_history - Get the command history.
 * @info: Pointer to the information struct.
 * Return: A pointer to the command history.
 */
char **get_history(info_t *info)
{
    return info->history;
}

/**
 * write_history - Write the command history to a file.
 * @info: Pointer to the information struct.
 * @filename: Name of the file to write the history to.
 */
void write_history(info_t *info);
{
    FILE *file = fopen(filename, "w");
    char **history = get_history(info);

    if (file == NULL)
    {
        perror("Error opening history file");
        return;
    }

    for (size_t i = 0; history[i] != NULL; i++)
    {
        fprintf(file, "%s\n", history[i]);
    }

    fclose(file);
}

/**
 * read_history - Read the command history from a file.
 * @info: Pointer to the information struct.
 * @filename: Name of the file to read the history from.
 */
void read_history(info_t *info);
{
    FILE *file = fopen(filename, "r");
    char *line = NULL;
    size_t bufsize = 0;

    if (file == NULL)
    {
        perror("Error opening history file");
        return;
    }

    while (getline(&line, &bufsize, file) != -1)
    {
        add_to_history(info, line);
    }

    free(line);
    fclose(file);
}
