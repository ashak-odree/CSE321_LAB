#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

#define MAX_TEXT_SIZE 6

struct msg {
    long int type;
    char txt[MAX_TEXT_SIZE];
};

int main() {
 
    key_t key = ftok(".", 'a');

    int msgId = msgget(key, 0666 | IPC_CREAT);
    if (msgId == -1) {
        perror("msgget");
        exit(1);
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
       
        struct msg message;
        long int type;

        char workspace[MAX_TEXT_SIZE];
        printf("Please enter the workspace name: ");
        scanf("%s", workspace);

        if (strcmp(workspace, "cse321") != 0) {
            printf("Invalid workspace name\n");
            exit(0);
        }

        message.type = 1;
        strcpy(message.txt, workspace);
        if (msgsnd(msgId, &message, sizeof(message.txt), 0) == -1) {
            perror("msgsnd");
            exit(1);
        }
       
        type = 2;
        if (msgrcv(msgId, &message, sizeof(message.txt), type, 0) == -1) {
            perror("msgrcv");
            exit(1);
        }
       
        int otp = getpid();
        sprintf(message.txt, "%d", otp);
        message.type = 3;

        if (msgsnd(msgId, &message, sizeof(message.txt), 0) == -1) {
            perror("msgsnd");
            exit(1);
        }
       
        message.type = 4;
        if (msgsnd(msgId, &message, sizeof(message.txt), 0) == -1) {
            perror("msgsnd");
            exit(1);
        }
       

    } else {
   

        struct msg message;
        long int type = 1;
        if (msgrcv(msgId, &message, sizeof(message.txt), type, 0) == -1) {
            perror("msgrcv");
            exit(1);
        }
       
        message.type = 2;
        if (msgsnd(msgId, &message, sizeof(message.txt), 0) == -1) {
            perror("msgsnd");
            exit(1);
        }

        type = 3;
        if (msgrcv(msgId, &message, sizeof(message.txt), type, 0) == -1) {
            perror("msgrcv");
            exit(1);
        }

        type = 4;
        if (msgrcv(msgId, &message, sizeof(message.txt), type, 0) == -1) {
            perror("msgrcv");
            exit(1);
        }
       

        message.type = 5;
        if (msgsnd(msgId, &message, sizeof(message.txt), 0) == -1) {
            perror("msgsnd");
            exit(1);
        }
       

        type = 5;
        if (msgrcv(msgId, &message, sizeof(message.txt), type, 0) == -1) {
            perror("msgrcv");
            exit(1);
        }
       
     
        printf("Workspace name sent to otp generator from log in: %s\n", message.txt);

        printf("OTP generator received workspace name from log in: %s\n", message.txt);

        printf("OTP sent to log in from OTP generator: %s\n", message.txt);

        printf("OTP sent to mail from OTP generator: %s\n", message.txt);

        printf("Mail received OTP from OTP generator: %s\n", message.txt);

        printf("OTP sent to log in from mail: %s\n", message.txt);

        printf("Log in received OTP from OTP generator: %s\n", message.txt);

        printf("Log in received OTP from mail: %s\n", message.txt);

        int otp1 = atoi(message.txt);
        int otp2 = atoi(message.txt);
        if (otp1 == otp2) {
            printf("OTP Verified\n");
        } else {
            printf("OTP Incorrect\n");
        }


        if (msgctl(msgId, IPC_RMID, NULL) == -1) {
            perror("msgctl");
            exit(1);
        }
    }

    return 0;
}


