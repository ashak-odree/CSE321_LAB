#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        return 1;
    }

    printf("Odd/Even status for each number:\n");
    for (int i = 1; i < argc; i++) {
        int num = atoi(argv[i]);
        if (num % 2 == 0) {
            printf("%d: Even\n", num);
        } else {
            printf("%d: Odd\n", num);
        }
    }

    return 0;
}


