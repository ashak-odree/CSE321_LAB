#include <stdio.h>

int main() {
    int num1, num2;

 
    printf("Enter first number: ");
    scanf("%d", &num1);

   
    printf("Enter second number: ");
    scanf("%d", &num2);

    
    if (num1 > num2) {
        int result = num1 - num2;
        printf("Result of subtraction: %d\n", result);
    } else if (num1 < num2) {
        int result = num1 + num2;
        printf("Result of addition: %d\n", result);
    } else {
        int result = num1 * num2;
        printf("Result of multiplication: %d\n", result);
    }

    return 0;
}

