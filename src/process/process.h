#pragma once
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Process;
typedef struct Process Process;

struct Process
{
    int pid;
    char* name_process;
    int priority;
    int init_time;
    int burst;
    int wait;
    int waiting_delay;
    int aging;
    char* state;
    int response_time;
    int interrupts;
    int waiting_time;
    int turnaround_time;
    int cpu_turns;
};

Process* init_process(
    int pid,
    char* name,
    int priority,
    int init_time,
    int burst,
    int wait,
    int waiting_delay,
    int aging
    );
bool verify_aging(int current_time, int init_time, struct Process * process);