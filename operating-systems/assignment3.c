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
	//Start file read. Source: Dr. Kaoutar Ben Ahmed, supplementary materials
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
	// End file read

	/*Create structure to hold all variables related to processes
	 * Struct members are arrays, each column corresponds to one process and its properties*/
	struct process {
	int name[num_process]; 
	int arrival[num_process];
	int burst[num_process];
	int start[num_process];
	int waitingTime[num_process];
	int turnAroundTime[num_process];
	};

	typedef struct process Process;
	Process p;

	//Instantiate variables that allow for command line argument validation
	const char* FCFS = "FCFS";
	const char* SJF = "SJF";
	char* algo = argv[2];

	//Instantiate process name, arrival, burst. These are needed for bubble sorts below
	for (int i = 0; i < num_process; i++){
		p.name[i] = i + 1;
		p.arrival[i] = arrival[i];
		p.burst[i] = burst[i];
	}
	
	//FCFS
	if (strcmp(FCFS, algo) == 0){

		//Bubble sort by arrival time, and switch the whole columns
		int temp1, temp2, temp3;
			for (int i = 0; i < num_process-1; i++){
				for (int j = 0; j < num_process-i-1; j++){
					if (p.arrival[j] > p.arrival[j+1]){
						temp1 = p.name[j];
						temp2 = p.arrival[j];
						temp3 = p.burst[j];

						p.name[j] = p.name[j+1];
						p.arrival[j] = p.arrival[j+1];
						p.burst[j] = p.burst[j+1];

						p.name[j+1] = temp1;
						p.arrival[j+1] = temp2;
						p.burst[j+1] = temp3;
					}
				}
			}

		/* FCFS: Initialize struct member for start time by summing
		 * burst times up to the current indices for a column*/
		int sumBurst = 0;
		for (int i = 0; i < num_process; i++){
			p.start[i] = sumBurst;	
			sumBurst += p.burst[i];
		}

		/* FCFS: Initialize struct member for waiting time by finding difference
		 * between start time and arrival time. Checks for negative waiting time*/
		for (int i = 0; i < num_process; i++){
			if((p.start[i] - p.arrival[i]) < 0)
				p.waitingTime[i] = 0;
			else
				p.waitingTime[i] = p.start[i] - p.arrival[i];
		}

		/* FCFS: Correct for start times less than arrival time in certain cases
		 * and for cases where two processes share the same arrival and burst time*/
		for (int i = 0; i < num_process; i++){
			 if (p.waitingTime[i] == 0 && p.start[i] < p.arrival[i])
				 p.start[i] = p.arrival[i];
			 if ((p.arrival[i] == p.arrival[i+1]) && (p.burst[i] == p.burst[i+1]))
				 p.waitingTime[i+1] += p.burst[i];
		}

		// FCFS: Calculate total wait time for all processes
		int totalWait = 0;
		float averageWait = 0.0;
		for (int i = 0; i < num_process; i++){
			totalWait += p.waitingTime[i];	
		}

		// FCFS: Initialize struct member for turnaround time for each column
		for (int i = 0; i < num_process; i++){
			p.turnAroundTime[i] = p.burst[i] + p.waitingTime[i];	
		}

		// FCFS: Calculate total turnaround time for all processes
		int totalTurnAround = 0;
		float averageTurnAround = 0.0;
		for (int i = 0; i < num_process; i++){
			totalTurnAround += p.turnAroundTime[i];
		}
		
		// FCFS: Assign final values of average wait and turnaround times
		averageWait = totalWait/(float)num_process;
		averageTurnAround = totalTurnAround/(float)num_process;

		// FCFS: Print final output
		printf("Order of Exectution:\n");
		for (int i = 0; i < num_process; i++){
			printf("\nProcess %d: Arrival %d, Waiting %d, Start %d, Burst %d, Turnaround %d", p.name[i], p.arrival[i], p.waitingTime[i], p.start[i], p.burst[i], p.turnAroundTime[i]);
		}
		printf("\n");
		printf("\nAverage Waiting Time: %.2f\n", averageWait);
		printf("\nAverage Turnaround Time: %.2f\n", averageTurnAround);
	}
	//SJF
	else if (strcmp(SJF, algo) == 0){

		int temp1, temp2, temp3;

			for (int i = 0; i < num_process-1; i++){
				for (int j = 0; j < num_process-i-1; j++){
					if (p.arrival[j] > p.arrival[j+1]){
						temp1 = p.name[j];
						temp2 = p.arrival[j];
						temp3 = p.burst[j];

						p.name[j] = p.name[j+1];
						p.arrival[j] = p.arrival[j+1];
						p.burst[j] = p.burst[j+1];

						p.name[j+1] = temp1;
						p.arrival[j+1] = temp2;
						p.burst[j+1] = temp3;
					}
				}
			}

		/* SJF: Used in bubblesort below
		 * Initialize struct member for start time by summing
		 * burst times up to the current indices for a column*/
		int sumBurst = 0;
		for (int i = 0; i < num_process; i++){
			p.start[i] = sumBurst;	
			sumBurst += p.burst[i];
		}
		
		/* SJF: Used in bubblesort below
		 * Initialize struct member for waiting time by finding difference
		 * between start time and arrival time. Checks for negative waiting time*/
		for (int i = 0; i < num_process; i++){
			if((p.start[i] - p.arrival[i]) < 0)
				p.waitingTime[i] = 0;
			else
				p.waitingTime[i] = p.start[i] - p.arrival[i];
		}

		for (int i = 0; i < num_process-1; i++){
			for (int j = 1; j < num_process-i-1; j++){
				if (p.burst[j] > p.burst[j+1] && !(p.arrival[j+1] >= (p.arrival[j] + p.waitingTime[j]))){
					temp1 = p.name[j];
					temp2 = p.arrival[j];
					temp3 = p.burst[j];

					p.name[j] = p.name[j+1];
					p.arrival[j] = p.arrival[j+1];
					p.burst[j] = p.burst[j+1];

					p.name[j+1] = temp1;
					p.arrival[j+1] = temp2;
					p.burst[j+1] = temp3;
				}
				else if (p.burst[j] == p.burst[j+1] && p.arrival[j] > p.arrival[j+1]){
					temp1 = p.name[j];
					temp2 = p.arrival[j];
					temp3 = p.burst[j];

					p.name[j] = p.name[j+1];
					p.arrival[j] = p.arrival[j+1];
					p.burst[j] = p.burst[j+1];

					p.name[j+1] = temp1;
					p.arrival[j+1] = temp2;
					p.burst[j+1] = temp3;
				}
			}
	 }

		/* SJF: Initialize struct member for start time by summing
		 * burst times up to the current indices for a column*/
		sumBurst = 0;
		for (int i = 0; i < num_process; i++){
			p.start[i] = sumBurst;	
			sumBurst += p.burst[i];
		}

		/* SJF: Initialize struct member for waiting time by finding difference
		 * between start time and arrival time. Checks for negative waiting time*/
		for (int i = 0; i < num_process; i++){
			if((p.start[i] - p.arrival[i]) < 0)
				p.waitingTime[i] = 0;
			else
				p.waitingTime[i] = p.start[i] - p.arrival[i];
		}

		/* FCFS: Correct for start times less than arrival time in certain cases
		 * and for cases where two processes share the same arrival and burst time*/
		for (int i = 0; i < num_process; i++){
			 if (p.waitingTime[i] == 0 && p.start[i] < p.arrival[i])
				 p.start[i] = p.arrival[i];
			 if ((p.arrival[i] == p.arrival[i+1]) && (p.burst[i] == p.burst[i+1]))
				 p.waitingTime[i+1] += p.burst[i];
		}

		// SJF: Calculate total wait time for all processes
		int totalWait = 0;
		float averageWait = 0.0;
		for (int i = 0; i < num_process; i++){
			totalWait += p.waitingTime[i];	
		}

		// SJF: Initialize struct member for turnaround time for each column
		for (int i = 0; i < num_process; i++){
			p.turnAroundTime[i] = p.burst[i] + p.waitingTime[i];	
		}

		// SJF: Calculate total turnaround time for all processes
		int totalTurnAround = 0;
		float averageTurnAround = 0.0;
		for (int i = 0; i < num_process; i++){
			totalTurnAround += p.turnAroundTime[i];
		}

		// SJF: Assign final values of average wait and turnaround times
		averageWait = totalWait/(float)num_process;
		averageTurnAround = totalTurnAround/(float)num_process;

		// SJF: Print final output
		printf("Order of Exectution:\n");
		for (int i = 0; i < num_process; i++){
			printf("\nProcess %d: Arrival %d, Waiting %d, Start %d, Burst %d, Turnaround %d", p.name[i], p.arrival[i], p.waitingTime[i], p.start[i], p.burst[i], p.turnAroundTime[i]);
		}
		printf("\n");
		printf("\nAverage Waiting Time: %.2f\n", averageWait);
		printf("\nAverage Turnaround Time: %.2f\n", averageTurnAround);

	}

	free(arrival);
	free(burst);

	return 0;
}
