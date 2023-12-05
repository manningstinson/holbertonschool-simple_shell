#!/bin/bash
#include "shell.h"

# Function to check if shell is in interactive mode
interactive() {
    [ -t 0 ] && [ "$1" -le 2 ]
}

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

# Function to check if a character is alphabetic
_isalpha() {
    local c="$1"
    [[ "$c" =~ [[:alpha:]] ]]
}

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
