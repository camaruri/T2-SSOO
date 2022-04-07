#include <stdio.h>	// FILE, fopen, fclose, etc.
#include <stdlib.h> // malloc, calloc, free, etc
#include <string.h>
#include "../process/process.h"
#include "../queue/queue.h"
#include "../file_manager/manager.h"

int main(int argc, char const *argv[])
{
	/*Lectura del input*/
	char *file_name = (char *)argv[1];
	InputFile *input_file = read_file(file_name);

	/*Mostramos el archivo de input en consola*/
	printf("Nombre archivo: %s\n", file_name);
	printf("Cantidad de procesos: %d\n", input_file->len);
	printf("Procesos:\n");
	for (int i = 0; i < input_file->len; ++i)
	{
		char* name =  input_file->lines[i][0];
		int pid = atoi(input_file->lines[i][1]);
		int priority = 0;
		int init_time = atoi(input_file->lines[i][2]);
		int burst = atoi(input_file->lines[i][3]);
		int wait = atoi(input_file->lines[i][4]);
		int waiting_delay = atoi(input_file->lines[i][5]);
		int aging = atoi(input_file->lines[i][6]);
		struct Process* p = init_process(pid, name, priority, init_time, burst, wait, waiting_delay, aging);
		printf("The burst time for the id %d is: %d\n", p->pid, p->burst);
		// revisar por cada proceso si esta en el init time y si esta meter a la cola
	}
	struct Process*  p = malloc(sizeof(struct Process));
	*p = (struct Process){1,"PROCESS", 5, 5, 130, 5, 30, 80, "READY"};

	struct Process*  p2 = malloc(sizeof(struct Process));
	*p2 = (struct Process){2,"PROCESS 2", 7, 8, 150, 6, 50, 85, "READY"};

	struct Process*  p3 = malloc(sizeof(struct Process));
	*p3 = (struct Process){3,"PROCESS 3", 7, 8, 100, 6, 50, 85, "READY"};

	struct Process*  p4 = malloc(sizeof(struct Process));
	*p4 = (struct Process){4,"PROCESS 4", 7, 8, 90, 6, 50, 85, "READY"};

	struct Process*  p5 = malloc(sizeof(struct Process));
	*p5 = (struct Process){5,"PROCESS 5", 7, 8, 90, 6, 50, 85, "READY"};

	struct Process*  p6 = malloc(sizeof(struct Process));
	*p6 = (struct Process){6,"PROCESS 6", 7, 8, 150, 6, 50, 85, "READY"};
	printf("%s\n", p->state);
	//p->state = "WAITING";
//	printf("%s\n", p->state);
	input_file_destroy(input_file);

	// test of a FIFO QUEUE
	struct Queue * q_fifo = init_queue(1, 0, 1, 5);
	printf("%d\n", q_fifo->qid);
	printf("the quantum of fthe FIFO Queue is: %d\n", q_fifo->quantum);
	enqueue(q_fifo, p);
	enqueue(q_fifo, p2);
	//printf("pid of the head of the queue: %d\n", q_fifo->head->value->pid);
	//printf("pid of the tail of the queue: %d\n", q_fifo->tail->value->pid);
	struct Process* pret = dequeue(q_fifo);
	pret->state = "FINISHED";


	// test of a SFJ QUEUE
	struct Queue * q_sfj = init_queue(2, 1, 0, 0);
	order_enqueue(q_sfj, p);
	order_enqueue(q_sfj, p2);
	order_enqueue(q_sfj, p3);
	order_enqueue(q_sfj, p4);
	order_enqueue(q_sfj, p6);
	order_enqueue(q_sfj, p5);
	printf("pid of the next of head of the queue: %d\n", q_sfj->head->value->pid);
	printf("pid of the tail of the queue: %d\n", q_sfj->tail->value->pid);
}