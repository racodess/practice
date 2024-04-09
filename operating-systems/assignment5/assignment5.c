/* Raul Acosta 4566606
 *
*  This program will find the number of page faults from FIFO,
*  and LRU page replacement algorithms.
*/

#include <stdio.h>
#include <stdlib.h>

int findMemory(int page, int memory[], int totalFrames);

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
  for(int i = 0; i < numPageRefs; i++) {
    int inMemory = findMemory(pageRefs[i], memoryLRU, numFrames);

    if(!inMemory) {
      if(currentFrame < numFrames) {
        memoryLRU[currentFrame] = pageRefs[i];
        lastAccess[currentFrame] = i;
        currentFrame++;
      } 
      else {
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
}

int findMemory(int page, int memory[], int totalFrames){
  for(int i = 0; i < totalFrames; i++){
    if(memory[i] == page)
      return 1;
  }

  return 0;
}

