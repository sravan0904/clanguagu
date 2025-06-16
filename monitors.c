#include <stdio.h>
#include <pthread.h>

#define MAX_PORTS 3
int available_ports = MAX_PORTS;
pthread_mutex_t lock;

void* use_port(void* arg) {
    int id = *(int*)arg;
    while (1) {
        pthread_mutex_lock(&lock);
        if (available_ports > 0) {
            available_ports--;
            printf("Process %d: Acquired port\n", id);
            pthread_mutex_unlock(&lock);
            sleep(1);
            pthread_mutex_lock(&lock);
            printf("Process %d: Released port\n", id);
            available_ports++;
            pthread_mutex_unlock(&lock);
            break;
        }
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    pthread_t t[5];
    int id[5];
    pthread_mutex_init(&lock, NULL);
    for (int i=0;i<5;i++) {
        id[i] = i+1;
        pthread_create(&t[i], NULL, use_port, &id[i]);
    }
    for (int i=0;i<5;i++)
        pthread_join(t[i], NULL);
    pthread_mutex_destroy(&lock);
    return 0;
}
