#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file;
   
    file = fopen("input.txt", "a");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    } 
    pid_t child_pid =fork();

    if (child_pid == -1) {
        perror("Fork error");
        return 1;
    }

    if (child_pid == 0) {
        char input[100];

        while (1) {
            printf("Enter a string: ");
            fgets(input, sizeof(input), stdin);

            if (strcmp(input, "-1\n") == 0) {
                break;
            }

            fputs(input, file);
        }

        fclose(file);
    } else {

        wait(NULL); 
    }

    return 0;


}

