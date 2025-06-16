#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

#define MAX_PORTS 3
sem_t ports;

void* use_port(void* arg) {
    int id = *(int*)arg;
    sem_wait(&ports);
    printf("Process %d: Using a port\n", id);
    sleep(1);
    printf("Process %d: Releasing the port\n", id);
    sem_post(&ports);
    return NULL;
}

int main() {
    pthread_t t[5];
    int id[5];
    sem_init(&ports, 0, MAX_PORTS);
    for (int i=0;i<5;i++) {
        id[i] = i+1;
        pthread_create(&t[i], NULL, use_port, &id[i]);
    }
    for (int i=0;i<5;i++)
        pthread_join(t[i], NULL);
    sem_destroy(&ports);
    return 0;
}
