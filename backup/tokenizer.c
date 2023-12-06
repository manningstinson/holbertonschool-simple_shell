#include "shell.h"

/**
 * tokenize - Splits a string into words.
 * @str: The input string.
 *
 * Return: An array of strings (tokens).
 */
char **tokenize(char *str)
{
    const char delim[] = " \t\n";
    char *token;
    char **tokens = NULL;
    size_t token_count = 0;

    if (!str)
        return NULL;

    tokens = malloc(sizeof(char *));
    if (!tokens)
        return NULL;

    token = strtok(str, delim);
    while (token) {
        tokens = realloc(tokens, (token_count + 1) * sizeof(char *));
        if (!tokens) {
            perror("Failed to allocate memory");
            exit(EXIT_FAILURE);
        }

        tokens[token_count] = strdup(token);
        if (!tokens[token_count]) {
            perror("Failed to duplicate string");
            exit(EXIT_FAILURE);
        }

        token = strtok(NULL, delim);
        token_count++;
    }

    tokens = realloc(tokens, (token_count + 1) * sizeof(char *));
    if (!tokens) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    tokens[token_count] = NULL;

    return tokens;
}

