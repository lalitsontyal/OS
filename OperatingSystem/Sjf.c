#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int pid;
    int btime;
    int wtime;
} sp;

int main() {
    int i, j, n, tbm = 0, totwtime = 0, totttime;
    sp *p, t;

    printf("\nSJF Scheduling...\n");
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    p = (sp*)malloc(n * sizeof(sp));

    printf("\nEnter the burst time:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &p[i].btime);
        p[i].pid = i + 1;
        p[i].wtime = 0;
    }

    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
            if (p[i].btime > p[j].btime) {
                t = p[i];
                p[i] = p[j];
                p[j] = t;
            }

    printf("\nProcess Scheduling\n");
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (i = 0; i < n; i++) {
        totwtime += p[i].wtime = tbm;
        tbm += p[i].btime;
        printf("%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].btime, p[i].wtime, p[i].wtime + p[i].btime);
    }

    totttime = tbm + totwtime;
    printf("\nTotal Waiting Time: %d\n", totwtime);
    printf("Average Waiting Time: %f\n", (float)totwtime / n);
    printf("Total Turnaround Time: %d\n", totttime);
    printf("Average Turnaround Time: %f\n", (float)totttime / n);

    free(p);

    return 0;
}
