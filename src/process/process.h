#pragma once

struct Process
{
    int pid;
    char* name_process;
    int priority;
    int init_time;
    int cycles;
    int wait;
    int waiting_delay;
    int aging;
    char* state;
};

