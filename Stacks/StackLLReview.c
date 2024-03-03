//I LOVE SHANNEN
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int elem;
    struct node *link;
} *STACK;

void initStack(STACK *S);
void push(STACK *S, int data);
void pop(STACK *S);
int top(STACK S);
bool isEmpty(STACK S);
void display(STACK S);

int main(){
    STACK shannen;
    initStack(&shannen);

    push(&shannen, 10);
    push(&shannen, 20);
    push(&shannen, 30);
    push(&shannen, 40);
    display(shannen);

    pop(&shannen);
    pop(&shannen);
    pop(&shannen);
    pop(&shannen);
    pop(&shannen);
    display(shannen);

    return 0;
}

void initStack(STACK *S){
    *S = NULL;
}

void push(STACK *S, int data){
    STACK newNode = (STACK)malloc(sizeof(struct node));

    if(newNode != NULL){
        newNode->elem = data;
        newNode->link = *S;
        *S = newNode;
    }
}

void pop(STACK *S){
    STACK temp;

    if(*S != NULL){
        temp = *S;
        *S = temp->link;
        free(temp);
    } else{
        printf("Cannot Delete an Empty Stack.\n");
    }
}

int top(STACK S){
    return S->elem;
}

bool isEmpty(STACK S){
    return (S == NULL) ? 1 : 0;
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