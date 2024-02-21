/* Raul Acosta (ID: 4566606)
 *
 * This program implements FCFS and SJF scheduling
 * algorithms in C and calculates the average waiting
 * time and average turnaround time of concurrent processes.
 *
 * It expects a text file and scheduling algorithm (FCFS or SJF)
 * as arguments. Inputs are the number of processes, arrival time,
 * and burst time. Outputs are the order of process execution,
 * average waiting time, and average turn around time.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
	FILE *file;
	int num_process;
	int *arrival;
	int *burst;

	file = fopen(argv[1], "r");
	fscanf(file, "%d", &num_process);
	
	arrival = (int *)malloc(num_process * sizeof(int));
	burst = (int *)malloc(num_process * sizeof(int));

	for (int i = 0; i < num_process; i++)
	{
			fscanf(file, "%d", arrival + i);
			fscanf(file, "%d", burst + i);
	}

	fclose(file);
	
	printf("There are %d processes\n", num_process);
	for (int i = 0; i < num_process; i++)
	{
			printf("Process %d arrives at %d with burst time %d\n", i + 1, arrival[i], burst[i]);
	}
	// End file read

	//Start my code
	struct Process {
	int name[num_process];
	int arrival[num_process];
	int burst[num_process];
	int waitingTime[num_process];
	int turnAroundTime[num_process];
	};
	
	struct Process p;
	const char* FCFS = "FCFS";
	const char* SJF = "SJF";
	char* algo = argv[2];

	for (int i = 0; i < num_process; i++){
		p.name[i] = i + 1;
		p.arrival[i] = arrival[i];
		p.burst[i] = burst[i];
	}

	for (int i = 0; i < num_process; i++){
		printf("\nProcess %d: Arrival %d, Burst %d", p.name[i], p.arrival[i], p.burst[i]);
	}

	if (strcmp(FCFS, algo) == 0){
		printf("\nSuccess for FCFS!\n");

	}
	else if (strcmp(SJF, algo) == 0){
		printf("\nSuccess for SJF!\n");

	}
	else {
		printf("Not working....");
	}
	
	for(int i = 0; i < num_process; i++){ 
		// this shows that burst itself has changed and is sorted
		printf("%d", burst[i]);
	}

	// And remember to release the dynamically allocated memory after using
	free(arrival);
	free(burst);

	return 0;
}

void bubbleSort(int arr[], int n){ // From supplementary materials, TA recording, sort.c
	int i, j, temp;
	for (i = 0; i < n-1; i++){
		for (j = 0; j < n-i-1; j++){
			if (arr[j] > arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}


