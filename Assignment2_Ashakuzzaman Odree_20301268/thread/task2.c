#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *funcThread(void *arg);

int total = 1;  

int main() {
    pthread_t threads[5];

    for (int i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, funcThread, (void *)(intptr_t)(i ));
    
    
        pthread_join(threads[i], NULL);
    
    }

    return 0;
}

void *funcThread(void *arg) {
    int threadNum = (intptr_t)arg;

    int i = 0;
    while (i < 5) {
    printf("Thread %d prints %d\n", threadNum, total);
    total++;
    sleep(1);
    i++;
	}


    return NULL;
}

