#ifndef PROCESS_H
#define PROCESS_H

typedef enum {
    NEW,
    READY,
    RUNNING,
    FINISHED
} state_t;
// state_t is the variable type
// state_t tells the scheduler what the process is doing
// Just created, ready in the queue, currently using CPU, done executing

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    state_t state;
} process_t;
// FCFS (First come first serve)
// Each process has an ID

#endif
// if not defined yet, define this way, otherwise ignore