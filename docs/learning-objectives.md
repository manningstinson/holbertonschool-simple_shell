# Learning Objectives

**Who designed and implemented the original Unix operating system:**<br>
The original Unix operating system was designed and implemented by Ken Thompson, Dennis Ritchie, and others at Bell Labs in the early 1970s.

**Who wrote the first version of the UNIX shell:** <br>
The first version of the UNIX shell, known as the Thompson shell, was written by Ken Thompson.

**Who invented the B programming language (the direct predecessor to the C programming language):**<br>
Ken Thompson invented the B programming language, which was the direct predecessor to the C programming language. Dennis Ritchie later developed C based on the B language.

**Who is Ken Thompson:**<br>
Ken Thompson is a computer scientist and one of the key figures in the development of the Unix operating system. He co-created the original Unix with Dennis Ritchie and made significant contributions to programming languages and computer science.

**How does a shell work:**<br>
A shell is a command-line interpreter that allows users to interact with the operating system. It reads user input, interprets commands, and executes them by interacting with the operating system's kernel. The shell also manages processes, I/O redirection, and environment variables.

**What is a pid and a ppid:**<br>
PID (Process ID) is a unique identifier assigned to each process running on a Unix-like system. PPID (Parent Process ID) is the PID of the parent process that spawned the current process.

**How to manipulate the environment of the current process:**<br>
The environment of the current process can be manipulated using shell commands to set or unset environment variables. Commands like `export` (in Unix-like systems) are used to set environment variables.

**What is the difference between a function and a system call:**<br>
A function is a set of instructions that performs a specific task within a program. A system call, on the other hand, is a request made by a program to the operating system's kernel to perform tasks such as file operations, process management, or memory allocation.

**How to create processes:**<br>
Processes can be created using system calls such as `fork` in Unix-like systems. The `fork` system call duplicates the calling process, creating a new process (child) that is a copy of the original (parent).

**What are the three prototypes of main:**<br>
The three standard prototypes for the `main` function in C are:
- `int main(void)`
- `int main(int argc, char *argv[])`
- `int main(int argc, char *argv[], char *envp[])`

**How does the shell use the PATH to find the programs:**<br>
The shell uses the `PATH` environment variable to locate executable programs. It searches directories specified in `PATH` in the order they appear, looking for the requested program. When a match is found, the shell executes the program.

**How to execute another program with the execve system call:**<br>
The `execve` system call is used to execute another program in Unix-like systems. It replaces the current process image with a new one specified by the provided executable file.

**How to suspend the execution of a process until one of its children terminates:**<br>
The `wait` or `waitpid` system calls are used to suspend the execution of a process until one of its child processes terminates. This allows a parent process to wait for the completion of a specific child process.

**What is EOF / “end-of-file”:**<br>
EOF, or "end-of-file," is a condition in a file stream that indicates that there is no more data to be read. It is typically represented by a special value (often `-1` in C) returned by input functions when attempting to read beyond the end of a file.
