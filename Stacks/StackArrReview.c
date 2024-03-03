#include <stdio.h>
#include <stdbool.h>
#define MAX 5

typedef struct{
    int elem[MAX];
    int top;
} STACK;

void initStack(STACK *S);
void push(STACK *S, int data);
void pop(STACK *S);
bool isFull(STACK S);
bool isEmpty(STACK S);
int top(STACK S);
void display(STACK S);

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
    pop(&shannen);
    pop(&shannen);
    pop(&shannen);
    pop(&shannen);
    pop(&shannen);
    display(shannen);

    return 0;
}

void initStack(STACK *S){
    S->top = -1;
}

void push(STACK *S, int data){
    if(S->top != MAX - 1){
        S->top++;
        S->elem[S->top] = data;
    } else{
        printf("Cannot add the element.\n");
    }
}

void pop(STACK *S){
    if(S->top != -1){
        S->top--;
    } else{
        printf("Cannot delete the element.\n");
    }
}

bool isFull(STACK S){
    return (S.top == MAX - 1) ? 1 : 0;
}

bool isEmpty(STACK S){
    return (S.top == -1) ? 1 : 0;
}

int top(STACK S){
    return S.elem[S.top];
}

void display(STACK S){
    STACK temp;
    initStack(&temp);

    while(!isEmpty(S)){
        push(&temp, top(S));
        pop(&S);
    }

    while(!isEmpty(temp)){
        printf("%d ", top(temp));
        push(&S, top(temp));
        pop(&temp);
    }
    printf("\n");
}