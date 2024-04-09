/* Raul Acosta 4566606
 *
*  This program will find the number of page faults from FIFO,
*  and LRU page replacement algorithms.
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  int numFrames = atoi(argv[2]);

  FILE *pageRefFile = fopen(argv[1], "r");

  int numPageRefs = 0;
  int pageRefs[100];
  while (fscanf(pageRefFile, "%d", &pageRefs[numPageRefs]) != EOF)
    numPageRefs++;

  fclose(pageRefFile);
}
