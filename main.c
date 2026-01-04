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
}