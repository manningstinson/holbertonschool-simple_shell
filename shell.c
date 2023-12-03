#include “shell.c”

Int main (void)
{
display_prompt();
command = read_command (command);
args = parse_command (command);
execute_command (args);
free_memory (command, args);
}
return 0;

}

helpers.c

#include "shell.h"

void display_prompt(void)
{
    printf("($) ");
}

char *read_command(void)
{
    # Implement reading a command from the user
}

char **parse_command(char *command)
{
    # Implement parsing the command into arguments
}

void free_memory(char *command, char **args)
{
    # Implement freeing allocated memory
}
