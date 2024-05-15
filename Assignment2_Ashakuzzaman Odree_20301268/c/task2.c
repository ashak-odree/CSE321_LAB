#include <stdio.h>

// Function to check if a number is perfect
int isPerfect(int num) {
    int sum = 1;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            sum += i;
            if (i * i != num) {
                sum += num / i;
            }
        }
    }
    return sum == num;
}

int main() {
    int start, ending;

    // Input starting and ending intervals
    printf("Enter starting interval: ");
    scanf("%d", &start);

    printf("Enter ending interval: ");
    scanf("%d", &ending);

    printf("Perfect numbers between %d and %d are:\n", start, ending);

    int i = start + 1; // Start from the next number after start
    while (i <= ending) { // Loop while i is less than or equal to ending
        if (isPerfect(i)) { // Check if i is a perfect number
            printf("%d\n", i); // Print i if it's perfect
        }
        i++; // Move to the next number
    }

    return 0;
}

