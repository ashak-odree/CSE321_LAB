#include <stdio.h>
#include <stdlib.h>

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


    bubbleSortDescending(arr, n);

    printf("Sorted array in descending order: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}


