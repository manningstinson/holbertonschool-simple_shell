# realloc.c

The realloc.c file houses essential memory manipulation functions. The _memset function fills a given memory area with a constant byte. 

The ffree function facilitates the proper freeing of a string of strings, preventing memory leaks. Finally, the _realloc function dynamically reallocates memory, allowing for resizing memory blocks efficiently. 

These functions are foundational for effective memory management in C programs, ensuring optimal usage and preventing memory-related issues.

```c
#include "shell.h"

/**
 **_memset - fills memory with a constant byte
 *@s: the pointer to the memory area
 *@b: the byte to fill *s with
 *@n: the amount of bytes to be filled
 *Return: (s) a pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
    unsigned int i;

    for (i = 0; i < n; i++)
        s[i] = b;
    return (s);
}
```

The `_memset` function is designed to fill a specified memory area with a constant byte. It takes three parameters: the pointer to the memory area (`s`), the byte to fill the memory with (`b`), and the number of bytes to be filled (`n`). It utilizes a simple loop to iterate through the memory area, assigning the constant byte to each element. This function is a fundamental building block for initializing and manipulating memory regions efficiently.

```c
/**
 * ffree - frees a string of strings
 * @pp: string of strings
 */
void ffree(char **pp)
{
    char **a = pp;

    if (!pp)
        return;
    while (*pp)
        free(*pp++);
    free(a);
}
```

The `ffree` function plays a crucial role in freeing a string of strings (`char**`). It takes the address of the string of strings (`pp`) as its parameter. The function begins by creating a duplicate pointer (`a`) to the original pointer to safeguard against losing the starting address. It then iterates through the string array, freeing each string, and finally frees the original pointer itself. This function ensures proper deallocation of memory associated with dynamic string arrays, preventing memory leaks.

```c
/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 *
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
    char *p;

    if (!ptr)
        return (malloc(new_size));
    if (!new_size)
        return (free(ptr), NULL);
    if (new_size == old_size)
        return (ptr);

    p = malloc(new_size);
    if (!p)
        return (NULL);

    old_size = old_size < new_size ? old_size : new_size;
    while (old_size--)
        p[old_size] = ((char *)ptr)[old_size];
    free(ptr);
    return (p);
}
```
The `_realloc` function dynamically reallocates memory, allowing for the resizing of memory blocks. It takes three parameters: the pointer to the previous dynamically allocated block (`ptr`), the byte size of the previous block (`old_size`), and the desired byte size of the new block (`new_size`). The function first handles special cases, such as allocating new memory if the original pointer is `NULL` or freeing the pointer if the new size is zero. It then allocates a new memory block, copies the necessary data from the old block, and frees the original block. This function is crucial for adapting memory allocations during program execution, optimizing memory usage.

