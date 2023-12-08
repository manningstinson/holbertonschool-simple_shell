# getline.c

**getline.c Summary**

The `getline.c` file serves a pivotal role in the Simple Shell project, focusing on the processing of user input and managing command line interactions. Within this file, several key functions contribute to the functionality of the shell. The `input_buf` function is responsible for buffering chained commands, reading from standard input, and dynamically resizing buffers. It adeptly detects and processes command chains, removes trailing newlines, and updates the command history. The `get_input` function reads user input, manages command chains, and handles the command history, checking for chained commands, iterating through the buffer, and returning the length of the current command. Additionally, the `read_buf` function facilitates the reading of a buffer from the specified file descriptor, aiding input retrieval. The `_getline` function plays a crucial role in retrieving the next line of input from STDIN, handling buffer allocation, dynamic resizing, and newline character detection. Lastly, the `sigintHandler` function effectively blocks Ctrl-C, providing a user-friendly response to the corresponding signal. It displays a newline character, a shell prompt, ensuring a smooth and intuitive user experience. These functions collectively contribute to the robust handling of user input, enabling proper command execution and enhancing user interaction within the Simple Shell program.

## `input_buf` Function

The `input_buf` function buffers chained commands, reads from the standard input, and handles dynamic buffer resizing.

```c
/**
 * input_buf - buffers chained commands
 * @info: parameter struct
 * @buf: address of buffer
 * @len: address of len var
 *
 * Return: bytes read
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
    ssize_t r = 0;
    size_t len_p = 0;

    if (!*len) /* if nothing left in the buffer, fill it */
    {
        /*bfree((void **)info->cmd_buf);*/
        free(*buf);
        *buf = NULL;
        signal(SIGINT, sigintHandler);
        #if USE_GETLINE
        r = getline(buf, &len_p, stdin);
        #else
        r = _getline(info, buf, &len_p);
        #endif
        if (r > 0)
        {
            if ((*buf)[r - 1] == '\n')
            {
                (*buf)[r - 1] = '\0'; /* remove trailing newline */
                r--;
            }
            info->linecount_flag = 1;
            remove_comments(*buf);
            build_history_list(info, *buf, info->histcount++);
            /* if (_strchr(*buf, ';')) is this a command chain? */
            {
                *len = r;
                info->cmd_buf = buf;
            }
        }
    }
    return (r);
}
```

## `get_input` Function

The `get_input` function reads user input, manages command chains, and handles command history.

```c
/**
 * get_input - gets a line minus the newline
 * @info: parameter struct
 *
 * Return: bytes read
 */
ssize_t get_input(info_t *info)
{
    static char *buf; /* the ';' command chain buffer */
    static size_t i, j, len;
    ssize_t r = 0;
    char **buf_p = &(info->arg), *p;

    _putchar(BUF_FLUSH);
    r = input_buf(info, &buf, &len);
    if (r == -1) /* EOF */
        return (-1);
    if (len) /* we have commands left in the chain buffer */
    {
        j = i; /* init new iterator to current buf position */
        p = buf + i; /* get pointer for return */

        check_chain(info, buf, &j, i, len);
        while (j < len) /* iterate to semicolon or end */
        {
            if (is_chain(info, buf, &j))
                break;
            j++;
        }

        i = j + 1; /* increment past nulled ';'' */
        if (i >= len) /* reached end of buffer? */
        {
            i = len = 0; /* reset position and length */
            info->cmd_buf_type = CMD_NORM;
        }

        *buf_p = p; /* pass back pointer to current command position */
        return (_strlen(p)); /* return length of current command */
    }

    *buf_p = buf; /* else not a chain, pass back buffer from _getline() */
    return (r); /* return length of buffer from _getline() */
}
```

## `read_buf` Function

The `read_buf` function reads a buffer from the specified file descriptor.

```c
/**
 * read_buf - reads a buffer
 * @info: parameter struct
 * @buf: buffer
 * @i: size
 *
 * Return: r
 */
ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
    ssize_t r = 0;

    if (*i)
        return (0);
    r = read(info->readfd, buf, READ_BUF_SIZE);
    if (r >= 0)
        *i = r;
    return (r);
}
```

## `_getline` Function

The `_getline` function gets the next line of input from STDIN.

```c
/**
 * _getline - gets the next line of input from STDIN
 * @info: parameter struct
 * @ptr: address of pointer to buffer, preallocated or NULL
 * @length: size of preallocated ptr buffer if not NULL
 *
 * Return: s
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
    static char buf[READ_BUF_SIZE];
    static size_t i, len;
    size_t k;
    ssize_t r = 0, s = 0;
    char *p = NULL, *new_p = NULL, *c;

    p = *ptr;
    if (p && length)
        s = *length;
    if (i == len)
        i = len = 0;

    r = read_buf(info, buf, &len);
    if (r == -1 || (r == 0 && len == 0))
        return (-1);

    c = _strchr(buf + i, '\n');
    k = c ? 1 + (unsigned int)(c - buf) : len;
    new_p = _realloc(p, s, s ? s + k : k + 1);
    if (!new_p) /* MALLOC FAILURE! */
        return (p ? free(p), -1 : -1);

    if (s)
        _strncat(new_p, buf + i, k - i);
    else
        _strncpy(new_p, buf + i, k - i + 1);

    s += k - i;
    i = k;
    p = new_p;

    if (length)
        *length = s;
    *ptr = p;
    return (s);
}
```

## `sigintHandler` Function

The `sigintHandler` function blocks Ctrl-C and handles the corresponding signal.

```c
/**
 * sigintHandler - blocks ctrl-C
 * @sig_num: the signal number
 *
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
    _puts("\n");
    _puts("$ ");
    _putchar(BUF_FLUSH);
}
```
