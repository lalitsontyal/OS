#include <stdio.h>
#include <stdlib.h>

struct Process {
    int processNumber, burstTime, remainingBurstTime, waitingTime, lastScheduledTime;
} processes[10];

int main() {
    int previousProcessIndex = -1, timeSlice, flag, count, currentTime = 0, i, numProcesses, totalWaitingTime = 0, totalTurnaroundTime = 0;

    printf("\nRound Robin Scheduling............");
    printf("\nEnter the number of processes:");
    scanf("%d", &numProcesses);

    printf("Enter the time slice:");
    scanf("%d", &timeSlice);

    printf("Enter the burst time\n");
    for (i = 0; i < numProcesses; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &processes[i].burstTime);
        processes[i].waitingTime = processes[i].lastScheduledTime = 0;
        processes[i].processNumber = i + 1;
        processes[i].remainingBurstTime = processes[i].burstTime;
    }

    printf("Scheduling....\n");

    do {
        flag = 0;
        for (i = 0; i < numProcesses; i++) {
            count = processes[i].remainingBurstTime;
            if (count > 0) {
                flag = -1;
                count = (count >= timeSlice) ? timeSlice : count;

                printf("\nProcess %d", processes[i].processNumber);
                printf(" from %d", currentTime);
                currentTime += count;
                printf(" to %d", currentTime);

                processes[i].remainingBurstTime -= count;

                if (previousProcessIndex != i) {
                    previousProcessIndex = i;
                    processes[i].waitingTime += currentTime - processes[i].lastScheduledTime - count;
                    processes[i].lastScheduledTime = currentTime;
                }
            }
        }

        if (flag == 0) {
            break;  // All processes completed their execution
        }

    } while (1);

    printf("\n\nProcess\tBurst Time\tWaiting Time\tTurnaround Time");

    for (i = 0; i < numProcesses; i++) {
        totalWaitingTime += processes[i].waitingTime;
        printf("\n%d\t\t%d\t\t%d\t\t%d", processes[i].processNumber, processes[i].burstTime, processes[i].waitingTime, processes[i].waitingTime + processes[i].burstTime);
    }

    totalTurnaroundTime = currentTime;
    printf("\n\nTotal Waiting Time: %d", totalWaitingTime);
    printf("\nAverage Waiting Time: %f", (float)totalWaitingTime / numProcesses);
    printf("\nTotal Turnaround Time: %d", totalTurnaroundTime);
    printf("\nAverage Turnaround Time: %f\n", (float)totalTurnaroundTime / numProcesses);

    return 0;
}
