#include <stdio.h>
#include "process.h"
#include "scheduler.h"

int main() {
    process_t processes[3];

    processes[0] = (process_t){1, 0, 5, 5, NEW};
    processes[1] = (process_t){2, 2, 3, 3, NEW};
    processes[2] = (process_t){3, 4, 2, 2, NEW};

    int num_processes = 3;
    // demo processes
    printf("First Come First Serve Algorithm executes processes by arrival time\n");
    fcfs(processes, num_processes);
    printf("\n");
    printf("Shortest Job First Algorithm executes processes by burst time\n");
    shortest_job_first(processes, num_processes);
    printf("\n");
    printf("Round Robin Algorithm cycles through all available processes at a given time with an alotted time until they run as long as the burst time\n");
    round_robin(processes, num_processes, 2);
}