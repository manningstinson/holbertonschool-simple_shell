#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * custom_realloc - Reallocate a block of memory
 * @ptr: Pointer to the previously allocated memory block
 * @size: New size of the memory block
 *
 * Return: Pointer to the reallocated memory block
 */
void *custom_realloc(void *ptr, size_t size)
{
    void *new_ptr = realloc(ptr, size);

    if (new_ptr == NULL)
    {
        perror("realloc");
        exit(EXIT_FAILURE);
    }

    return new_ptr;
}

/**
 * custom_free_strings - Free a string array
 * @str_arr: String array to free
 */
void custom_free_strings(char **str_arr)
{
    if (str_arr == NULL)
        return;

    for (size_t i = 0; str_arr[i] != NULL; i++)
    {
        free(str_arr[i]);
    }

    free(str_arr);
}

/**
 * custom_memset - Fill memory with a constant byte
 * @ptr: Pointer to the memory block
 * @value: Byte value to fill the memory with
 * @size: Size of the memory block
 */
void custom_memset(void *ptr, int value, size_t size)
{
    memset(ptr, value, size);
}

