/* Raul Acosta 4566606
 *
 * This program implements a fair starvation and deadlock-free solution
 * to the readers-writers problem by ensuring max reader concurrency and
 * preventing starvation of processes. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t ok_to_read;
sem_t ok_to_write;

int readers = 0;
int shared_value = 0;

void reader(void *arg){
  long reader_thread = (long)arg;

  for (int i = 0; i < 2000000; i++){
    sem_wait(&ok_to_read);

    readers++;

    if (readers == 1){
      sem_wait(&ok_to_write);
    }

    sem_post(&ok_to_read);

    readers--;

    if (readers == 0){
      sem_post(&ok_to_write);
    }

    if (i == 1999999){
      printf("I'm reader%ld, counter = %d\n", reader_thread, shared_value);
    }
  }
}

void writer(){
  printf("Executing... please wait...\n");
  for (int i = 0; i < 25000; i++){
    sem_wait(&ok_to_write);

    shared_value++;

    sem_post(&ok_to_write);
  }
  printf("Writer Done!\n");
}

int main(int argc, char *argv[]) {
  int input = atoi(argv[1]);

  if (input > 12){
    printf("Warning: The maximum number of readers allowed is 12.\n Input: %d, but this program will proceed with only 12 readers and 1 writer\n", input);
    input = 12;
  }
  else if (input < 1){
    printf("Error: Number of readers cannot be less than 1 or null"); 
    return 1;
  }

  //Add 1 for writer thread.
  input++;

  sem_init(&ok_to_read, 0, 1);
  sem_init(&ok_to_write, 0, 1);

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

  for (int i = 1; i < input; i++){
    if ((rc = pthread_create(&tid[i], &attr, reader, NULL))) {
        fprintf(stderr, "ERROR: pthread_create, rc: %d\n", rc);
        exit(0);
    }
  }

  /* Wait for threads to finish */
  for (int i = 0; i < input; i++){
    pthread_join(tid[i], NULL);
  }

  /* Clean up */
  pthread_exit(NULL);

  return 0;
}

