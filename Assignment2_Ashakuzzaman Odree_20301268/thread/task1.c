#include <stdio.h>
#include <pthread.h>
#include <unistd.h> 

void *threadFunction(void *arg) {
    int thread_num = *(int *)arg;

    printf("thread-%d running\n", thread_num);

    sleep(2);

    printf("thread-%d closed\n", thread_num);

    return NULL;
}

int main() {
    pthread_t threads[5];
    int thread_numbers[5] = {1, 2, 3, 4, 5};
    
    int i = 0;
    while (i < 5) {
    pthread_create(&threads[i], NULL, threadFunction, &thread_numbers[i]);
    pthread_join(threads[i], NULL);
    i++;
	}


    return 0;
}
