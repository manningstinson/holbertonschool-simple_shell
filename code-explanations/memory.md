# memory.c
This function, `bfree`, takes the address of a pointer (`ptr`) and frees the memory it points to using the `free` function. It then sets the pointer to `NULL` to prevent any accidental use after freeing. The function returns `1` to indicate that the memory has been successfully freed or `0` if the pointer was already `NULL` or not provided. This utility is useful for safe memory deallocation and helps prevent memory leaks.

#### Function: `bfree`

```c
/**
 * bfree - frees a pointer and NULLs the address
 * @ptr: address of the pointer to free
 *
 * Return: 1 if freed, otherwise 0.
 */
int bfree(void **ptr) {
    if (ptr && *ptr) {
        // Free the memory pointed to by the given pointer
        free(*ptr);
        *ptr = NULL; // Set the pointer to NULL after freeing
        return 1;    // Return 1 to indicate successful freeing
    }
    return 0;        // Return 0 if the pointer was already NULL or not provided
}
```
