#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}nodeType, *STACK;

void Push(STACK *S, int data);
void Pop(STACK *S);
void InsertSorted(STACK *S, int data);
void Display(STACK S);
void InitStack(STACK *S);
bool isEmpty(STACK S);
STACK getAllNegatives(STACK S); 
void Clear(STACK *S);
void Populate(STACK *S);
int Top(STACK S);

void InitStack(STACK *S)
{
    *S = NULL;
}

void Pop(STACK *S)
{
    if(!isEmpty(*S))
    {
        STACK temp;
        temp = *S;
        *S = temp->next;
        free(temp);
    }
}

void Display(STACK S)
{
    STACK tempStack;
    InitStack(&tempStack);

    printf("\n===\nStack: ");
    while(!isEmpty(S))
    {
        Push(&tempStack, Top(S));
        printf("\nTop = %d\n", Top(S));
        Pop(&S);
    }

    printf("\nyes\n");

    while(!isEmpty(tempStack))
    {
        printf("%d ", Top(tempStack));
        Push(&S, Top(tempStack));
        Pop(&tempStack);
    }   

    printf("\ntest one\n");

    printf("\n\n");

}

int Top(STACK S)
{
    return S->data;
}

void Clear(STACK *S)
{
    while(!isEmpty(*S))
    {
        Pop(S);
    }
}

void Push(STACK *S, int data)
{
    STACK newNode = (STACK)malloc(sizeof(nodeType));
    if(newNode!=NULL)
    {
        newNode->data = data;
        newNode->next = *S;
        *S = newNode;
    }
}

STACK getAllNegatives(STACK S)
{
    STACK tempStack, stackNegative;
    InitStack(&tempStack);
    InitStack(&stackNegative);

    while(!isEmpty(S))
    {
        if(Top(S) < 0)
        {
            Push(&stackNegative, Top(S));
        }

        Push(&tempStack, Top(S));
        Pop(&S);
    }

    while(!isEmpty(tempStack))
    {
        Push(&S, Top(tempStack));
        Pop(&tempStack);
    }

    STACK returnStack;
    while(!isEmpty(stackNegative))
    {
        Push(&returnStack, Top(stackNegative));
        Pop(&stackNegative);
    }

    return returnStack;
}

bool isEmpty(STACK S)
{
    return (S==NULL) ? true : false;
}

void Populate(STACK *S)
{
    Push(S, -1);
    Push(S, -6);
    Push(S, 2);
    Push(S, 18);
    Push(S, -5);
}

int main()
{
    STACK myStack;
    InitStack(&myStack);

    Populate(&myStack);
    Display(myStack);
    return 0;
}