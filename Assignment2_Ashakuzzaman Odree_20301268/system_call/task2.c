#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  
#include <sys/wait.h>

int main() {

    int num_generations = 2;  

    pid_t child_pid; 
    
    for (int i = 0; i < num_generations; i++) {
        child_pid = fork();

        if (child_pid == -1) {
            perror("fork error");
            exit(1);
        }

        if (child_pid == 0) {
            if (i == 0) {  
                printf("I am grandchild\n");
                sleep(1);  
            } else {       
                printf("I am child\n");
            }
            exit(0);  
        } else {
            
            wait(NULL);  
        }
    }

    
    printf("I am Parent\n");

    return 0;
}

