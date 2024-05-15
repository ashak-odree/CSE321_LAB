#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t a, b, c;
    int process_count = 1; 

    a = fork();
    b = fork();
    c = fork();

    if (a > 0 && b > 0 && c > 0) 
        printf("Parent PID: %d\n", getpid());
    else if (a == 0 || b == 0 || c == 0) 
    {
        int pid = getpid();
        printf("Child PID: %d\n", pid);

        if (pid % 2 != 0) 
        {
            fork();
            printf("Grandchild PID: %d\n", getpid());
        }
    }

    for (; wait(NULL) > 0; process_count++) {
    
	}


    printf("Total number of processes created: %d\n", process_count);

    return 0;
}
