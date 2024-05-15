#include <stdio.h>
#include <string.h>

int lowerCasePresent(char* password) {
    for (int i = 0; password[i] != '\0'; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            return 1;
        }
    }
    return 0;
}

int upperCasePresent(char* password) {
    for (int i = 0; password[i] != '\0'; i++) {
        if(password[i] >= 'A' && password[i] <= 'Z') {
            return 1;
        }
    }
    return 0;
}

int digitPresent(char* password) {
    for (int i = 0; password[i] != '\0'; i++) {
        if(password[i] >= '0' && password[i] <= '9') {
            return 1;
        }
    }
    return 0;
}

int specialPresent(char* password) {
    for (int i = 0; password[i] != '\0'; i++) {
        if(password[i] == '_' || password[i] == '$' || password[i] == '#' || password[i] == '@') {
            return 1;
        }
    }
    return 0;
}

int main() {
    char password[100];
    printf("Enter the Password: ");
    scanf("%s", password);

    int lowerCase = lowerCasePresent(password);
    int upperCase = upperCasePresent(password);
    int digit = digitPresent(password);
    int specialChar = specialPresent(password);

    int errorCount = 0; //  track the error

    if (!lowerCase) {
        printf("Lowercase character missing");
        errorCount++;
    }
    if (!upperCase) {
        if (errorCount > 0) {
        	printf(", ");
        	} 
        printf("Uppercase character missing");
        errorCount++;
    }
    if (!digit) {
        if (errorCount > 0) {
        	printf(", ");
        	} 
        printf("Digit missing");
        errorCount++;
    }
    if (!specialChar) {
        if (errorCount > 0) {
        	printf(", ");
        	} 
        printf("Special character missing");
        errorCount++;
    }
    if (lowerCase && upperCase && digit && specialChar) {
        printf("OK\n");
    } else {
        printf("\n");
    }

    return 0;
}

