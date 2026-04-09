#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    // Check if the user provided a number
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <positive_integer>\n", argv[0]);
        return 1;
    }

    // Convert the input text to an integer
    int n = atoi(argv[1]);
    if (n <= 0) {
        fprintf(stderr, "Error: Please enter a positive integer.\n");
        return 1;
    }

    // Create the child process
    pid_t pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed.\n");
        return 1;
    } 
    else if (pid == 0) {
        // --- CHILD PROCESS ---
        // Generate and print the sequence
        while (n > 1) {
            printf("%d, ", n);
            if (n % 2 == 0) {
                n = n / 2;
            } else {
                n = 3 * n + 1;
            }
        }
        printf("%d\n", n); // Print the final 1
    } 
    else {
        // --- PARENT PROCESS ---
        // Wait for the child to finish its job
        wait(NULL);
    }

    return 0;
}