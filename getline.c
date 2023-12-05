#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

void _prompt(void);
void clear_info(info_t *info);

/**
 * _getline - Read a line of input from standard input.
 * @info: Pointer to the information struct.
 * Return: A pointer to the read line.
 */
char *_getline(info_t *info)
{
    size_t bufsize = 0; /* Initial size of the buffer */
    ssize_t characters_read;
    char *line = NULL;

    if (info != NULL)
    {
        _prompt();
        characters_read = getline(&line, &bufsize, stdin);

        if (characters_read == -1)
        {
            _eputchar('\n');
            clear_info(info);
            free(line);
            exit(EXIT_SUCCESS);
        }

        if (line[characters_read - 1] == '\n')
        {
            line[characters_read - 1] = '\0';
        }
    }

    return line;
}

