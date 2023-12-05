# ATOI

```bash
#!/bin/bash
#include "shell.h"
```

This section specifies that the script is written in the Bash shell, and it includes a file named "shell.h". The `#!/bin/bash` is called a shebang, and it indicates the path to the interpreter for the script.

```bash
# Function to check if shell is in interactive mode
interactive() {
    [ -t 0 ] && [ "$1" -le 2 ]
}
```

This is a function named `interactive` that checks whether the shell is in interactive mode. It uses the `[ -t 0 ]` test, which checks if file descriptor 0 (standard input) is associated with a terminal. The second part `[ "$1" -le 2 ]` checks if the provided argument is less than or equal to 2.

```bash
# Function to check if a character is a delimiter
is_delim() {
    local c="$1"
    local delim="$2"

    while [ -n "$delim" ]; do
        [ "$c" == "${delim:0:1}" ] && return 1
        delim="${delim:1}"
    done

    return 0
}
```

This function, `is_delim`, checks if a given character `c` is a delimiter. It compares the character to each character in the `delim` string.

```bash
# Function to check if a character is alphabetic
_isalpha() {
    local c="$1"
    [[ "$c" =~ [[:alpha:]] ]]
}
```

This function, `_isalpha`, checks if a given character `c` is alphabetic using a regular expression.

```bash
# Function to convert a string to an integer
_atoi() {
    local s="$1"
    local i=0
    local sign=1
    local flag=0
    local result=0

    while [ "${s:i:1}" != "" ] && [ "$flag" -ne 2 ]; do
        if [ "${s:i:1}" == "-" ]; then
            sign=$((sign * -1))
        fi

        if [[ "${s:i:1}" =~ [0-9] ]]; then
            flag=1
            result=$((result * 10 + ${s:i:1}))
        elif [ "$flag" -eq 1 ]; then
            flag=2
        fi

        ((i++))
    done

    if [ "$sign" -eq -1 ]; then
        echo $((0 - result))
    else
        echo $result
    fi
}
```

This function, `_atoi`, converts a string `s` to an integer. It iterates through each character of the string, handling signs and digits to build the resulting integer. The final result is adjusted based on the sign. The function uses a `while` loop and conditional statements to parse the string and build the integer value.
