#include <stdio.h>
#include <stdbool.h>
#define MAX 5

typedef struct{
    int elem[MAX];
    int top;
} STACK;

void initStack(STACK *S);
bool isFull(STACK S);
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
    push(&shannen, 50);
    push(&shannen, 60);
    display(shannen);

    pop(&shannen);
    display(shannen);

    return 0;
}

void initStack(STACK *S){
    S->top = -1;
}

bool isFull(STACK S){
    return (S.top == MAX - 1) ? true : false; 
}

bool isEmpty(STACK S){
    return (S.top == -1) ? true : false;
}

void push(STACK *S, int data){
    if(!isFull(*S)){
        S->top++;
        S->elem[S->top] = data;
    } else{
        printf("Cannot add the element.\n");
    }
}

void pop(STACK *S){
    if(!isEmpty(*S)){
        S->top--;
    }
}

int top(STACK S){
    return S.elem[S.top];
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