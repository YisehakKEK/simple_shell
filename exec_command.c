#include "shell.h"

/**
 * execute_command - Executes a given command using execve
 * @command: The command to execute
 */
void execute_command(char *command)
{
    pid_t pid;
    int status;
    char *argv[] = {command, NULL};

    pid = fork();
    if (pid == 0)
    {
        if (execve(command, argv, environ) == -1)
        {
            perror("./shell");
            exit(127);
        }
    }
    else if (pid > 0)
    {
        waitpid(pid, &status, 0);
    }
    else
    {
        perror("fork");
    }
}
