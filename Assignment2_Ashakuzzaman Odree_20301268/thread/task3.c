#include <stdio.h>
#include <string.h>
#include <pthread.h>

int asciiSum(char *str) {
    int sum = 0;
    int i = 0;
    
    while (str[i] != '\0') {
        sum += (int)str[i];
        i++;
    }

    return sum;
}


int compare_result[3] = {0};  
pthread_mutex_t mutex;   

void *calculateAndStore(void *arg) {
    char *name = (char *)arg;
    int sum = asciiSum(name);

    pthread_mutex_lock(&mutex);
    for (int i = 0; i < 3; i++) {
        if (compare_result[i] == 0) {
            compare_result[i] = sum;
            break;
        }
    }
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[3];
    char names[3][100];  

    for (int i = 0; i < 3; i++) {
        printf("Enter user name %d: ", i + 1);
        scanf("%s", names[i]);
    }

    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < 3; i++) {
        if (pthread_create(&threads[i], NULL, calculateAndStore, (void *)&names[i])) {
            return 1;
        }
    }

    pthread_mutex_destroy(&mutex);

    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    if (compare_result[0] == compare_result[1] && compare_result[1] == compare_result[2]) {
        printf("Youreka\n");
    } else if (compare_result[0] == compare_result[1] || compare_result[1] == compare_result[2] || compare_result[0] == compare_result[2]) {
        printf("Miracle\n");
    } else {
        printf("Hasta la vista\n");
    }

    return 0;
}

