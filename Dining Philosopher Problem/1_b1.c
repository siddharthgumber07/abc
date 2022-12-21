#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#define phil 5

int ARR[phil] = { 0, 1, 2, 3, 4 }; // Strict ordering
pthread_mutex_t bowl;
pthread_mutex_t chop[phil];

void* fun(void* num)
{
    int id = *(int*)num;
    int l = id;
    int r = (id + 1) % phil;

    while (1) {
        printf("Philosopher %d is thinking!!!\n\n", id);
        sleep(1);

        pthread_mutex_lock(&bowl);

        pthread_mutex_lock(&chop[l]);
        pthread_mutex_lock(&chop[r]);

        printf("Philosopher %d eating!!!\n\n", id);
        sleep(1);

        pthread_mutex_unlock(&chop[l]);
        pthread_mutex_unlock(&chop[r]);

        pthread_mutex_unlock(&bowl);
    }
}

int main(int argc, char* argv[])
{
    int id[phil];
    pthread_t arr[phil];

    pthread_mutex_init(&bowl, NULL);
    for (int i = 0; i < phil; i++) {
        pthread_mutex_init(&chop[i], NULL);
    }

    for (int i = 0; i < phil; i++) {
        id[i] = ARR[i];
        pthread_create(&arr[i], NULL, fun, &id[i]);
    }

    for (int i = 0; i < phil; i++) {
        pthread_join(arr[i], NULL);
    }

    return 0;
}

