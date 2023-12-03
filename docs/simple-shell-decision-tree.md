<img width="1417" alt="Screen Shot 2023-12-02 at 3 32 26 PM" src="https://github.com/manningstinson/holbertonschool-simple_shell/assets/104523090/376d3a32-bbf8-479d-948e-017701f6a812">

# Simple Shell Process Flow
Here's a breakdown of the given shell execution process in a flowchart format. Included are flows for error handing, non built in commands, and subshell commands.  

**Shell Awaits User Input** <br>
The process initiates as the shell awaits user input.

**Tokenize and Parse User Input** <br>
User input undergoes tokenization and parsing for further processing.

**Is it a Built-in Command** <br>
The initial decision point involves determining if the user input corresponds to a built-in command.

**Execute Built-in Command?** <br>
If the input matches a built-in command, execute it, advancing the process.

## Is it an Executable File?
The second decision point examines whether the user input is an executable file.

**Child Process Execution** <br>
The child process, created by forking, is responsible for executing the external command.

**Loading the Executable** <br>
The child process loads the executable code of the external command into its address space.

**Replacing Image** <br>
The child process replaces its current image with the image of the external command. This involves loading the code and data of the external command into the memory space of the child process.

**Command Execution** <br>
The external command is executed within the context of the child process. This involves performing the actions specified by the command, whether it's running a program, processing data, or performing some other operation.

**Child Process Termination** <br>
Once the external command completes its execution, the child process terminates. The termination might be normal, indicating that the command executed successfully, or it could be due to an error.

**Exit Status** <br>
The child process may exit with a status code, which indicates the outcome of the command execution. The exit status is typically checked by the parent process (the shell) to determine whether the command executed successfully or encountered an issue.

**Parent Process Handling** <br>
The parent process (the shell) may perform additional actions based on the exit status of the child process. For example, it might display an error message if the command failed, or it might continue with the next steps if the command succeeded.

**Waiting for Child Process** <br>
In many cases, the parent process waits for the child process to complete before proceeding. This ensures that the shell doesn't move on to the next command until the current one has finished executing.

**Fork and Execute the Command** <br>
For executable files, fork and execute the command to progress further.

## Is it a Directory?
The third decision point assesses if the user input represents a directory.

#### Change to the Directory
If the input denotes a directory, change to it to continue the process.

#### Is it a Subshell Command?
The fourth decision point involves identifying if the user input is a subshell command.

#### Fork and Execute Subshell Command
For subshell commands, fork and execute them, ensuring the process moves forward.

#### Is it a Subshell Command?
The fifth decision point involves checking again if the user input is a subshell command.

#### Fork and Execute Subshell Command
For subshell commands, fork and execute them, ensuring the process moves forward.

## Process Flow for Non-Built Commands

