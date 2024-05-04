/* 
Name : WAGHA ARYAN ANIL
Class : SE AIML 
RollNO :- 53
Problem Statement: Implement the C program for CPU Scheduling Algorithms: Shortest Job First (Preemptive) 
and Round Robin with different arrival time.
*/
#include <stdio.h>

int main() {
    int i, NOP, sum = 0, count = 0, y, quant, wt = 0, tat = 0, at[10], bt[10], temp[10];
    float avg_wt, avg_tat;

    printf("Total number of processes in the system: ");
    scanf("%d", &NOP);
    y = NOP;

    for (i = 0; i < NOP; i++) {
        printf("\nEnter the Arrival and Burst time of Process[%d]\n", i + 1);
        printf("Arrival time is: ");
        scanf("%d", &at[i]);
        printf("Burst time is: ");
        scanf("%d", &bt[i]);
        temp[i] = bt[i];
    }

    printf("\nEnter the Time Quantum for the process: ");
    scanf("%d", &quant);

    printf("\nProcess No \t\t Burst Time \t\t TAT \t\t Waiting Time ");
    for (sum = 0, i = 0; y != 0;) {
        if (temp[i] <= quant && temp[i] > 0) {
            sum = sum + temp[i];
            temp[i] = 0;
            count = 1;
        } else if (temp[i] > 0) {
            temp[i] = temp[i] - quant;
            sum = sum + quant;
        }

        if (temp[i] == 0 && count == 1) {
            y--;
            printf("\nProcess No[%d] \t\t %d\t\t\t\t %d\t\t\t %d", i + 1, bt[i], sum - at[i], sum - at[i] - bt[i]);
            wt = wt + sum - at[i] - bt[i];
            tat = tat + sum - at[i];
            count = 0;
        }
        
        if (i == NOP - 1) {
            i = 0;
        } else if (at[i + 1] <= sum) {
            i++;
        } else {
            i = 0;
        }
    }
    
    // Calculate averages
    avg_wt = (float)wt / NOP;
    avg_tat = (float)tat / NOP;
    
    printf("\n\nAverage Waiting Time: %.2f", avg_wt);
    printf("\nAverage Turnaround Time: %.2f", avg_tat);

    return 0;
}
/*
error@DESKTOP-OFL03QL:~/OS code$ gcc round_robin.c -o abc
error@DESKTOP-OFL03QL:~/OS code$ ./abc
Total number of processes in the system: 5

Enter the Arrival and Burst time of Process[1]
Arrival time is: 0
Burst time is: 5

Enter the Arrival and Burst time of Process[2]
Arrival time is: 1
Burst time is: 6

Enter the Arrival and Burst time of Process[3]
Arrival time is:
2
Burst time is: 9

Enter the Arrival and Burst time of Process[4]
Arrival time is: 3
Burst time is: 4

Enter the Arrival and Burst time of Process[5]
Arrival time is: 4
Burst time is: 10

Enter the Time Quantum for the process: 4

Process No               Burst Time              TAT             Waiting Time
Process No[4]            4                               13                      9
Process No[1]            5                               21                      16
Process No[2]            6                               22                      16
Process No[3]            9                               30                      21
Process No[5]            10                              30                      20

Average Waiting Time: 16.40
Average Turnaround Time: 23.20
*/