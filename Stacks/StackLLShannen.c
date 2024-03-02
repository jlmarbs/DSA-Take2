#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int elem;
    struct node *link;
} nodeType, *STACK;

void initStack(STACK *S);
bool isEmpty(STACK S);
void push(STACK *S, int data);
void pop(STACK *S);
void display(STACK S);
int top(STACK S);

int main(){
    STACK shannen;
    initStack(&shannen);

    push(&shannen, 10);
    push(&shannen, 20);
    push(&shannen, 30);
    push(&shannen, 40);
    display(shannen);

    pop(&shannen);
    push(&shannen, 50);
    display(shannen);

    return 0;
}

void initStack(STACK *S){
    *S = NULL;
}

bool isEmpty(STACK S){
    return (S == NULL) ? true : false;
}

int top(STACK S){
    return S->elem;
}

void push(STACK *S, int data){
    STACK newNode = (STACK)malloc(sizeof(nodeType));
    if(newNode != NULL){
        newNode->elem = data;
        newNode->link = *S;
        *S = newNode;
    }
}

void pop(STACK *S){
    if(!isEmpty(*S)){
        STACK temp;

        temp = *S;
        *S = temp->link;
        free(temp);
    }
}

void display(STACK S){
    STACK tempStack;
    initStack(&tempStack);

    while(!isEmpty(S)){
        push(&tempStack, top(S));
        pop(&S);
    }

    while(!isEmpty(tempStack)){
        printf("%d ", top(tempStack));
        push(&S, top(tempStack));
        pop(&tempStack);
    }
    printf("\n");
}