#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct{
    int elem[MAX];
    int front;
    int rear;
} CQUEUE;

void initQueue(CQUEUE *CQ);
void displayQueue(CQUEUE CQ);
void enQueue(CQUEUE *CQ, int data);
void deQueue(CQUEUE *CQ, int data);

int main(){
    CQUEUE Shannen;
    initQueue(&Shannen);

    enQueue(&Shannen, 10);
    enQueue(&Shannen, 20);
    enQueue(&Shannen, 30);
    displayQueue(Shannen);

    enQueue(&Shannen, 12);
    displayQueue(Shannen);

    deQueue(&Shannen, 12);
    deQueue(&Shannen, 10);
    displayQueue(Shannen);

    return 0;
}

void initQueue(CQUEUE *CQ){
    CQ->front = 1;
    CQ->rear = 0;
}

void enQueue(CQUEUE *CQ, int data){
    if((CQ->rear + 2) % MAX != CQ->front){
        CQ->rear = (CQ->rear + 1) % MAX;
        CQ->elem[CQ->rear] = data;
    }
}

void deQueue(CQUEUE *CQ, int data){
    if((CQ->rear + 1) % MAX != CQ->front){
        CQ->front = (CQ->front + 1) % MAX;
    }
}

void displayQueue(CQUEUE CQ){
    int x;

    for(x = CQ.front; x != (CQ.rear + 1) % MAX; x = (x + 1) % MAX){
        printf("%d ", CQ.elem[x]);
    }
    printf("\n\n");
}