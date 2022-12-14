#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef TP10_4_QUEUEARRAY_H
#define TP10_4_QUEUEARRAY_H

#define MAX_SIZE 30
struct Queue{
    int size;
    int front;
    int rear;
    int elems[MAX_SIZE];
};

struct Queue* createEmptyQueue();

void enqueue(struct Queue* q, int item, bool* valid);

int head(struct Queue* q, bool* valid);

int dequeue(struct Queue* q, bool* valid);

int queueSize(struct Queue* q);

bool isQueueEmpty(struct Queue* q);

void printQueue(struct Queue* q);

void deleteQueue(struct Queue* q);

#endif
