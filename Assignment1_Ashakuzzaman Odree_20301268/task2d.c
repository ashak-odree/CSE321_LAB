#include <stdio.h>
#include <string.h>

int main(){
    char pass[100];
    printf("Enter your mail: ");
    scanf("%s", pass);
    
    char* domain = strstr(pass, "@");
    
    if (domain == NULL) {
        printf("Invalid email address");
    } 
    else {
        
        domain++;
       
        if (strcmp(domain, "sheba.xyz") == 0) {
            printf("Email address is okay\n");
        } else {
            printf("Email address is outdated\n");
        }
    }

    return 0;
}

