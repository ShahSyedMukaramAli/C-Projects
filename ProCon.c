#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define SIZE 5

int buffer[SIZE];
int in = 0, out = 0;

sem_t empty, full;
pthread_mutex_t mutex;

void* producer(void* arg) {
    int item;
    for(int i = 0; i < 10; i++) {
        item = rand() % 100;

        sem_wait(&empty);              // Decrement empty
        pthread_mutex_lock(&mutex);    // Enter critical section

        buffer[in] = item;
        printf("Produced: %d at %d\n", item, in);
        in = (in + 1) % SIZE;

        pthread_mutex_unlock(&mutex);  // Exit critical section
        sem_post(&full);               // Increment full

        sleep(1);
    }
    return NULL;
}

void* consumer(void* arg) {
    int item;
    for(int i = 0; i < 10; i++) {
        sem_wait(&full);               // Decrement full
        pthread_mutex_lock(&mutex);    // Enter critical section

        item = buffer[out];
        printf("Consumed: %d from %d\n", item, out);
        out = (out + 1) % SIZE;

        pthread_mutex_unlock(&mutex);  // Exit critical section
        sem_post(&empty);              // Increment empty

        sleep(2);
    }
    return NULL;
}

int main() {
    pthread_t prod, cons;

    sem_init(&empty, 0, SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}
