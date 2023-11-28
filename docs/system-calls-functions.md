# System Calls & Functions

**Functions from string.h:**
- `strcpy`, `strcat`, `strlen`, `strcmp`, `strncmp`, etc.

**`access` (man 2 access):**
Checks real user's permissions for a file. Used to test the accessibility of a file, checking if the calling process can access the file in the specified mode.

**`chdir` (man 2 chdir):**
Changes the current working directory of the calling process.

**`close` (man 2 close):**
Closes a file descriptor, releasing associated resources.

**`closedir` (man 3 closedir):**
Closes a directory stream opened by `opendir()`.

**`execve` (man 2 execve):**
Executes a program.

**`exit` (man 3 exit):**
Terminates the calling process, returning an exit status.

**`_exit` (man 2 _exit):**
Terminates the calling process without running exit handlers or flushing buffers.

**`fflush` (man 3 fflush):**
Flushes the output buffer of a stream.

**`fork` (man 2 fork):**
Creates a new process by duplicating the calling process.

**`free` (man 3 free):**
Deallocates memory previously allocated by `malloc`, `calloc`, or `realloc`.

**`getcwd` (man 3 getcwd):**
Gets the current working directory.

**`getline` (man 3 getline):**
Reads an entire line from a stream, dynamically allocating the buffer as needed.

**`getpid` (man 2 getpid):**
Returns the process ID of the calling process.

**`isatty` (man 3 isatty):**
Tests whether a file descriptor refers to a terminal.

**`kill` (man 2 kill):**
Sends a signal to a process or a group of processes.

**`malloc` (man 3 malloc):**
Allocates a specified number of bytes of memory.

**`open` (man 2 open):**
Opens a file or creates a new file if it does not exist.

**`opendir` (man 3 opendir):**
Opens a directory stream.

**`perror` (man 3 perror):**
Prints a description for the last error that occurred.

**`printf` (man 3 printf):**
Prints formatted output to stdout.

**`fprintf` (man 3 fprintf):**
Prints formatted output to a specified file stream.

**`vfprintf` (man 3 vfprintf):**
Prints formatted output using a va_list.

**`sprintf` (man 3 sprintf):**
Writes formatted data to a string.

**`putchar` (man 3 putchar):**
Writes a character to the standard output.

**`read` (man 2 read):**
Reads data from a file descriptor.

**`readdir` (man 3 readdir):**
Returns a pointer to a dirent structure representing the next directory entry in the directory stream.

**`signal` (man 2 signal):**
Sets the disposition of a signal.

**`stat (__xstat)` (man 2 stat):**
Gets file status.

**`lstat (__lxstat)` (man 2 lstat):**
Like `stat`, but does not follow symbolic links.

**`fstat (__fxstat)` (man 2 fstat):**
Gets file status of an open file descriptor.

**`strtok` (man 3 strtok):**
Breaks a string into a sequence of zero or more nonempty tokens.

**`wait` (man 2 wait):**
Waits for a child process to terminate.

**`waitpid` (man 2 waitpid):**
Waits for a specific child process to terminate.

**`wait3` (man 2 wait3):**
An older version of `waitpid` with three arguments.

**`wait4` (man 2 wait4):**
An older version of `waitpid` with four arguments.

**`write` (man 2 write):**
Writes data to a file descriptor.

These functions and system calls are fundamental for performing various operations related to file and process manipulation in a Unix-like environment.
