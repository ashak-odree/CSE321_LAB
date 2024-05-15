#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>
#include <ctype.h>


#define SHARED_MEM_KEY 'B'  


typedef struct {
  char sel;
  int b;
} shared_data;


int main() {
  
  key_t key = ftok(".", SHARED_MEM_KEY);
  int shmid = shmget(key, sizeof(shared_data), IPC_CREAT | 0666);
  if (shmid < 0) {
    perror("shmget");
    exit(1);
  }

  shared_data *data = shmat(shmid, NULL, 0);
  if (data == (void *) -1) {
    perror("shmat");
    exit(1);
  }

  data->b = 1000;

  char selection;
  printf("Provide Your Input From Given Options:\n");
  printf("1. Type a to Add Money\n");
  printf("2. Type w to Withdraw Money\n");
  printf("3. Type c to Check Balance\n");
  printf("Your selection: ");
  scanf(" %c", &selection);

int amount;

switch (toupper(selection)) {

    case 'A':

        printf("Enter amount to be added: ");
        scanf("%d", &amount);

        if (amount > 0) {
            
            data->b += amount; 
            printf("Balance added successfully\n");
            printf("Updated balance after addition: %d\n", data->b); 
        } else {
            printf("Adding failed, Invalid amount\n");
        }

        break;

    case 'W':

        printf("Enter amount to be withdrawn: ");
        scanf("%d", &amount);

        if (amount > 0 && amount <= data->b) {
           
            data->b -= amount;
            printf("Balance withdrawn successfully\n");
            printf("Updated balance after withdrawal: %d\n", data->b); 
        } else {
            printf("Withdrawal failed, Invalid amount\n");
        }

        break;

    case 'C':

       
        printf("Your current balance is: %d\n", data->b); 

        break;

    default:

        printf("Invalid selection\n");

}


  shmdt(data);

  shmctl(shmid, IPC_RMID, NULL);

  printf("Thank you for using!\n");
 
  return 0;
}

