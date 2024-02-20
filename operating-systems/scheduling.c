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

int main(int argc, char *argv[]) {
	if (argc != 3)
		printf("Error: two arguments are required.\n");
	else
		printf("Argument 1: %s   Argument 2: %s", argv[1], argv[2]);

	return 0;
}

