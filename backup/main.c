#include "shell.h"
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

/**
 * entry_point - Entry point of the shell program
 *
 * Return: 0 on success, 1 on error
 */
int entry_point(void)
{
    /* Initialize shell information */
    info_t shell_info = INFO_INIT;

    /* Check if a file is provided as an argument */
    int file_descriptor = 2;

    if (shell_info.argument_count == 2)
    {
        file_descriptor = open(shell_info.argument_vector[1], O_RDONLY);
        if (file_descriptor == -1)
        {
            if (errno == EACCES)
                exit(126);
            if (errno == ENOENT)
            {
                _eputs(shell_info.argument_vector[0]);
                _eputs(": 0: Unable to open ");
                _eputs(shell_info.argument_vector[1]);
                _eputchar('\n');
                _eputchar(BUF_FLUSH);
                exit(127);
            }
            return EXIT_FAILURE;
        }
        shell_info.readfd = file_descriptor;
    }

    /* Initialize environment and read command history */
    populate_env_list(&shell_info);
    read_history();

    /* Launch the shell */
    shell_loop(&shell_info);

    return EXIT_SUCCESS;
}

/**
 * main - Main function to start the shell program
 *
 * Return: 0 on success, 1 on error
 */
int main(void)
{
    return entry_point();
}
