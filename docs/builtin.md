# Shell Built-in Commands

This file (`builtin.c`) contains implementations of built-in commands for a simple shell project. The built-in commands include `_myexit`, `_mycd`, and `_myhelp`, each serving a specific purpose within the shell.

### `_myexit(info_t *info)`
```c
/**
 * _myexit - exits the shell
 * @info: Structure containing potential arguments. Used to maintain
 *         a constant function prototype.
 * Return: exits with a given exit status
 *         (0) if info->argv[0] != "exit"
 */
int _myexit(info_t *info)
{
    // Implementation details...
}
```
**Function Description:**
The `_myexit` function exits the shell. If an argument is provided, it attempts to convert it to an integer as an exit status. If successful, it sets the exit status; otherwise, it prints an error message.

###`_mycd(info_t *info)`
```c
/**
 * _mycd - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *         a constant function prototype.
 * Return: Always 0
 */
int _mycd(info_t *info)
{
    // Implementation details...
}
```
**Function Description:**
The `_mycd` function changes the current directory of the process. It supports changing to the home directory, the previous directory, or a specified directory. It updates environment variables accordingly.

### `_myhelp(info_t *info)`
```c
/**
 * _myhelp - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *         a constant function prototype.
 * Return: Always 0
 */
int _myhelp(info_t *info)
{
    // Implementation details...
}
```
**Function Description:**
The `_myhelp` function currently provides a placeholder message indicating that the help function is not yet implemented. It is intended to offer assistance and information about shell commands.

---
