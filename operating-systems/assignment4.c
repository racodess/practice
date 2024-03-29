/* Raul Acosta 4566606
 *
 * This program implements a fair starvation and deadlock-free solution
 * to the readers-writers problem by ensuring max reader concurrency and
 * preventing starvation of processes. This is done using semaphores and a 
 * monitor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

//#define MAX_UPDATES 2000000
//
///* Struct a shared variable to store result */
//struct shared_data {
//    int value;  
//};
//
///* Global shared variable */
//struct shared_data *counter;
///* Mutex lock */
//pthread_mutex_t mutex;
//
///* Thread1 function */
//void *thread1() {
//    }
//    
//    return NULL;
//}
//
//int main() {
//    pthread_t tid[2CHANGGE THIS CHANGE THIS CHANGE THIS];
//    int rc;
//
//    /* Allocate memory for shared data */
//    counter = (struct shared_data *) malloc(sizeof(struct shared_data));
//    counter->value = 0;
//
//    /*Initialize semaphores
//     * change
//     * change
//     * change
//     * change
//     * change
//     * change
//     * change*/
//    if ((pthread_mutex_init(&mutex, NULL))) {
//        printf("Error occured when initialize mutex lock.");
//        exit(0);
//    }
//
//    pthread_attr_t attr;
//    if ((pthread_attr_init(&attr))) {
//        printf("Error occured when initialize pthread_attr_t.");
//        exit(0);
//    }
//
//    /* Create thread1 */
//    if ((rc = pthread_create(&tid[0], &attr, CHANGETHISthreeeeeeeeeeeeeeeeeeeead1, NULL))) {
//        fprintf(stderr, "ERROR: pthread_create, rc: %d\n", rc);
//        exit(0);
//    }
//
//    /* Wait for threads to finish */
//    pthread_join(tid[0], NULL);
//    pthread_join(tid[1], NULL);
//
//		printf("from parent counter = %d\n", counter->value);
//
// 
//    /* Clean up */
//    pthread_mutex_destroy(&mutex);
//    free(counter);
//    pthread_exit(NULL);
//
//    return 0;
//}
//
