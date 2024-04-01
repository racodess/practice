/* Raul Acosta 4566606
 *
 * This program implements a fair starvation and deadlock-free solution
 * to the readers-writers problem by ensuring max reader concurrency and
 * preventing starvation of processes. It is implemented using semaphores.
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

// Define maximum number of times readers access shared value counter.
#define MAX_READS 2000000

// Declare semaphores
sem_t ok_to_read; 
sem_t ok_to_write;
sem_t protect; // Protects readers counter.

int readers = 0; // Keeps track of active readers.
int shared_value = 0; // Counter written by writer() and accessed by reader().

// Reader function, accepts index i from reader's pthread_create for loop to identify threads. Also returns NULL to avoid warnings on compile.
void *reader(void *arg){
  long reader_thread = (long)arg; // Thread id.

  // Allows readers to access shared value counter 2000000 times.
  for (int i = 0; i < MAX_READS; i++){
    sem_wait(&ok_to_read); // Ensures it is safe to read.

    sem_wait(&protect); // Protects readers counter.
    readers++; // Increment for new active reader.

    // If an active reader is present, wait to write.
    if (readers == 1){
      sem_wait(&ok_to_write); // Ensures it is safe to write.
    }
    sem_post(&protect);

    sem_post(&ok_to_read);

    sem_wait(&protect);
    readers--; // Decrement when active reader leaves.

    // When all active readers leave, signal it is ok to write.
    if (readers == 0){
      sem_post(&ok_to_write);
    }
    sem_post(&protect);

    // When 2000000 accesses complete, identify reader and counter value.
    if (i == MAX_READS - 1){
      printf("I'm reader%ld, counter = %d\n", reader_thread, shared_value);
    }
  }

  return NULL;
}

// Accepts void *arg, and returns NULL to prevent compilation warnings.
void *writer(void *arg){
  printf("Executing... please wait...\n");
  
  // Writes 25000 times.
  for (int i = 0; i < 25000; i++){
    sem_wait(&ok_to_write);

    shared_value++;

    sem_post(&ok_to_write); 
  }

  printf("Writer Done!\n");

  return NULL;
}

// Accepts arguments from command line
int main(int argc, char *argv[]) {
  int input = atoi(argv[1]); // Turns user's reader thread number input to int.

  // CLI argument input validation.
  if (input > 12){
    printf("Warning: The maximum number of readers allowed is 12.\nInput: %d, but this program will proceed with only 12 readers and 1 writer\n", input);
    input = 12;
  }
  else if (input < 1){
    printf("Error: Number of readers cannot be less than 1\n"); 
    return 1;
  }

  //Add 1 for writer thread.
  input++;

  // Initialize semaphores.
  sem_init(&ok_to_read, 0, 1);
  sem_init(&ok_to_write, 0, 1);
  sem_init(&protect, 0, 1);


  // Declare pthread_t array for dynamic thread creation, rc for error handling. Source: Dr. Kaoutar Ben Ahmend, canvas
  pthread_t tid[input];
  int rc;

  pthread_attr_t attr;
  if ((pthread_attr_init(&attr))) {
      printf("Error occured when initialize pthread_attr_t.");
      exit(0);
  }

  /* Create threads */
  if ((rc = pthread_create(&tid[0], &attr, writer, NULL))) {
      fprintf(stderr, "ERROR: pthread_create, rc: %d\n", rc);
      exit(0);
  }

  for (long i = 1; i < input; i++){
    if ((rc = pthread_create(&tid[i], &attr, reader, (void *)i))) { // Pass index cast to void *, allows for thread identification in reader function.
        fprintf(stderr, "ERROR: pthread_create, rc: %d\n", rc);
        exit(0);
    }
  }

  /* Wait for threads to finish */
  for (int i = 0; i < input; i++){
    pthread_join(tid[i], NULL);
  }

  /* Clean up */
  sem_destroy(&ok_to_read);
  sem_destroy(&ok_to_write);
  sem_destroy(&protect);
  pthread_exit(NULL);

  return 0;
}

