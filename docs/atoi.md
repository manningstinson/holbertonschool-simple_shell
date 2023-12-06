# ATOI
The provided Bash script contributes to a simple shell implementation by offering essential functions. The `interactive()` function determines whether the shell is ready for user input by checking its connection to a terminal. Additionally, functions like `is_delim()` and `_isalpha()` assist in parsing and validating command parameters, while `_atoi()` facilitates the conversion of numerical input from strings to integers. Together, these functions enhance the basic functionality of a shell by providing tools for interactive mode detection, character checks, and string-to-integer conversion.

```bash
# Function to check if shell is in interactive mode
interactive() {
    [ -t 0 ] && [ "$1" -le 2 ]
}

```

**`interactive()` Function:**

Determines whether the shell is in interactive mode. Interactive mode typically means that the shell is connected to a terminal and is ready to receive user input. The function checks if file descriptor 0 (standard input) is associated with a terminal (`[ -t 0 ]`), and if the provided argument is less than or equal to 2. The argument check may be related to the number of file descriptors, where a value of 2 indicates that standard error is also available.

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

**`is_delim()` Function:**

Checks whether a given character `c` is a delimiter. This function can be used to identify whether a character is a delimiter in command parsing. Delimiters separate different parts of a command, such as spaces or other characters.

```bash
# Function to check if a character is alphabetic
_isalpha() {
    local c="$1"
    [[ "$c" =~ [[:alpha:]] ]]
}
```

**`_isalpha()` Function:**

Checks whether a given character `c` is alphabetic. This function might be used for validating input or checking the syntax of command parameters. It ensures that a character is a letter of the alphabet.

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

**`_atoi()` Function:**

Converts a string `s` to an integer. This function is likely used for converting numerical input from the user (entered as strings) into integer values that the shell can use in calculations or comparisons. It handles signs (positive and negative) and stops parsing once it encounters a non-digit character.
