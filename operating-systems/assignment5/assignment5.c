/* Raul Acosta 4566606
 *
*  This program will find the number of page faults from FIFO,
*  and LRU page replacement algorithms.
*/

#include <stdio.h>
#include <stdlib.h>

int findMemory(int page, int memory[], int numFrames);
int findLRU(int lastAccess[], int numFrames);

int main(int argc, char *argv[]){
  int numFrames = atoi(argv[2]);

  FILE *pageRefFile = fopen(argv[1], "r");

  int numPageRefs = 0;
  int pageRefs[50];
  while(fscanf(pageRefFile, "%d", &pageRefs[numPageRefs]) != EOF)
    numPageRefs++;

  fclose(pageRefFile);

  int memoryFIFO[10], memoryLRU[10];
  int faultsFIFO = 0, faultsLRU = 0;

  for(int i = 0; i < 10; i++) {
    memoryFIFO[i] = -1;
    memoryLRU[i] = -1;
  }

  int nextFrame = 0;
  for(int i = 0; i < numPageRefs; i++) {
    int inMemory = findMemory(pageRefs[i], memoryFIFO, numFrames);

    if(!inMemory) {
      memoryFIFO[nextFrame] = pageRefs[i];
      nextFrame = ++nextFrame % numFrames;

      faultsFIFO++;
    }
  }

  int currentFrame = 0;
  int lastAccess[10];

  for(int i = 0; i < 10; i++) {
    lastAccess[i] = 0;
  }

  for(int i = 0; i < numPageRefs; i++) {
    int inMemory = findMemory(pageRefs[i], memoryLRU, numFrames);

    if(!inMemory) {
      if(currentFrame < numFrames) {
        memoryLRU[currentFrame] = pageRefs[i];
        lastAccess[currentFrame] = i;
        currentFrame++;
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

int findMemory(int page, int memory[], int numFrames){
  for(int i = 0; i < numFrames; i++){
    if(memory[i] == page)
      return 1;
  }

  return 0;
}

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
