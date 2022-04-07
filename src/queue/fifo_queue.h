#pragma once
#include "../process/process.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


struct Queue;
struct Node;

typedef struct Queue Queue;
typedef struct Node Node;

struct Node
{
    struct Process* value;
    Node* next;
};

struct Queue{
    Node *head;
    Node *tail;
};


Queue init_queue(Queue *q);
bool enqueue(Queue *q, struct Process value );
struct Process dequeue(Queue *q);
