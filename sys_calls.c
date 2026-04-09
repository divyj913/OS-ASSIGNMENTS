#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Child Process
        printf("Child Process: Executing 'ls' command...\n");
        execlp("ls", "ls", "-l", NULL); // The exec() call
        exit(1); // The exit() call (only reached if exec fails)
    } else if (pid > 0) {
        // Parent Process
        wait(NULL); // The wait() call
        printf("Parent Process: Child has finished executing.\n");
    }
    return 0;
}