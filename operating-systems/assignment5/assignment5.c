/* Raul Acosta 4566606
 *
 * This program will find the number of page faults from FIFO,
 * and LRU page replacement algorithms. It reads page references
 * from a file and works with anywhere from 1 to 10 frames, determined
 * by the user from the command line. The implementation is rather 
 * simple, yet still involves many variables, including arrays, to keep 
 * track of things like frames, positions, times, etc.
 */

#include <stdio.h>
#include <stdlib.h>

//Prototypes to resolve warnings at compile time
int findMemory(int page, int memory[], int numFrames);
int findLRU(int lastAccess[], int numFrames);

int main(int argc, char *argv[]){

  //Start file read, and assign CLI arguments
  int numFrames = atoi(argv[2]); //Number of frames from user

  FILE *pageRefFile = fopen(argv[1], "r");

  int numPageRefs = 0; //Total number of page references in file
  int pageRefs[50]; //Actual page reference values from file
  while(fscanf(pageRefFile, "%d", &pageRefs[numPageRefs]) != EOF)
    numPageRefs++;

  fclose(pageRefFile);
  //End file read

  int memoryFIFO[10], memoryLRU[10]; //Frames for FIFO/LRU
  int faultsFIFO = 0, faultsLRU = 0; //Faults for FIFO/LRU

  //Initialize frames with -1 to differentiate used from unused frames
  for(int i = 0; i < 10; i++) {
    memoryFIFO[i] = -1;
    memoryLRU[i] = -1;
  }

  int nextFrameFIFO = 0; //Next frame to be replaced by FIFO
  for(int i = 0; i < numPageRefs; i++) {
    //Attempts to find each page in FIFO memory
    int inMemory = findMemory(pageRefs[i], memoryFIFO, numFrames);

    /*If page not found in FIFO memory, 
    * assign to next FIFO frame to be replaced,
    * and count another FIFO page fault. */
    if(!inMemory) {
      memoryFIFO[nextFrameFIFO] = pageRefs[i];
      nextFrameFIFO = ++nextFrameFIFO % numFrames;

      faultsFIFO++;
    }
  }

  int nextFrameLRU = 0; //Next frame to be replaced by LRU
  int lastAccess[10]; //Stores last access times for pages by LRU

  //Initialize lastAccess[] with 0 for each element
  for(int i = 0; i < 10; i++) {
    lastAccess[i] = 0;
  }

  for(int i = 0; i < numPageRefs; i++) {
    //Attempts to find each page in LRU memory
    int inMemory = findMemory(pageRefs[i], memoryLRU, numFrames);

    /*If page not found in LRU memory, add page to LRU memory
     * if not full. If LRU memory is full, find least recently used 
     * frame and replace it.
     *
     * If page is found in LRU memory, mark is as the least recently
     * used frame.
    */
    if(!inMemory) {
      if(nextFrameLRU < numFrames) {
        memoryLRU[nextFrameLRU] = pageRefs[i];
        lastAccess[nextFrameLRU] = i;
        nextFrameLRU++;
      } 
      else {
        int place = findLRU(lastAccess, numFrames);

        memoryLRU[place] = pageRefs[i];
        lastAccess[place] = i;
      }

      faultsLRU++;
    }
    else {
      for(int j = 0; j < numFrames; j++) {
        if(memoryLRU[j] == pageRefs[i]) {
          lastAccess[j] = i;
          break;
        } 
      }
    }
  }

  //Print only the elements changed from their default values
  printf("FIFO: %d page faults\n", faultsFIFO);
  printf("Final state of memory: ");
  for(int i = 0; i < numFrames; i++) {
    if(memoryFIFO[i] != -1)
      printf("%d ", memoryFIFO[i]);
  }
  printf("\n");
  printf("LRU: %d page faults\n", faultsLRU);
  printf("Final state of memory: ");
  for(int i = 0; i < numFrames; i++) {
    if(memoryLRU[i] != -1)
      printf("%d ", memoryLRU[i]);
  }
  printf("\n");

  return 0;
}

//Searches for a page in memory and returns 1 if found, else return 0
int findMemory(int page, int memory[], int numFrames){
  for(int i = 0; i < numFrames; i++){
    if(memory[i] == page)
      return 1;
  }

  return 0;
}

//Searches for the least recently used frame and returns its index
int findLRU(int lastAccess[], int numFrames) {
  int place = 0;
  int least = lastAccess[0];

  for(int i = 1; i < numFrames; i++) {
    if(lastAccess[i] < least) {
      least = lastAccess[i];
      place = i;
    }
  }

  return place;
}
