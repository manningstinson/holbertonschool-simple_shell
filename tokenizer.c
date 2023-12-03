// tokenizer.c
#include "shell.h"

/**
 * tokenize - Splits a string into words.
 * @str: The input string.
 *
 * Return: An array of strings (tokens).
 */
char **tokenize(char *str)
{
    const char delim[] = " \t\n";  // Space, tab, and newline are used as delimiters
    char *token;
    char **tokens = NULL;
    size_t token_count = 0;

    if (!str)
        return NULL;

    // Allocate initial memory for tokens
    tokens = malloc(sizeof(char *));
    if (!tokens)
        return NULL;

    // Tokenize the input string
    token = strtok(str, delim);
    while (token) {
        // Resize the array of tokens
        tokens = realloc(tokens, (token_count + 1) * sizeof(char *));
        if (!tokens) {
            // Handle memory allocation failure
            perror("Failed to allocate memory");
            exit(EXIT_FAILURE);
        }

        // Duplicate the token and add it to the array
        tokens[token_count] = _strdup(token);
        if (!tokens[token_count]) {
            // Handle memory allocation failure
            perror("Failed to duplicate string");
            exit(EXIT_FAILURE);
        }

        // Move to the next token
        token = strtok(NULL, delim);
        token_count++;
    }

    // Add a NULL pointer at the end of the array to indicate the end
    tokens = realloc(tokens, (token_count + 1) * sizeof(char *));
    if (!tokens) {
        // Handle memory allocation failure
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    tokens[token_count] = NULL;

    return tokens;
}
