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

char **arrdup(char **argv) {
    return NULL;
}
