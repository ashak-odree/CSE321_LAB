#include <stdio.h>
#include <string.h>

int main() {
    FILE* inputFile = fopen("input_b.txt", "r");
    FILE* outputFile = fopen("output_b.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening files!\n");
        return 1;
    }

    char input[100];
    if (fgets(input, sizeof(input), inputFile) != NULL) {
        char output[sizeof(input)];
        int i, j;
        int len = strlen(input);
        int spaceFlag = 0;

    
        char *word;
        word = strtok(input, " ");

       
        while (word != NULL) {
            strcpy(output + strlen(output), word);
            word = strtok(NULL, " ");
            if (word != NULL) {
                strcat(output, " ");
            }
        }

        fprintf(outputFile, "%s\n", output);
        printf("Modified sentence written to output_b.txt\n");
    } 
    else {
	printf("Error reading input from file!\n");
    }

    fclose(inputFile);
    fclose(outputFile);
    return 0;
}

