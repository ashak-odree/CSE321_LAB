#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t parent_pid = getpid();
    printf("1. Parent process ID: %d\n", parent_pid);

    pid_t child_pid = fork();  // First fork

    if (child_pid == 0) {
        printf("2. Child process ID: %d\n", getpid());

        pid_t grandchild1_pid = fork();
        if (grandchild1_pid == 0) {
            printf("3. Grandchild process ID: %d\n", getpid());
        } else if (grandchild1_pid > 0) {
            pid_t grandchild2_pid = fork(); // Second grandchild
            if (grandchild2_pid == 0) {
                printf("4. Grandchild process ID: %d\n", getpid());
            } else if (grandchild2_pid > 0) {
                pid_t grandchild3_pid = fork(); // Third grandchild
                if (grandchild3_pid == 0) {
                    printf("5. Grandchild process ID: %d\n", getpid());
                }
            }
        }
    } else if (child_pid > 0) {
        wait(NULL);
    }

    return 0;
}

