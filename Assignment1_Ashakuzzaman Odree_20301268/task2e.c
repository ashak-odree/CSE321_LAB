#include <stdio.h>
#include <string.h>

int main(){
    char pass[100];
    printf("Enter your string: ");
    scanf("%s",pass);
    int start=0;
//    int count=0;
    int length= strlen(pass);
    int end =length-1;

    while (start<end){
        if (pass[start]!=pass[end]){
            printf("Not a palindrome\n");
//            count++;
              return 0;
        }
        start++;
        end--;
    }
    printf("Palindrome\n");
    return 0;
}
