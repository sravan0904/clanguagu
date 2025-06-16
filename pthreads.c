#include <stdio.h>
#include <pthread.h>

void* task(void* arg) {
    int id = *(int*)arg;
    printf("Thread %d: Running concurrently\n", id);
    return NULL;
}

int main() {
    pthread_t threads[3];
    int ids[3] = {1, 2, 3};

    for (int i = 0; i < 3; i++)
        pthread_create(&threads[i], NULL, task, &ids[i]);

    for (int i = 0; i < 3; i++)
        pthread_join(threads[i], NULL);

    return 0;
}
