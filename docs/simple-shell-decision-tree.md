# Simple Shell Process Flow
Below is a decision tree/diagream of the simple shell command process with error handling. 
<img width="1417" alt="Screen Shot 2023-12-02 at 3 32 26 PM" src="https://github.com/manningstinson/holbertonschool-simple_shell/assets/104523090/376d3a32-bbf8-479d-948e-017701f6a812">

## General Flow

## Shell Awaits User Input: 
The process starts with the shell waiting for user input. <br>

## Tokenize and Parse User Input: 
The user input is processed by tokenizing and parsing. <br>

## Is it a Built-in Command?: The first decision point. 
If the user input corresponds to a built-in command, execute it; otherwise, proceed to the next check. <br>

Execute Built-in Command: If it's a built-in command, execute it. The process continues.
Is it an Executable File?: The second decision point. If the user input is an executable file, fork and execute it; otherwise, move on to the next check.
Fork and Execute the Command: If it's an executable file, fork and execute the command. The process continues.
Is it a Directory?: The third decision point. If the user input is a directory, change to that directory; otherwise, proceed.
Change to the Directory: If it's a directory, change to that directory. The process continues.
Is it a Subshell Command?: The fourth decision point. If the user input is a subshell command, fork and execute it; otherwise, proceed.
Fork and Execute Subshell Command: If it's a subshell command, fork and execute it. The process continues.
Continue Normal Execution: Regardless of the path taken, normal execution continues.
Error Encountered?: The fifth decision point. If an error occurs during execution, handle the error and notify the user.
Handle Error and Notify User: If there's an error, handle it and inform the user. The process continues.
User Interrupts Command?: The sixth decision point. If the user interrupts the command, the shell sends a SIGINT signal to the child process.
Shell Sends SIGINT to Child Process: If the user interrupts, send a termination signal to the child process. The process continues.
Parent Process Terminates: The final step where the parent process terminates, completing the shell execution flow.
