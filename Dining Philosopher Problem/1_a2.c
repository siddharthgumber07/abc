#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#define phil 5

sem_t chop[phil];
sem_t bowl[phil];

void * fun(void *num)
{
    int id = *(int *)num;
    int r = (id + 1) % phil;
    int l = id;

    while (1)
    {

        printf("Philosopher %d is thinking!!!\n\n", id);
        sleep(1);

        sem_wait(&bowl[id]);
        sem_wait(&chop[l]);
        sem_wait(&chop[r]);

        printf("Philosopher %d is eating!!!\n\n", id);
        sleep(1);

        sem_post(&chop[l]);
        sem_post(&chop[r]);
        sem_post(&bowl[id]);
    }
}

int main(int argc, char *argv[])
{
    int id[phil];
    pthread_t arr[phil];

    for (int i = 0; i < phil; i++)
    {
        sem_init(&bowl[i], 0, 1);
        sem_init(&chop[i], 0, 1);
    }

    for (int i = 0; i < phil; i++)
    {
        id[i] = i;
        pthread_create(&arr[i], NULL, fun, &id[i]);
    }

    for (int i = 0; i < phil; i++)
    {
        pthread_join(arr[i], NULL);
    }

    return 0;
}
