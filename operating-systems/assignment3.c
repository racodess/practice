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
	// End file read

	//Start my code
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
	const char* FCFS = "FCFS";
	const char* SJF = "SJF";
	char* algo = argv[2];

	for (int i = 0; i < num_process; i++){
		p.name[i] = i + 1;
		p.arrival[i] = arrival[i];
		p.burst[i] = burst[i];
	}

	if (strcmp(FCFS, algo) == 0){

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

		
		int sumBurst = 0;
		for (int i = 0; i < num_process; i++){
			p.start[i] = sumBurst;	
			sumBurst += p.burst[i];
		}

		for (int i = 0; i < num_process; i++){
			p.waitingTime[i] = p.start[i] - p.arrival[i];
		}

		int totalWait = 0;
		float averageWait = 0.0;
		for (int i = 0; i < num_process; i++){
			totalWait += p.waitingTime[i];	
		}
		averageWait = totalWait/(float)num_process;

		for (int i = 0; i < num_process; i++){
			p.turnAroundTime[i] = p.burst[i] + p.waitingTime[i];	
		}

		int totalTurnAround = 0;
		float averageTurnAround = 0.0;
		for (int i = 0; i < num_process; i++){
			totalTurnAround += p.turnAroundTime[i];
		}
		averageTurnAround = totalTurnAround/(float)num_process;

		printf("Order of Exectution:\n");
		for (int i = 0; i < num_process; i++){
			printf("\nProcess %d: Arrival %d, Waiting %d, Start %d, Burst %d, Turnaround %d", p.name[i], p.arrival[i], p.waitingTime[i], p.start[i], p.burst[i], p.turnAroundTime[i]);
		}
		printf("\n");
		printf("\nAverage Waiting Time: %.2f\n", averageWait);
		printf("\nAverage Turnaround Time: %.2f\n", averageTurnAround);
	}
	else if (strcmp(SJF, algo) == 0){
		printf("\nSuccess for SJF!\n");
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
  
		int sumBurst = 0;
		for (int i = 0; i < num_process; i++){
			p.start[i] = sumBurst;	
			sumBurst += p.burst[i];
		}

		for (int i = 0; i < num_process; i++){
			p.waitingTime[i] = p.start[i] - p.arrival[i];
		}

		printf("\n");
		for (int i = 0; i < num_process; i++){
			printf("\nProcess %d: Arrival %d, Burst %d, Waiting %d", p.name[i], p.arrival[i], p.burst[i], p.waitingTime[i]);
		}
		printf("\n");

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
		
		printf("\n");
		for (int i = 0; i < num_process; i++){
			printf("\nProcess %d: Arrival %d, Burst %d", p.name[i], p.arrival[i], p.burst[i]);
		}
		printf("\n");

		sumBurst = 0;
		for (int i = 0; i < num_process; i++){
			p.start[i] = sumBurst;	
			sumBurst += p.burst[i];
		}

		for (int i = 0; i < num_process; i++){
			p.waitingTime[i] = p.start[i] - p.arrival[i];
		}

		int totalWait = 0;
		float averageWait = 0.0;
		for (int i = 0; i < num_process; i++){
			totalWait += p.waitingTime[i];	
		}
		averageWait = totalWait/(float)num_process;

		for (int i = 0; i < num_process; i++){
			p.turnAroundTime[i] = p.burst[i] + p.waitingTime[i];	
		}

		int totalTurnAround = 0;
		float averageTurnAround = 0.0;
		for (int i = 0; i < num_process; i++){
			totalTurnAround += p.turnAroundTime[i];
		}
		averageTurnAround = totalTurnAround/(float)num_process;

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
