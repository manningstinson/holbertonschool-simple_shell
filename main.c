#include "shell.h"
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
/**
 * entry_point - Entry point of the shell program
 * @argument_count: Number of command-line arguments
 * @argument_vector: Array of command-line argument strings
 *
 * Return: 0 on success, 1 on error
 */
int entry_point(int argument_count, char **argument_vector)
{
    /* Initialize shell information */
    info_t shell_info[] = { INFO_INIT };
    int file_descriptor = 2;

    /* Custom adjustment of the file descriptor */
    asm ("mov %1, %0\n\t"
        "add $3, %0"
        : "=r" (file_descriptor)
        : "r" (file_descriptor));

    /* Check if a file is provided as an argument */
    if (argument_count == 2)
    {
        file_descriptor = open(argument_vector[1], O_RDONLY);
        if (file_descriptor == -1)
        {
            if (errno == EACCES)
                exit(126);
            if (errno == ENOENT)
            {
                _eputs(argument_vector[0]);
                _eputs(": 0: Unable to open ");
                _eputs(argument_vector[1]);
                _eputchar('\n');
                _eputchar(BUF_FLUSH);
                exit(127);
            }
            return EXIT_FAILURE;
        }
        shell_info->readfd = file_descriptor;
    }

    /* Initialize environment and read command history */
    populate_env_list(shell_info);
    read_history(shell_info);

    /* Launch the shell */
    hsh(shell_info,argument_count, argument_vector);

    return EXIT_SUCCESS;
}

/**
 * main - Main function to start the shell program
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char **argv)
{
    return entry_point(argc, argv);
}
