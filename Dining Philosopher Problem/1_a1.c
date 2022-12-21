#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define phil 5

pthread_mutex_t chop[phil];
pthread_mutex_t bowl[phil];
int ARR[phil] = {0, 1, 2, 3, 4};

void * fun(void *num)
{
    int id = *(int *)num;
    int r = (id + 1) % phil;
    int l = id;

    while (1)
    {
        printf("Philosopher %d is thinking!!!\n\n", id);
        sleep(1);

        while (pthread_mutex_trylock(&bowl[id]) != 0)
        {
            sleep(1);
        }

        while (pthread_mutex_trylock(&chop[l]) != 0 || pthread_mutex_trylock(&chop[r]) != 0)
        {
            pthread_mutex_unlock(&chop[r]);
            pthread_mutex_unlock(&chop[l]);
            sleep(1);
        }

        printf("Philosopher %d is eating!!!\n\n", id);
        sleep(1);

        pthread_mutex_unlock(&chop[r]);
        pthread_mutex_unlock(&chop[l]);

        pthread_mutex_unlock(&bowl[id]);
    }
}

int main(int argc, char *argv[])
{
    int id[phil];
    pthread_t arr[phil];

    for (int i = 0; i < phil; i++)
    {
        pthread_mutex_init(&bowl[i], NULL);
        pthread_mutex_init(&chop[i], NULL);
    }

    for (int i = 0; i < phil; i++)
    {
        id[i] = ARR[i];
        pthread_create(&arr[i], NULL, fun, &id[i]);
    }

    for (int i = 0; i < phil; i++)
    {
        pthread_join(arr[i], NULL);
    }

    return 0;
}
