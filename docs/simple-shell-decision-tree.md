<img width="1417" alt="Screen Shot 2023-12-02 at 3 32 26 PM" src="https://github.com/manningstinson/holbertonschool-simple_shell/assets/104523090/376d3a32-bbf8-479d-948e-017701f6a812">

# Simple Shell Process Flow
Here's a breakdown of the given shell execution process in a flowchart format. Included are flows for error handing, non built in commands, and subshell commands. 

### Shell Awaits User Input
The process initiates as the shell awaits user input.

### Tokenize and Parse User Input
User input undergoes tokenization and parsing for further processing.

### Is it a Built-in Command?
The initial decision point involves determining if the user input corresponds to a built-in command.

### Execute Built-in Command
If the input matches a built-in command, execute it, advancing the process.

### Is it an Executable File?
The second decision point examines whether the user input is an executable file.

### Fork and Execute the Command
For executable files, fork and execute the command to progress further.

### Is it a Directory?
The third decision point assesses if the user input represents a directory.

### Change to the Directory
If the input denotes a directory, change to it to continue the process.

### Is it a Subshell Command?
The fourth decision point involves identifying if the user input is a subshell command.

### Fork and Execute Subshell Command
For subshell commands, fork and execute them, ensuring the process moves forward.

### Is it a Subshell Command?
The fifth decision point involves checking again if the user input is a subshell command.

### Fork and Execute Subshell Command
For subshell commands, fork and execute them, ensuring the process moves forward.

## Process Flow for Non-Built Commands

