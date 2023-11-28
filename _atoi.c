// File: atoi.c

#include <stdio.h>

int atoi(const char *str) {
    int result = 0;
    int sign = 1;  // Default sign is positive

    // Skip leading white spaces
    while (*str == ' ' || (*str >= '\t' && *str <= '\r')) {
        str++;
    }

    // Handle the sign
    if (*str == '-' || *str == '+') {
        sign = (*str++ == '-') ? -1 : 1;
    }

    // Convert the string to an integer
    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str++ - '0');
    }

    return sign * result;
}

int main() {
    const char *str = "12345";
    int num = atoi(str);
    printf("Converted number: %d\n", num);

    return 0;
}
