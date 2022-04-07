#include "process.h"

// Metodo para verificar si un proceso tiene que volver a la cola de primera prioridad por ancianidad
bool verify_aging(int current_time, int init_time, struct Process * process) {
    if (((current_time - init_time) % process->aging) == 0 )
    {
        return true;
    }
    return false;
    
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
    ) {
        Process* p = malloc(sizeof(Process));
        p->pid = pid;
        p->name_process = name;
        p->priority = priority;
        p->init_time = init_time;
        p->burst = burst;
        p->wait = wait;
        p->waiting_delay = waiting_delay;
        p->aging = aging;
        return p;
    }