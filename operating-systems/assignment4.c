#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX_UPDATES 2000000

/* Struct a shared variable to store result */
struct shared_data {
    int value;  
};

/* Global shared variable */
struct shared_data *counter;
/* Mutex lock */
pthread_mutex_t mutex;

/* Thread1 function */
void *thread1() {
    int i = 0;
		int bonus = 0;
    while (i < MAX_UPDATES) {
        if (pthread_mutex_lock(&mutex) == 0) { //Entry section
						if ((counter->value % 100) == 0 && (i + 100 <= MAX_UPDATES)){
					  //Start critical section
							counter->value += 100;
							i += 100;
							bonus++;
					  //End critical section
						}
						else{
					  //Start critical section
							counter->value++;
							i++;
					  //End critical section
						}

            pthread_mutex_unlock(&mutex); //Exit section
        }
    }
    
    printf("I'm thread1, I did %d updates and I got the bonus for %d times, counter = %d\n", i, bonus, counter->value); //Remainder section
    return NULL;
}

/* Thread2 function */
void *thread2() {
    int i = 0;
    while (i < MAX_UPDATES) {
        if (pthread_mutex_lock(&mutex) == 0) { //Entry section
					  //Start critical section
							counter->value++;
							i++;
						//End critical section
           
            pthread_mutex_unlock(&mutex); //Exit section
        }
    }
    
    printf("I'm thread2, I did %d updates, counter = %d\n", i, counter->value); //Remainder section
    return NULL;
}

int main() {
    pthread_t tid[2];
    int rc;

    /* Allocate memory for shared data */
    counter = (struct shared_data *) malloc(sizeof(struct shared_data));
    counter->value = 0;

    /* Initialize mutex lock */
    if ((pthread_mutex_init(&mutex, NULL))) {
        printf("Error occured when initialize mutex lock.");
        exit(0);
    }

    pthread_attr_t attr;
    if ((pthread_attr_init(&attr))) {
        printf("Error occured when initialize pthread_attr_t.");
        exit(0);
    }

    /* Create thread1 */
    if ((rc = pthread_create(&tid[0], &attr, thread1, NULL))) {
        fprintf(stderr, "ERROR: pthread_create, rc: %d\n", rc);
        exit(0);
    }

		/* Create thread2 */
		if ((rc = pthread_create(&tid[1], &attr, thread2, NULL))) {
        fprintf(stderr, "ERROR: pthread_create, rc: %d\n", rc);
        exit(0);
    }

    /* Wait for threads to finish */
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);

		printf("from parent counter = %d\n", counter->value);

 
    /* Clean up */
    pthread_mutex_destroy(&mutex);
    free(counter);
    pthread_exit(NULL);

    return 0;
}
