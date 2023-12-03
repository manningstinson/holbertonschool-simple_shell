#!/bin/bash

# Function to mimic strncpy
my_strncpy() {
    if [ "$#" -ne 3 ]; then
        echo "Usage: my_strncpy <destination> <source> <n>"
        return 1
    fi

    dest="$1"
    src="$2"
    n="$3"

    i=0
    while [ "$i" -lt "$n" ] && [ "${src:$i:1}" ]; do
        dest="${dest}${src:$i:1}"
        i=$((i + 1))
    done

    echo "$dest"
}

# Function to mimic strncat
my_strncat() {
    if [ "$#" -ne 3 ]; then
        echo "Usage: my_strncat <destination> <source> <n>"
        return 1
    fi

    dest="$1"
    src="$2"
    n="$3"

    i=0
    while [ "$i" -lt "$n" ] && [ "${src:$i:1}" ]; do
        dest="${dest}${src:$i:1}"
        i=$((i + 1))
    done

    echo "$dest"
}

# Function to mimic strchr
my_strchr() {
    if [ "$#" -ne 2 ]; then
        echo "Usage: my_strchr <string> <character>"
        return 1
    fi

    string="$1"
    char="$2"

    i=0
    while [ "${string:$i:1}" ]; do
        if [ "${string:$i:1}" = "$char" ]; then
            echo "$char found at position $i"
            return 0
        fi
        i=$((i + 1))
    done

    echo "$char not found in the string"
    return 1
}

# Example usage
dest="Hello"
src=" World"
n=3

result=$(my_strncpy "$dest" "$src" "$n")
echo "my_strncpy result: $result"

dest="Hello"
src=" World"
n=3

result=$(my_strncat "$dest" "$src" "$n")
echo "my_strncat result: $result"

string="Hello, World!"
char="o"

my_strchr "$string" "$char"

