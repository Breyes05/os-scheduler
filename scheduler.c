#include <stdio.h>
#include "scheduler.h"

// first come first serve
void fcfs(process_t processes[], int num_processes) {
    qsort(processes, num_processes, sizeof(processes[0]), comp_arrival);

    int current_time = 0;

    for (int i = 0; i < num_processes; i++) {
        process_t *p = &processes[i];
        if (p->arrival_time > current_time) {
            current_time = p->arrival_time;
        }
        p->state = RUNNING;
        printf("Time %d: Process %d running\n", current_time, p->pid);
        current_time += p->burst_time;
        p->state = FINISHED;
    }
}
// based on arrival time and queue

// shortest job first
void shortest_job_first(process_t processes[], int num_processes) {
    qsort(processes, num_processes, sizeof(processes[0]), comp_burst);

    int current_time = 0;

    for (int i = 0; i < num_processes; i++) {
        process_t *p = &processes[i];
        if (p->arrival_time > current_time) {
            current_time = p->arrival_time;
        }
        p->state = RUNNING;
        printf("Time %d: Process %d running\n", current_time, p->pid);
        current_time += p->burst_time;
        p->state = FINISHED;
    }
}

// based on burst_time

// round robin
void round_robin(process_t processes[], int num_processes, int time_quantum) {
    int finished_processes = 0;
    int current_time = 0;

    while (finished_processes < num_processes) {
        for (int i = 0; i < num_processes; i++) {
            process_t *p = &processes[i];

            if (p->remaining_time > 0 && p->arrival_time <= current_time) {
                p->state = RUNNING;
                int run_time = (p->remaining_time < time_quantum) ? p->remaining_time : time_quantum;
                printf("Time %d: Process %d running for %d units\n", current_time, p->pid, run_time);
                current_time += run_time;
                p->remaining_time -= run_time;
                if (p->remaining_time == 0) {
                    p->state = FINISHED;
                    finished_processes++;
                } else {
                    p->state = READY;
                }
            }
        }
    }
}

int comp_arrival(const void *a, const void *b) {
    const process_t *p1 = (const process_t *)a;
    const process_t *p2 = (const process_t *)b;
    int val = p1->arrival_time - p2->arrival_time;
    if (val == 0) {
        return p1->pid - p2->pid;
    } else {
        return val;
    }
    // compare arrival time, if equal use smaller pid
}

int comp_burst(const void *a, const void *b) {
    const process_t *p1 = (const process_t *)a;
    const process_t *p2 = (const process_t *)b;
    int val = p1->burst_time - p2->burst_time;
    if (val == 0) {
        return p1->pid - p2->pid;
    } else {
        return val;
    }
    // compare burst time, if equal use smaller pid
}