#include "vars.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isChainDelimiter(char c) {
        return (c == ';' || c == '&' || c == '|');
}

int shouldContinueChaining(int lastStatus) {
    
    return (lastStatus == 0);
}

void replaceAliases(char **tokens) {
    
    for (int i = 0; tokens[i] != NULL; ++i) {
        if (strcmp(tokens[i], "ls") == 0) {
            free(tokens[i]);
            tokens[i] = strdup("ls -l");
        }
    }
}

void replaceVars(char **tokens) {
    
    for (int i = 0; tokens[i] != NULL; ++i) {
        if (strcmp(tokens[i], "$HOME") == 0) {            
            free(tokens[i]);
            tokens[i] = strdup("/home/user");
        }
    }
}

void replaceAliasesAndVars(char **tokens) {
    replaceAliases(tokens);
    replaceVars(tokens);
}

