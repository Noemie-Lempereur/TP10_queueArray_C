#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queueArray.h"

struct Queue* createEmptyQueue(){
    struct Queue* queue =malloc(sizeof(struct Queue));
    if (queue!=NULL){
        queue->size=0;
        queue->front=0;
        queue->rear=0;
    }
    return queue;
}

void enqueue(struct Queue* q, int item, bool* valid){
    if((q != NULL)&&(q->size<MAX_SIZE)){
        if (q->front == q->rear && q->size ==0){
            q->elems[q->front]=item;
            q->size=q->size+1;
            *valid = true;
            return;
        }
        q->rear=q->rear+1;
        if (q->rear==MAX_SIZE){
            q->rear=0;
        }
        q->elems[q->rear]=item;
        q->size=q->size+1;
        *valid = true;
        return;
    }
    *valid = false;
}

int head(struct Queue* q, bool* valid){
    if((q!=NULL)&&(isQueueEmpty(q)==false)){
        *valid=true;
        return q->elems[q->front];
    }
    *valid=false;
    return 0;
}

int dequeue(struct Queue* q, bool* valid){
    if((q!=NULL)&&(isQueueEmpty(q)==false)){
        int a=head(q,valid);
        if(*valid==true) {
            q->size = q->size - 1;
            q->front = q->front + 1;
            if (q->front==MAX_SIZE){
                q->front=0;
            }
            return a;
        }
    }
    *valid=false;
    return 0;
}


int queueSize(struct Queue* q){
    if(q!=NULL){
        return q->size;
    }
    return -1;
}

bool isQueueEmpty(struct Queue* q){
    if ((q==NULL)||(q->size==0)){
        return true;
    }
    return false;
}


void printQueue(struct Queue* q){
    if (q != NULL) {
        if (isQueueEmpty(q)==true){
            printf("rear -> NULL <- front\n");
        }
        else{
            printf("rear -> ");
            int b;
            int j=MAX_SIZE-1;
            for (int k=0;k<queueSize(q);k++){
                b=q->rear-k;
                if(b<0){
                    b=j;
                    j--;
                }
                printf("%d",q->elems[b]);
                if (k<queueSize(q)-1){
                    printf(" - ");
                }
            }
            printf(" <- front\n");
        }
    }
}

void deleteQueue(struct Queue* q){
    if(q!=NULL){
        q->size=0;
        free(q);
    }
}
