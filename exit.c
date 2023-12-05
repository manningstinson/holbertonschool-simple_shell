#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * my_exit - Exit the shell
 * @args: The arguments passed to the command
 *
 * Return: Always returns 0, to indicate success
 */
int my_exit(__attribute__((unused)) char **args)
{
    exit(EXIT_SUCCESS);
    return 0;
}
