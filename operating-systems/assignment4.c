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
  }
    
  return NULL;
}

int main(int argc, char *argv[]) {
  int input = atoi(*argv[1]);

  if (input > 12){
    printf("Warning: The maximum number of readers allowed is 12.\n Input: %d, but this program will proceed with only 12 readers and 1 writer\n", input);
    input = 12;
  }
  else if (input < 0 || input == null){
    printf("Error: Number of readers cannot be less than 0 or null"); 
    exit(0);
  }

  //Add 1 for the writer thread
  input += 1;

  pthread_t tid[input];
  int rc;

  /* Allocate memory for shared data */
  counter = (struct shared_data *) malloc(sizeof(struct shared_data));
  counter->value = 0;

  /*Initialize semaphores
    * change
    * change
    * change
    * change
    * change
    * change
    * change*/
  if ((pthread_mutex_init(&mutex, NULL))) {
      printf("Error occured when initialize mutex lock.");
      exit(0);
  }

  pthread_attr_t attr;
  if ((pthread_attr_init(&attr))) {
      printf("Error occured when initialize pthread_attr_t.");
      exit(0);
  }

  /* Create threads */
  for (int i = 0; i < input; i++){
    if ((rc = pthread_create(&tid[i], &attr, thread1, NULL))) {
        fprintf(stderr, "ERROR: pthread_create, rc: %d\n", rc);
        exit(0);
    }
  }

  /* Wait for threads to finish */
  for (int i = 0; i < input; i++){
    pthread_join(tid[i], NULL);
  }

  /* Clean up */
  pthread_mutex_destroy(&mutex); //CHAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAANGE!!!
  free(counter); //CHAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAANGE!!!
  pthread_exit(NULL);

  return 0;
}

