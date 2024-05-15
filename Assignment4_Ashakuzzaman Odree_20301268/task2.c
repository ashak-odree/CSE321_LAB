#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>


#define MaxCrops 5 
#define warehouseSize 5 


sem_t empty;
sem_t full;
pthread_mutex_t mutex;


int in = 0;
int out = 0;


char crops[warehouseSize] = {'R', 'W', 'P', 'S', 'M'}; 
char warehouse[warehouseSize] = {'N', 'N', 'N', 'N', 'N'}; 


void *Farmer(void *farmerID) {
    int *id = (int *)farmerID;
    char crop;
   
    for (int i = 0; i < MaxCrops; i++) {
        crop = crops[i];
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
       
       
        warehouse[in] = crop;
        printf("Farmer %d: Insert crop %c at room %d\n", *id, crop, in);
        in = (in + 1) % warehouseSize;
       
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
       
        sleep(1); 
    }
   
    pthread_exit(NULL);
}


void *ShopOwner(void *shopOwnerID) {
    int *id = (int *)shopOwnerID;
    char crop;
   
    for (int i = 0; i < MaxCrops; i++) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
       
      
        crop = warehouse[out];
        warehouse[out] = 'N';
        printf("Shop owner %d: Remove crop %c from room %d\n", *id, crop, out);
        out = (out + 1) % warehouseSize;
       
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
       
        sleep(1); 
    }
   
    pthread_exit(NULL);
}


int main() {
    pthread_t farmers[5], shopOwners[5];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty, 0, warehouseSize);
    sem_init(&full, 0, 0);
   
    int farmerIDs[5] = {1, 2, 3, 4, 5};
    int shopOwnerIDs[5] = {1, 2, 3, 4, 5};
   

    for (int i = 0; i < 5; i++) {
        pthread_create(&farmers[i], NULL, Farmer, &farmerIDs[i]);
    }
   
 
    for (int i = 0; i < 5; i++) {
        pthread_create(&shopOwners[i], NULL, ShopOwner, &shopOwnerIDs[i]);
    }
   

    for (int i = 0; i < 5; i++) {
        pthread_join(farmers[i], NULL);
    }
   
    
    for (int i = 0; i < 5; i++) {
        pthread_join(shopOwners[i], NULL);
    }
   
  
    printf("Warehouse state: ");
    for (int i = 0; i < warehouseSize; i++) {
        printf("%c", warehouse[i]);
    }
    printf("\n");
   
    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
   
    return 0;
}

