#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "process.h"

void fcfs(process_t processes[], int num_processes);

void shortest_job_first(process_t processes[], int num_processes);

void round_robin(process_t processes[], int num_processes, int time_quantum);

// fcfs comp for qsort()
int comp_arrival(const void *a, const void *b);

// sjf comp for qsort()
int comp_burst(const void *a, const void *b);

#endif