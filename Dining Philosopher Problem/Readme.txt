For 1_a1.c:

-->Declaring two arrays of mutex pointer of size 5 as global variables i.e.  
   a) chop[5]        b) bowl[5]
   
-->Storing ids of philosophers in an array id[5].

-->Initializing the mutex of for both chop and bowl using pthread_mutex_init() subroutine by default attributes having NULL.

-->Now, creating 5 threads usihng pthread_create() having fun() as a parameter which impliments the philosopher problem using mutex locking.

-->Finally joining all the threads.


For 1_a2.c:

-->Declaring 2 arrays of sem_t data type of size 5 as global variables.
   a)chop[5]		b)bowl[5]
   
-->int id[5] for saving ids of philosophers.

-->Declaring 5 threads using phread_t().

-->Then initializing the semophore using sem_init for bowl and chop.

-->Then, creating 5 threads using pthread_create() having fun() as parameter which implements philosopher problem using sem_wait() and sem_post() and then joining them using pthread_join().


For 1_b1.c and 1_b2.c:

-->Similiar approach is used here as were in part a1 and a2 but now instead bowls, we have 2 sauce bowls.

