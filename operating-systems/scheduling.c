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

	// Open the file
	file = fopen(argv[1], "r");
	// Read the first line - number of processes, note the '&' operator before num_process
	fscanf(file, "%d", &num_process);
	
	// Allocate the arrays to store the arrival time and burst time, one element for each process
	arrival = (int *)malloc(num_process * sizeof(int));
	burst = (int *)malloc(num_process * sizeof(int));

	// Read each line of the file for arrival time and burst time, note that no '&' operator used here
	for (int i = 0; i < num_process; i++)
	{
			fscanf(file, "%d", arrival + i);
			fscanf(file, "%d", burst + i);
	}
	// You should close the file after reading, even though it's usually ok to forget
	fclose(file);
	
	// In this example I only print the values, in your assignment you have to compute the execution sequence
	// as well as the average waiting time and average turnaround time
	printf("There are %d processes\n", num_process);
	for (int i = 0; i < num_process; i++)
	{
			printf("Process %d arrives at %d with burst time %d\n", i + 1, arrival[i], burst[i]);
	}

	const char* FCFS = "FCFS";
	const char* SJF = "SJF";
	char* algo = argv[2];

	if (strcmp(FCFS, algo) == 0){
		printf("\nSuccess for FCFS!\n");

		bubbleSort(arrival, num_process);
	}
	else if (strcmp(SJF, algo) == 0){
		printf("\nSuccess for SJF!\n");

		bubbleSort(burst, num_process);
	}
	else {
		printf("Not working....");
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

