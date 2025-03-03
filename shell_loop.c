#include "shell.h"

/**
 * shell_loop - Runs the shell loop, displaying a prompt and reading input
 */
void shell_loop(void)
{
    char *command = NULL;
    size_t len = 0;
    ssize_t read;

    while (1)
    {
        write(STDOUT_FILENO, "#cisfun$ ", 9);
        read = getline(&command, &len, stdin);
        if (read == -1)  /* Handle Ctrl+D */
        {
            write(STDOUT_FILENO, "\n", 1);
            free(command);
            exit(0);
        }

        command[strcspn(command, "\n")] = 0; /* Remove newline character */
        if (strlen(command) > 0)
            execute_command(command);
    }
}
