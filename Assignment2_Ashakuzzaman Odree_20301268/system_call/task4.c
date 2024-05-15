#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubbleSortDescending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }

    printf("Sorted array in descending order:\n");
        int i = 0;
    	while (i < n) {
    	    printf("%d ", arr[i]);
    	    i++;
	}

        printf("\n");
}





int main(int argc, char *argv[]) {
    if (argc < 2) {
        return 1;
    }

    int n = argc - 1;
    int arr[n];

    int i = 0;
    while (i < n) {
    	arr[i] = atoi(argv[i + 1]);
    	i++;
	}


    pid_t pid = fork();

    if (pid == 0) {   
        bubbleSortDescending(arr, n);
          
    } else if (pid > 0) {  
        wait(NULL);

        printf("Odd/Even status for each number:\n");
        int i = 0;
	while (i < n) {
	    if (arr[i] % 2 == 0) {
		printf("%d: Even\n", arr[i]);
	    } else {
		printf("%d: Odd\n", arr[i]);
	    }
	    i++;
	}

    } else {
        perror("Fork failed");
        return 1;
    }

    return 0;
}

